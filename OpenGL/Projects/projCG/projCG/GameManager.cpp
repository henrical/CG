#include <iostream>

#include "GameManager.h"

GameManager::GameManager()
{
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
