#pragma once
#include "ShaderManager.h"
#include "LightObservable.h"

#include <glm/vec3.hpp> // glm::vec3

enum lightType
{
	point, directional, spot
};

class Light : public LightObservable
{
public:
	Light(int type, glm::vec3 lightPos, glm::vec3 lightColor);
	Light(int type, glm::vec3 lightPos, glm::vec3 lightColor, glm::vec3 lightDir, float cutOff);
	//void sendToShaders(int index);
	void addLightObserver(LightObserver* obs) override;
	void removeLightObserver(LightObserver* obs) override;
	void notifyLightObservers() override;
	int getLightCount();

private:
	unsigned int id;
	int typ;
	glm::vec3 lightPos;
	glm::vec3 lightColor;
	glm::vec3 lightDir;
	float cutOff;

	std::vector<LightObserver*> lightObs;
	static unsigned int lightCount;
};

