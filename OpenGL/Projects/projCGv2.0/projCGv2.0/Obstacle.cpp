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

void Obstacle::update(double delta_t, Vector3 hit_direction){

}