#include "../Include/SkyBox.h"

void SkyBox::initializeVao()
{
	//vertex attribute Model(VAO)
	glGenVertexArrays(1, &VAO); //generate the VAO
	glBindVertexArray(VAO); //bind the VAO
	glEnableVertexAttribArray(0); //enable vertex attributes
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(decltype(points)::value_type), NULL);
}

void SkyBox::initializeVbo()
{
	//vertex buffer Model (VBO)
	glGenBuffers(1, &VBO); // generate the VBO
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(decltype(points)::value_type) * points.size(), points.data(), GL_STATIC_DRAW);
}

SkyBox::SkyBox()
{
}
// Left, right, top, bot, back, front
SkyBox::SkyBox(std::vector<std::string> paths)
{
	this->textureId = SOIL_load_OGL_cubemap(paths[0].c_str(), paths[1].c_str(), paths[2].c_str(), paths[3].c_str(), paths[4].c_str(), paths[5].c_str(), SOIL_LOAD_RGBA, SOIL_CREATE_NEW_ID, 0);
    this->shadreProgam = ShaderManager::getInstance()->getShader("skybox");
    initializeVbo();
    initializeVao();
}

void SkyBox::draw()
{
    glDepthMask(GL_FALSE);
    shadreProgam.useProgram(); 
    glBindTexture(GL_TEXTURE_CUBE_MAP, textureId);
    glStencilFunc(GL_ALWAYS, -1, 0xFF); 
    glBindVertexArray(VAO);
    // shader - modelova matice - pozice kamery
    glDrawArrays(GL_TRIANGLES, 0, points.size());
    glDepthMask(GL_TRUE);

}

const std::vector<float> SkyBox::points = {
    // positions          
    -1.0f,  1.0f, -1.0f,
    -1.0f, -1.0f, -1.0f,
     1.0f, -1.0f, -1.0f,
     1.0f, -1.0f, -1.0f,
     1.0f,  1.0f, -1.0f,
    -1.0f,  1.0f, -1.0f,

    -1.0f, -1.0f,  1.0f,
    -1.0f, -1.0f, -1.0f,
    -1.0f,  1.0f, -1.0f,
    -1.0f,  1.0f, -1.0f,
    -1.0f,  1.0f,  1.0f,
    -1.0f, -1.0f,  1.0f,

     1.0f, -1.0f, -1.0f,
     1.0f, -1.0f,  1.0f,
     1.0f,  1.0f,  1.0f,
     1.0f,  1.0f,  1.0f,
     1.0f,  1.0f, -1.0f,
     1.0f, -1.0f, -1.0f,

    -1.0f, -1.0f,  1.0f,
    -1.0f,  1.0f,  1.0f,
     1.0f,  1.0f,  1.0f,
     1.0f,  1.0f,  1.0f,
     1.0f, -1.0f,  1.0f,
    -1.0f, -1.0f,  1.0f,

    -1.0f,  1.0f, -1.0f,
     1.0f,  1.0f, -1.0f,
     1.0f,  1.0f,  1.0f,
     1.0f,  1.0f,  1.0f,
    -1.0f,  1.0f,  1.0f,
    -1.0f,  1.0f, -1.0f,

    -1.0f, -1.0f, -1.0f,
    -1.0f, -1.0f,  1.0f,
     1.0f, -1.0f, -1.0f,
     1.0f, -1.0f, -1.0f,
    -1.0f, -1.0f,  1.0f,
     1.0f, -1.0f,  1.0f
};
