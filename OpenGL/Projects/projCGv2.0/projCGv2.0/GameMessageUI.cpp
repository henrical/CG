#include <iostream>
#include "GameMessageUI.h"

GameMessageUI::GameMessageUI(GLuint text)
	:texture(text)
{
}

void GameMessageUI::setTexture(GLuint text)
{
	texture = text;
}

void GameMessageUI::draw(){
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);
	
	glBegin(GL_QUADS);

	//glNormal3f(0.0, 0.0, 1);
	glColor3f(1.0, 1.0, 1.0);

	glTexCoord2f(0, 0);
	glVertex3f(-1 * OFFSET_Y_AXIS , -1 * OFFSET_X_AXIS, 0.5);

	glTexCoord2f(0, 1);
	glVertex3f(-1 * OFFSET_Y_AXIS, OFFSET_X_AXIS, 0.5);

	glTexCoord2f(1 ,1);
	glVertex3f(OFFSET_Y_AXIS, OFFSET_X_AXIS, 0.5);

	glTexCoord2f(1, 0);
	glVertex3f(OFFSET_Y_AXIS, -1 * OFFSET_X_AXIS, 0.5);

	glEnd();

	glDisable(GL_TEXTURE_2D);
}