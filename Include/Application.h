#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>

#include "Application.h"
#include "Shader.h"
#include "Object.h"
#include "Camera.h"
#include "ShaderManager.h"
#include "Scene.h"
#include "ModelManager.h"

class Application
{
public:
	static Application* getInstance();

	void cursor_pos_callback(GLFWwindow* window, double mouseX, double mouseY);
	void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
	void button_callback(GLFWwindow* window, int button, int action, int mode);
	void window_focus_callback(GLFWwindow* window, int focused);
	void window_size_callback(GLFWwindow* window, int width, int height);
	void window_iconify_callback(GLFWwindow* window, int iconified);
	void error_callback(int error, const char* description);

	void run();

private:
	static Application* instance;
	Application();
	
	int width;
	int height;
	//std::vector<Object*> objs;
	//Object* obj;
	Camera* cam;
	//glm::vec3 lightPosition{ 0.f, 0.f, 0.f };
	float mouseX = 0.f;
	float mouseY = 0.f;
	GLuint selectedObjectIndex;

	Scene* mainScene;
	void identifyObject();
	void emplaceObject();
};

