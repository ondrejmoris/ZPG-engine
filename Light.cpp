#include "Light.h"

unsigned int Light::lightCount = 0;

Light::Light(int type, glm::vec3 lightPos, glm::vec3 lightColor)
{
	this->id = lightCount++;
	this->typ = type;
	this->lightPos = lightPos;
	this->lightColor = lightColor;
}

Light::Light(int type, glm::vec3 lightPos, glm::vec3 lightColor, glm::vec3 lightDir, float cutOff)
{
	this->id = lightCount++;
	this->typ = type;
	this->lightPos = lightPos;
	this->lightColor = lightColor;
	this->lightDir = lightDir;
	this->cutOff = cutOff;
}

void Light::addLightObserver(LightObserver* obs)
{
	this->lightObs.push_back(obs);
}

void Light::removeLightObserver(LightObserver* obs)
{
	auto iterator = std::find(this->lightObs.begin(), this->lightObs.end(), obs);

	if (iterator != this->lightObs.end()) { // observer found
		this->lightObs.erase(iterator); // remove the observer
	}
}

void Light::notifyLightObservers()
{
	for (LightObserver* observer : this->lightObs) {
		if (typ == point || typ == directional) {
			observer->update(this->id, this->typ, this->lightPos, this->lightColor, lightCount);
		}
		else {
			observer->update(this->id, this->typ, this->lightPos, this->lightColor, this->lightDir, this->cutOff, lightCount);
		}
	}
}

int Light::getLightCount()
{
	return this->lightCount;
}
