#include "../Include/ShaderManager.h"

ShaderManager* ShaderManager::instance = nullptr;

ShaderManager* ShaderManager::getInstance() {
	if (!instance) {
		instance = new ShaderManager();
	}
	return instance;
}
/*
Shader ShaderManager::createShader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath, std::string name)
{
	Shader s = Shader(vertexShaderPath, fragmentShaderPath);
	this->shaders.emplace(name, s);
	return s;
}*/

void ShaderManager::initShaders() {
	//Shader Constatn = Shader("../Cviceni1/Shader.vert", "../Cviceni1/Constant.frag");
	//Shader Lambert = Shader("../Cviceni1/Shader.vert", "../Cviceni1/Lambert.frag");
	//Shader Phong = Shader("../Cviceni1/Shader.vert", "../Cviceni1/Phong.frag");
	//Shader Blinn = Shader("../Cviceni1/Shader.vert", "../Cviceni1/Blinn.frag");
	//
	//shaders.emplace("constant", Constatn);
	//shaders.emplace("lambert", Lambert);
	//shaders.emplace("phong", Phong);
	//shaders.emplace("blinn", Blinn);

	shaders.emplace("constant", Shader("../Cviceni1/Resources/Shader.vert", "../Cviceni1/Resources/Constant.frag"));
	shaders.emplace("lambert", Shader("../Cviceni1/Resources/Shader.vert", "../Cviceni1/Resources/Lambert.frag"));
	shaders.emplace("phong", Shader("../Cviceni1/Resources/Shader.vert", "../Cviceni1/Resources/Phong.frag"));
	shaders.emplace("blinn", Shader("../Cviceni1/Resources/Shader.vert", "../Cviceni1/Resources/Blinn.frag"));
	shaders.emplace("texture", Shader("../Cviceni1/Resources/Shader.vert", "../Cviceni1/Resources/Texture.frag"));
	shaders.emplace("skybox", Shader("../Cviceni1/Resources/SkyBox.vert", "../Cviceni1/Resources/SkyBox.frag"));
}

Shader& ShaderManager::getShader(std::string shaderName)
{
	auto s = shaders.find(shaderName);
	if (s != shaders.end()) {
		return s->second;
	}
	throw std::runtime_error("Bad observer shader!");
}

ShaderManager::ShaderManager(){
	initShaders();
}
