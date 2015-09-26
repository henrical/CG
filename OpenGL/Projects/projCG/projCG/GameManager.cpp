#include <iostream>

#include "GameManager.h"
#include "LightSource.h"

GameManager* GameManager::_instance = nullptr;

GameManager::GameManager()
{

	//memset(_lightSources, 0, sizeof _lightSources);
	_gameObjects = 0 ;
}

void GameManager::addObject()
{
	_gameObjects += 1;
}

int GameManager::getObjects()
{
	return _gameObjects;
}

