#include <iostream>
#include <string>

#include "Butter.h"
#include "GL\glut.h"
#include "GameManager.h"

Butter::Butter(Vector3 *pos, float angle)
{
	_position->set(pos->getX(), pos->getY(), pos->getZ());
	this->_angle = angle;

	bbox = CollisionBox(_position->getX() - BBOX_POS_X, _position->getY() - BBOX_POS_Y, _position->getX() + BBOX_POS_X , _position->getY() + BBOX_POS_Y);
}

Butter::~Butter()
{

}

void Butter::draw()
{
	/*std::cout << this->toString();*/
	glColor3f(B_COLOR_R, B_COLOR_G, B_COLOR_B);

	glPushMatrix();

	glTranslated(_position->getX(), _position->getY(), 0.085);
	glScalef(SIDES_RATIO, 1, 1);
	
	if (_angle != 0)
		glRotatef(_angle, 0, 0, 1);

	glutSolidCube(BUTTER_SIZE);

	glPopMatrix();

	bbox.setCordinates(_position->getX() - BBOX_POS_X, _position->getY() - BBOX_POS_Y, _position->getX() + BBOX_POS_X, _position->getY() + BBOX_POS_Y);

	if (GameManager::viewCollisionBoxes() == 1)
		bbox.draw();
}