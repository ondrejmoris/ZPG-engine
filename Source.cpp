//Include GLEW
#include <GL/glew.h>
//Include GLFW 
#include <GLFW/glfw3.h>

//Include GLM  
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr

//Include the standard C++ headers  
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#include "Application.h"
#include "Shader.h"
#include "Object.h"
#include "Camera.h"
#include "ShaderManager.h"

//GLM test

int main(void)
{
	

	//glClearColor(0.f, 0.f, 0.4f, 0.f);
	
	Application::getInstance()->run();


	
}