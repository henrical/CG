#include <iostream>

#include "GL/glut.h"

#include "GameManager.h"

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


	//#####################################

	glutMainLoop();

	getchar();

	return 0;
}