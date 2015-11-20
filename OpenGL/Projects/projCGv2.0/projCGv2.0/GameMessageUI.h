#ifndef _GAME_MESSAGE_UI_H_
#define	_GAME_MESSAGE_UI_H_

#include "GL\glut.h"
#include "GameObject.h"

// Width and height of interface window.
#define UI_WIDTH 3.2f
#define UI_HEIGHT 2.0f

// Distance of UI window sides from the axes (eixos)
#define OFFSET_X_AXIS     UI_HEIGHT / 2
#define OFFSET_Y_AXIS     UI_WIDTH / 2

class GameMessageUI : public GameObject
{
	private:
		GLuint texture;
	
	public:
		GameMessageUI(GLuint);
		void draw();
		void setTexture(GLuint);
};

#endif