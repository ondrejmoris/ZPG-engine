#version 400
out vec4 frag_colour;

in vec3 TexCoords;

uniform samplerCube skybox;

void main()
{    
    frag_colour = texture(skybox, TexCoords);
}