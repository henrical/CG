#include <iostream>

#include "Obstacle.h"

Obstacle::Obstacle(){

}

Obstacle::~Obstacle(){

}

void Obstacle::draw(){

}

CollisionBox* Obstacle::getBbox(){
	return &bbox;
}