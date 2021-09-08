#pragma once

#include "Camera.h"
#include "CameraObserver.h"
#include "LightObserver.h"

#include <GL/glew.h>

#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <sstream>

class Camera; // dopredna deklarace (z duvodu krizoveho odkazu)
class Shader : public CameraObserver, public LightObserver
{
private:
	Camera* m_camera;
	GLuint vertexShaderId;
	GLuint fragmentShaderId;
	GLuint shaderProgramId;

	// TODO - parser nová tøída

	std::string parseShader(const std::string& filePath);
	void createShader(const std::string& vertexShader, const std::string& fragmentShader);
	GLuint compileShader(const std::string& shader, GLuint type);
	bool checkShaderCompileStatus(GLint id);
	void checkLinkStatus();

public:
	Shader();
	Shader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);
	void useProgram();
	void sendUniform(const GLchar* name, glm::mat4 data);
	void sendUniform(const GLchar* name, glm::vec3 data);
	//void sendUniform(const GLchar* name, Light* light);
	void sendUniform(const GLchar* name, int data);
	void sendUniform(const GLchar* name, float data);

	void update(glm::mat4 viewMatrix, glm::mat4 projectionMatrix, glm::vec3 camPos) override;

	void update(int id, int type, glm::vec3 lightPos, glm::vec3 lightColor, int lightCount) override;
	void update(int id, int type, glm::vec3 lightPos, glm::vec3 lightColor, glm::vec3 lightDir, float cutOff, int lightCount) override;
};

