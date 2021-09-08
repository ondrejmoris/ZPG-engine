#pragma once
#include <GL/glew.h>
#include <iostream>
#include <vector>
#include <soil.h>

#include "Shader.h"
#include "Texture.h"
#include "ShaderManager.h"

class SkyBox
{
private:
	GLuint textureId;
	GLuint VBO = 0;
	GLuint VAO = 0;
	Shader shadreProgam;
	static const std::vector<float> points;

	void initializeVao();
	void initializeVbo();

public:
	SkyBox();
	SkyBox(std::vector<std::string> paths);
	void draw();
};

