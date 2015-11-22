#include <iostream>
#include "GameMessageUI.h"

GameMessageUI::GameMessageUI(GLuint text)
	:texture(text)
{
	camera_id = 1;
	_position->set(0,0,0);
}

void GameMessageUI::setTexture(GLuint text)
{
	texture = text;
}

void GameMessageUI::setCameraId(int id)
{
	camera_id = id;
}

int GameMessageUI::getCameraId()
{
	return camera_id;
}

void GameMessageUI::draw(){
	glDisable(GL_LIGHTING);
	
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, this->texture);
	
	glBegin(GL_QUADS);

	double x; 
	double y;
	//glNormal3f(0.0, 0.0, 1);
	//glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();

	switch (camera_id)
	{
	case 1:
		glTexCoord2f(0, 0);
		glVertex3f(-1 * OFFSET_Y_AXIS, -1 * OFFSET_X_AXIS, 0.5);

		glTexCoord2f(0, 1);
		glVertex3f(-1 * OFFSET_Y_AXIS, OFFSET_X_AXIS, 0.5);

		glTexCoord2f(1, 1);
		glVertex3f(OFFSET_Y_AXIS, OFFSET_X_AXIS, 0.5);

		glTexCoord2f(1, 0);
		glVertex3f(OFFSET_Y_AXIS, -1 * OFFSET_X_AXIS, 0.5);
		break;
	case 2:
		glTexCoord2f(0, 0);
		glVertex3f(-1,-0.5, 1);

		glTexCoord2f(0, 1);
		glVertex3f(-1 , 0.2, 2);

		glTexCoord2f(1, 1);
		glVertex3f(1, 0.2, 2);

		glTexCoord2f(1, 0);
		glVertex3f(1, -0.5, 1);
		break;
	case 3:
		x = _position->getX();
		y = _position->getY();

		glTexCoord2f(0, 0);
		glVertex3f(x - 0.4 , y, 0.1);

		glTexCoord2f(0, 1);
		glVertex3f(x- 0.4, y + 0.3, 0.5);

		glTexCoord2f(1, 1);
		glVertex3f(x + 0.4, y + 0.3, 0.5);

		glTexCoord2f(1, 0);
		glVertex3f(x + 0.4, y, 0.1);
		
		break;
	}

	glEnd();

	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
	glEnable(GL_LIGHTING);
}