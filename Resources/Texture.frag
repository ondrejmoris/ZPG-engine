#version 400

out vec4 frag_colour;

uniform sampler2D textureUnitID;

in vec2 uv;

void main () {
     //frag_colour = vec4(uv,1.0,1.0); //test na funkcnost uv sou�adnic
     frag_colour = texture(textureUnitID, uv);
     //frag_colour = vec4(1.0, 1.0, 1.0, 1.0);
}