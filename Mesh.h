#pragma once
#include <vector>
#include <iostream>

#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec2.hpp>
#include <GL/glew.h>

#include "Texture.h"

struct Vertex {
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec2 TexCoords;
};

class Mesh
{
public:
    std::vector<Vertex> vertices;
    std::vector<GLuint> indices;
    Texture texture;

    Mesh(std::vector<Vertex> vertices, std::vector<GLuint> indices, Texture texture);
    void draw(unsigned int id, Shader& shader);
private:
    GLuint VAO, VBO, EBO;

    void setupMesh();
};

