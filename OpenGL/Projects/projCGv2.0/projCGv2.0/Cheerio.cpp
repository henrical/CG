#include <iostream>
#include <string>

#include "Cheerio.h"
#include "GL\glut.h"
#include "GameManager.h"

Cheerio::Cheerio(Vector3 *pos)
{
	_position->set(pos->getX(), pos->getY(), pos->getZ());

	has_collision = false;
	game_has_started = false;

	bbox = CollisionBox(_position->getX(), _position->getY(), _position->getX() + CHEERIO_BBOX_LENGTH, _position->getY() + CHEERIO_BBOX_LENGTH);
}

Cheerio::~Cheerio()
{

}

void Cheerio::draw()
{
	/*if (game_has_started)
	{
		if (!this->has_collision){
			return;
		}
			
	}*/

	//std::cout << "---> Drawing CHEERIO;" << std::endl;

	glColor3d(C_COLOR_R, C_COLOR_G, C_COLOR_B);

	glPushMatrix();
	glTranslatef(_position->getX(), _position->getY(), _position->getZ());
	glutSolidTorus(TORUS_INNER_RADIUS, TORUS_OUTER_RADIUS, 50, 50);
	glPopMatrix();

	game_has_started = true;
	has_collision = false;

	if (GameManager::viewCollisionBoxes() == 1)
		bbox.draw();
}