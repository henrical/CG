#include <iostream>
#include <cstdio>
#include <string>

#include "GL/glut.h"
#include "generic.h"

#include "main.h"
#include "GameManager.h"
#include "LightSource.h"
#include "Vector3.h"
#include "Entity.h"
#include "GameObject.h"
#include "DynamicObject.h"
#include "Car.h"


void myDisplay(){
	GameManager::instance()->display();
}

void myReshape(int w, int h){
	GameManager::instance()->reshape(w, h);
}

void myKeyPress(unsigned char key, int x, int y){
	GameManager::instance()->keyPressed(key);
	//GameManager::instance()->display(); //tirar este display quando o ciclo estiver a funcionar
}

void mySpecialPress(int key, int x, int y){
	GameManager::instance()->specialPress(key);
}

void myUpdate(int x){
	GameManager::instance()->update();
	glutTimerFunc(30, myUpdate, 0);
}

void mySpecialUp(int key, int x, int y){
	GameManager::instance()->specialUp(key);
}

int main(int argc, char** argv)
{
	int window;

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE );

	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);

	glutInitWindowPosition(WINDOW_POS_X, WINDOW_POS_Y);

	window = glutCreateWindow("MicroMachines alpha v0.1");

	glutDisplayFunc(myDisplay);
	glutReshapeFunc(myReshape);
	glutKeyboardFunc(myKeyPress);
	glutSpecialFunc(mySpecialPress);
	glutSpecialUpFunc(mySpecialUp);
	glutIgnoreKeyRepeat(true);
	
	glutTimerFunc(30, myUpdate, 0);

	GameManager::instance()->init();


	glutMainLoop();

	return 0;
}