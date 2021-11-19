#include "../Include/Texture.h"

Texture::Texture()
{
}

Texture::Texture(const std::string& path)
{
	this->textureId = SOIL_load_OGL_texture(path.c_str(), SOIL_LOAD_RGBA, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
}

void Texture::bind(Shader& shader) {
    glActiveTexture(GL_TEXTURE0);
    
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
    glBindTexture(GL_TEXTURE_2D, textureId);
    shader.sendUniform("textureUnitID", 0);
}
