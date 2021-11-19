#include "../Include/ModelManager.h"

ModelManager* ModelManager::instance = nullptr;

ModelManager* ModelManager::getInstance() {
	if (!instance) {
		instance = new ModelManager();
	}
	return instance;
}

void ModelManager::initModels() {
	//this->models.emplace("sphere", Model(std::vector<float>(std::begin(sphere), std::end(sphere))));
	//this->models.emplace("plain", Model(std::vector<float>(std::begin(plain), std::end(plain))));
	//this->models.emplace("suziSmooth", Model(std::vector<float>(std::begin(suziSmooth), std::end(suziSmooth))));
	//this->models.emplace("suziFlat", Model(std::vector<float>(std::begin(suziFlat), std::end(suziFlat))));
	this->models.emplace("test", Model("../Cviceni1/Models/test.obj"));
	//this->models.emplace("city", Model("../Cviceni1/Models/Center_city/Center_City_Sci-Fi.obj"));
	this->models.emplace("grass", Model("../Cviceni1/Models/grass/grass.obj"));
	//this->models.emplace("tower", Model("../Cviceni1/Models/tower/wooden watch tower2.obj"));
	//this->models.emplace("drone", Model("../Cviceni1/Models/Drone_Costum/Material/drone_costum.obj"));
	//this->models.emplace("bookAndTable", Model("../Cviceni1/Models/bookAndTable.obj"));
	this->models.emplace("zidle", Model("../Cviceni1/Models/Zidle/zidle.obj"));
	this->models.emplace("test1", Model("../Cviceni1/Models/test1.obj"));
	this->models.emplace("zidle_baked", Model("../Cviceni1/Models/zidle_baked/zidle_cista_baked.obj"));
	this->models.emplace("table_baked", Model("../Cviceni1/Models/table_bake/table_baked.obj"));
	this->models.emplace("book", Model("../Cviceni1/Models/Book/book.obj"));
	this->models.emplace("altan", Model("../Cviceni1/Models/Altan/untitled.obj"));
	this->models.emplace("plain", Model("../Cviceni1/Models/Plain/plainGrass.obj"));
	this->models.emplace("fullScene", Model("../Cviceni1/Models/Scena/sceneBake.obj"));
	//this->models.emplace("bookATable", Model("../Cviceni1/Models/BookATable/bookAtable.obj"));
}

Model& ModelManager::getModel(std::string name)
{
	auto s = this->models.find(name);
	if (s != models.end()) {
		return s->second;
	}
	throw std::runtime_error("Bad observer model!");
}

ModelManager::ModelManager() {
	initModels();
}
