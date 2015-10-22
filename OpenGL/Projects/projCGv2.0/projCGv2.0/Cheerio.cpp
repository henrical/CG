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

	if (GameManager::viewCollisionBoxes() == 1)
		bbox.draw();
}

void Cheerio::update(int delta_t, Vector3 hit_direction){
	
	std::cout << "MOVING CHEERIO!" << std::endl;

	direction->set(hit_direction.getX(), hit_direction.getY(), hit_direction.getZ());
	
	if (hasCollisionp())
	{
		//setAcc(CHEERIO_ACCELERATION, CHEERIO_ACCELERATION, 0); //aumenta acc sempre na mesma direcção, TODO
		//setSpeed(_speed->getX() + getAcc()->getX() * delta_t, _speed->getY() + getAcc()->getY() * delta_t, 0);
		this->_position->set(_position->getX() - 2 * delta_t * direction->getX(), _position->getY() - 2 * delta_t * direction->getY(), _position->getZ());
	}
	else {
		setAcc(0, 0, 0);
		direction->set(0, 0, 0);
	}

	hasCollision = false;

}