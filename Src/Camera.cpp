#include "../Include/Camera.h"

Camera::Camera(glm::vec3 eye, glm::vec3 target, glm::vec3 up)
{
    this->eye = eye;
    this->target = target;
    this->up = up;

    setAngles();
    //this->camera = glm::lookAt(eye, target, up);

    notifyCameraObservers();
}

void Camera::updateAngle(float dtx, float dty)
{
    if (this->mouseMoveEnable == false) return;

    float radX = dtx / 180.f * M_PI;
    float radY = dty / 180.f * M_PI;

    this->fi += radX * this->rotateSpeed;
    this->psi += radY * this->rotateSpeed;

    setAngles();

    notifyCameraObservers();
}

void Camera::setAngles()
{
    if (this->fi < 0) {
        this->fi += 360.f;
    }
    this->fi = std::fmod(this->fi, 360.f);

    this->psi = std::max(this->psi, -90.f);
    this->psi = std::min(this->psi, 90.f);

    this->target.x = std::cos(this->fi);
    this->target.y = std::sin(this->psi);
    this->target.z = std::sin(this->fi);
}

void Camera::setMouseMoveState(bool state)
{
    this->mouseMoveEnable = state;
}

void Camera::setFrontMoveState(int state)
{
    this->frontMove = state;
}

void Camera::setSideMoveState(int state)
{
    this->sideMove = state;
}

void Camera::setMousePos(int mouseX, int mouseY)
{
    float dtx = (mouseX - pos_x);
    float dty = (mouseY - pos_y);

    this->pos_x = mouseX;
    this->pos_y = mouseY;

    updateAngle(dtx, dty);
}

void Camera::toFront()
{
    if (this->frontMove != 1) return;
    this->eye += (glm::normalize(this->target)) * this->moveSpeed;
}

void Camera::toBack()
{
    if (this->frontMove != -1) return;
    this->eye -= (glm::normalize(this->target)) * this->moveSpeed;
}

void Camera::toRight()
{
    if (this->sideMove != -1) return;
    this->eye += (glm::normalize(glm::cross(target, up))) * this->moveSpeed;
}

void Camera::toLeft()
{
    if (this->sideMove != 1) return;
    this->eye -= (glm::normalize(glm::cross(target, up))) * this->moveSpeed;
}

void Camera::update()
{
    toFront();
    toBack();
    toLeft();
    toRight();

    notifyCameraObservers();
}
glm::mat4 Camera::getProjectionMatrix()
{
    return this->projectionMatrix;
}

void Camera::addCameraObserver(CameraObserver* obs)
{
	this->cameraObs.push_back(obs);
}

void Camera::removeCameraObserver(CameraObserver* obs)
{
    auto iterator = std::find(this->cameraObs.begin(), this->cameraObs.end(), obs);

    if (iterator != this->cameraObs.end()) { // observer found
        this->cameraObs.erase(iterator); // remove the observer
    }
}

void Camera::notifyCameraObservers()
{
    for (CameraObserver* observer : this->cameraObs) {
        observer->update(this->getCamera(), this->projectionMatrix, this->eye);
    }
}

glm::mat4 Camera::getCamera() {
    //return glm::lookAt(eye, eye + glm::vec3{ std::cos(1.5f * M_PI), 0.f, std::sin(1.5f * M_PI) }, up);
    return glm::lookAt(eye, eye + target, up);
    //return glm::lookAt(glm::vec3(0.f, 0.f, 4.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 1.0f, 0.0f));
}    


