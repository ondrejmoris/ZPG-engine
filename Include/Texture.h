#pragma once
#include <soil.h>

#include <iostream> 
#include <GL/glew.h>
#include "Shader.h"

class Texture
{
public:
	Texture();
	Texture(const std::string& path);
	void bind(Shader& shader);
private:
	GLuint textureId;
};

