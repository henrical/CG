#include <iostream>
#include <cstdio>
#include <string>

#include "GL/glut.h"
#include "generic.h"

#include "GameManager.h"
#include "LightSource.h"
#include "Vector3.h"
#include "Entity.h"
#include "GameObject.h"
#include "DynamicObject.h"
#include "Car.h"

int main(int argc, char** argv)
{
	int window;

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);

	glutInitWindowSize(800, 700);

	glutInitWindowPosition(0, 0);

	window = glutCreateWindow("Main");

	glutDisplayFunc(GameManager::display);
	glutReshapeFunc(GameManager::reshape);

	//#####################################

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

	//#####################################

	glutMainLoop();

	getchar();

	return 0;
}