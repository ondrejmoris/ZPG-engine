#include "Camera.h"
#include "Shader.h"

constexpr bool debugShader = false;

std::string Shader::parseShader(const std::string& filePath) 
{
	std::ifstream stream(filePath);
	std::stringstream ss;

	while (stream)
	{
		std::string line;
		std::getline(stream, line);
		ss << line << "\n";
	}

	return ss.str();
}

bool Shader::checkShaderCompileStatus(GLint id) 
{
	GLint status;

	glGetShaderiv(id, GL_COMPILE_STATUS, &status);
	if (status == GL_FALSE) {
		GLint length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		GLchar* message = new GLchar[length + 1];
		glGetShaderInfoLog(id, length, &length, message);
		std::cout << message << std::endl;
		return false;
	}
	return true;
}

void Shader::checkLinkStatus() {
	GLint status;
	glGetProgramiv(this->shaderProgramId, GL_LINK_STATUS, &status);
	if (status == GL_FALSE)
	{
		GLint infoLogLength;
		glGetProgramiv(this->shaderProgramId, GL_INFO_LOG_LENGTH, &infoLogLength);
		GLchar* strInfoLog = new GLchar[infoLogLength + 1];
		glGetProgramInfoLog(this->shaderProgramId, infoLogLength, NULL, strInfoLog);
		fprintf(stderr, "Linker failure: %s\n", strInfoLog);
		delete[] strInfoLog;
	}
}

GLuint Shader::compileShader(const std::string& shader, GLuint type) 
{
	GLuint id = glCreateShader(type);
	const char* src = shader.c_str();
	glShaderSource(id, 1, &src, NULL);
	glCompileShader(id);

	if (checkShaderCompileStatus(id) == false){
		glDeleteShader(id);
		return 0;
	}

	return id;
}

void Shader::createShader(const std::string& vertexShader, const std::string& fragmentShader) 
{
	this->shaderProgramId = glCreateProgram();
	this->vertexShaderId = compileShader(vertexShader, GL_VERTEX_SHADER);
	this->fragmentShaderId = compileShader(fragmentShader, GL_FRAGMENT_SHADER);

	glAttachShader(this->shaderProgramId, this->fragmentShaderId);
	glAttachShader(this->shaderProgramId, this->vertexShaderId);
	glLinkProgram(this->shaderProgramId);

	checkLinkStatus();
}

Shader::Shader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath) {
	createShader(parseShader(vertexShaderPath), parseShader(fragmentShaderPath));
}

void Shader::useProgram() {
	glUseProgram(this->shaderProgramId);
}

void Shader::sendUniform(const GLchar* name, glm::mat4 data) {
	GLint uniformID = glGetUniformLocation(this->shaderProgramId, name);
	if (uniformID >= 0) {
		glUniformMatrix4fv(uniformID, 1, GL_FALSE, glm::value_ptr(data));
	}
	else {
		if constexpr (debugShader) {
			printf("In shader doesnt exist uniform variable %s!", name);
			//getchar();
		}	
	}
}

void Shader::sendUniform(const GLchar* name, glm::vec3 data)
{
	//useProgram();
	//std::cout << name << std::endl;
	GLint myLoc = glGetUniformLocation(this->shaderProgramId, name);
	if (myLoc >= 0) {
		glProgramUniform3f(this->shaderProgramId, myLoc, data.x, data.y, data.z); // aktualizace dat
	}
	else {
		if constexpr (debugShader) {
			printf("In shader doesnt exist uniform variable %s!", name);
			//getchar();
		}
	}
}

void Shader::sendUniform(const GLchar* name, int data)
{
	//useProgram();
	GLint myLoc = glGetUniformLocation(this->shaderProgramId, name);
	if (myLoc >= 0) {
		glProgramUniform1i(this->shaderProgramId, myLoc, data); // aktualizace dat
	}
	else {
		if constexpr (debugShader) {
			printf("In shader doesnt exist uniform variable %s!", name);
			//getchar();
		}
	}
}

void Shader::sendUniform(const GLchar* name, float data)
{
	//useProgram();
	GLint myLoc = glGetUniformLocation(this->shaderProgramId, name);
	if (myLoc >= 0) {
		glProgramUniform1f(this->shaderProgramId, myLoc, data); // aktualizace dat
	}
	else {
		if constexpr (debugShader) {
			printf("In shader doesnt exist uniform variable %s!", name);
			//getchar();
		}
	}
}


void Shader::update(glm::mat4 viewMatrix, glm::mat4 projectionMatrix, glm::vec3 camPos) {
	useProgram();
	//sendUniform("viewMatrix", glm::mat4(1.f, 0.f, 0.f, 0.f, 0.f ,1.f, 0.f,0.f, 0.f, 0.f, 1.f, 0.f, 0.f, 0.f, 0.f, 1.f));
	//sendUniform("projectionMatrix", glm::mat4(1.f, 0.f, 0.f, 0.f, 0.f, 1.f, 0.f, 0.f, 0.f, 0.f, 1.f, 0.f, 0.f, 0.f, 0.f, 1.f));
	sendUniform("projectionMatrix", projectionMatrix);
	//sendUniform("viewMatrix", glm::mat4(glm::mat3(viewMatrix)));
	sendUniform("viewMatrix", viewMatrix);
	sendUniform("cameraPos", camPos);
	//sendUniform("lightPosition", glm::vec3(0.f, 0.f, 0.f));
}

void Shader::update(int id, int type, glm::vec3 lightPos, glm::vec3 lightColor, int lightCount)
{
	useProgram();
	sendUniform(("lights[" + std::to_string(id) + "].type").c_str(), type);
	sendUniform(("lights[" + std::to_string(id) + "].position").c_str(), lightPos);
	sendUniform(("lights[" + std::to_string(id) + "].barva").c_str(), lightColor);
	//sendUniform("lights[0].color", (1.f));
	sendUniform("lightsCount", lightCount);
}

void Shader::update(int id, int type, glm::vec3 lightPos, glm::vec3 lightColor, glm::vec3 lightDir, float cutOff, int lightCount)
{
	useProgram();
	sendUniform(("lights[" + std::to_string(id) + "].type").c_str(), type);
	sendUniform(("lights[" + std::to_string(id) + "].position").c_str(), lightPos);
	sendUniform(("lights[" + std::to_string(id) + "].color").c_str(), lightColor);
	sendUniform(("lights[" + std::to_string(id) + "].lightDir").c_str(), lightDir);
	sendUniform(("lights[" + std::to_string(id) + "].cutOff").c_str(), cutOff);
	sendUniform("lightsCount", lightCount);
}

Shader::Shader(){}