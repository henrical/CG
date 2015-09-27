#include <iostream>
#include <cstdio>
#include <string>

#include "GL/glut.h"

#include "GameManager.h"
#include "LightSource.h"
#include "Vector3.h"
#include "Entity.h"
#include "GameObject.h"

int main(int argc, char** argv)
{
	int window;

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);

	glutInitWindowSize(600, 600);

	glutInitWindowPosition(0, 0);

	window = glutCreateWindow("Main");

	glutDisplayFunc(GameManager::display);
	glutReshapeFunc(GameManager::reshape);

	//#####################################

	GameManager::instance();
	LightSource *light = new LightSource(3);
	Vector3 *vector = new Vector3(1, 2, 3);
	Entity *entity = new Entity();
	GameObject *obj = new GameObject();


	obj->setPosition(3,4,5);
	std::cout << obj->toString();
	obj->setPosition(*vector);
	std::cout << obj->toString();



	//#####################################

	glutMainLoop();

	getchar();

	return 0;
}