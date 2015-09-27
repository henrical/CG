#include <iostream>
#include <cstdio>
#include <string>

#include "GL/glut.h"

#include "GameManager.h"
#include "LightSource.h"
#include "Vector3.h"
#include "Entity.h"

int main(int argc, char** argv)
{
	int window;

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);

	glutInitWindowSize(600, 600);

	glutInitWindowPosition(0, 0);

	window = glutCreateWindow("Teste");

	glutDisplayFunc(GameManager::display);
	glutReshapeFunc(GameManager::reshape);

	//#####################################

	GameManager::instance();
	LightSource *light = new LightSource(3);
	Vector3 *vector = new Vector3(1, 2, 3);
	Entity *entity = new Entity();
	
	/*entity->setPosition(3,4,5);
	std::cout << entity->toString();
	entity->setPosition(*vector);
	std::cout << entity->toString();*/



	//#####################################

	glutMainLoop();

	getchar();

	return 0;
}