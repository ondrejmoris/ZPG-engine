#pragma once
#include <unordered_map>
#include <string>
#include <iostream>

#include "Model.h"
#include "../Cviceni1/suzi_smooth.h"
#include "../Cviceni1/suzi_flat.h"
#include "../Cviceni1/sphere.h"
#include "../Cviceni1/plain.h"

class ModelManager
{
public:
	static ModelManager* getInstance();
	Model& getModel(std::string name);
private:
	std::unordered_map<std::string, Model> models;

	static ModelManager* instance;
	void initModels();
	ModelManager();
};

