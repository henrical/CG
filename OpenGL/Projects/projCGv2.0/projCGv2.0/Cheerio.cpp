#include <iostream>
#include <string>

#include "Cheerio.h"
#include "GL\glut.h"
#include "GameManager.h"

Cheerio::Cheerio(Vector3 *pos)
{
	_position->set(pos->getX(), pos->getY(), pos->getZ());

	hasCollision = false;

	bbox = CollisionBox(_position->getX() - CHEERIO_BBOX_LENGTH, _position->getY() - CHEERIO_BBOX_LENGTH, _position->getX() + CHEERIO_BBOX_LENGTH, _position->getY() + CHEERIO_BBOX_LENGTH);

	justCollided = false;
}

Cheerio::~Cheerio()
{

}

void Cheerio::draw()
{

	//std::cout << "---> Drawing CHEERIO;" << std::endl;

	glColor3d(C_COLOR_R, C_COLOR_G, C_COLOR_B);

	glPushMatrix();
	glTranslatef(_position->getX(), _position->getY(), _position->getZ());
	glutSolidTorus(TORUS_INNER_RADIUS, TORUS_OUTER_RADIUS, 50, 50);
	glPopMatrix();

	bbox.setCordinates(_position->getX() - CHEERIO_BBOX_LENGTH, _position->getY() - CHEERIO_BBOX_LENGTH, _position->getX() + CHEERIO_BBOX_LENGTH, _position->getY() + CHEERIO_BBOX_LENGTH);

	if (GameManager::viewCollisionBoxes() == 1)
		bbox.draw();
}

void Cheerio::update(int delta_t, Vector3 &hit_direction, Vector3 &hit_speed){
	
	std::cout << "MOVING CHEERIO!" << std::endl;
	
	if (hasCollisionp())
	{
		if (hit_speed.getX() != 0 || hit_speed.getY() != 0)
			this->_position->set(_position->getX() + delta_t * hit_direction.getX() * hit_speed.getX(), _position->getY() + delta_t * hit_direction.getY() * hit_speed.getY(), 0);
		else
			this->_position->set(_position->getX() + delta_t * hit_direction.getX() * 0.0005, _position->getY() + delta_t * hit_direction.getY() * 0.0005, 0);
	}

	hasCollision = false;

}