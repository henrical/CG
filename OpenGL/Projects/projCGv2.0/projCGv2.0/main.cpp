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
	GameManager::instance()->display(); //tirar este display quando o ciclo estiver a funcionar
}



int main(int argc, char** argv)
{
	int window;

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE );

	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);

	glutInitWindowPosition(WINDOW_POS_X, WINDOW_POS_Y);

	window = glutCreateWindow("MicroMachine alpha 0.001");

	glutDisplayFunc(myDisplay);
	glutReshapeFunc(myReshape);
	glutKeyboardFunc(myKeyPress);
	//#####################################
	/*
	GameManager::instance();
	LightSource *light = new LightSource(3);
	Vector3 *vector = new Vector3(1, 2, 3);
	Entity *entity = new Entity();
	DynamicObject *obj = new Car();


	obj->setPosition(3,4,5);
	std::cout << obj->toString();
	obj->setPosition(*vector);
	std::cout << obj->toString();

	std::cout << changeScale(212) << std::endl;
	*/
	//#####################################

	glutMainLoop();

	return 0;
}