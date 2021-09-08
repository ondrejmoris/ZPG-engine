#pragma once
#define _USE_MATH_DEFINES

#include "Shader.h"
#include "CameraObservable.h"

#include <glm/gtc/matrix_transform.hpp>

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


class Shader; // dopredna deklarace (z duvodu krizoveho odkazu)
class Camera : public CameraObservable
{
private:
	glm::vec3 eye;
	glm::vec3 target;
	glm::vec3 up;

	glm::mat4 projectionMatrix = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 200.0f);

	float fi = 1.5f * 3.14;
	float psi = 0.f;

	float pos_x = 0.f;
	float pos_y = 0.f;

	float rotateSpeed = 0.2f;
	float moveSpeed = 0.2f;

	bool mouseMoveEnable = false;
	int frontMove = 0;
	int sideMove = 0;

	std::vector<CameraObserver*> cameraObs;

public:
	Camera(glm::vec3 eye, glm::vec3 target, glm::vec3 up);

	void updateAngle(float dtx, float dty);
	void setAngles();
	void setMouseMoveState(bool state);
	void setFrontMoveState(int state);
	void setSideMoveState(int state);
	void setMousePos(int mouseX, int mouseY);
	void toFront();
	void toBack();
	void toRight();
	void toLeft();
	void update();
	glm::mat4 getProjectionMatrix();
	glm::mat4 getCamera();
	//float getMousePosX();
	//float getMousePosY();

	void addCameraObserver(CameraObserver* obs) override;
	void removeCameraObserver(CameraObserver* obs) override;
	void notifyCameraObservers() override;
};

