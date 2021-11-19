#pragma once
#include "Shader.h"

#include <unordered_map>
#include <string>
#include <iostream>

class ShaderManager
{
public:
	static ShaderManager* getInstance();

	//Shader addShader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath, std::string name);
	Shader& getShader(std::string shaderName);
private:
	std::unordered_map <std::string, Shader> shaders;

	void initShaders();

	static ShaderManager* instance;
	ShaderManager();
};

