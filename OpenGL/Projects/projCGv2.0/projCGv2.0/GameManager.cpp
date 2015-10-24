#include <iostream>
#include <iomanip>

#include "GameManager.h"
#include "LightSource.h"
#include "Roadside.h"
#include "generic.h"
#include "Orange.h"
#include "Butter.h"
#include "Table.h"
#include "Cheerio.h"
#include "CollisionBox.h"

GameManager* GameManager::_instance = nullptr;

GameManager::GameManager()
{
	currtime = 0;
	prevtime = 0;
	numGameObjects = 0;
	numObstaculos = 0;
	numButters = 0;
	numOranges;

	camera = 1;
	wireframe = false;
	seta_baixo = seta_cima = seta_direita = seta_esquerda = false;
}

void GameManager::addObject(GameObject *obj)
{
	_gameObjects[numGameObjects] = obj;
	numGameObjects += 1;
}

void GameManager::addObstacle(Cheerio *obs){
	obstacles[numObstaculos] = obs;
	numObstaculos += 1;
}

void GameManager::addButter(Butter *obs){
	butters[numButters] = obs;
	numButters += 1;
}

GameObject* GameManager::getObject(int object_index)
{	
	return _gameObjects[object_index];
}

// Pass color as parameter
// i.e. LIGHT_BLUE, WHITE, LIGHT_GREY
/*void GameManager::drawTable(const float color[]){
	glColor3f(color[0], color[1], color[2]);
	glScalef(1.5, 1.5, 1.5);
	glPushMatrix();
	glTranslatef(0.0, 0.0, -1.5);
	glutSolidCube(3);
	glPopMatrix();
}*/

int GameManager::init(){

	addObject(new Roadside());
	addObject(new Car());
	addObject(new Table());

	Roadside *road = (Roadside*)getObject(ROADSIDE);
	road->draw();

	addButter(new Butter(&Vector3(1.25, 0.3, 0), 0));
	addButter(new Butter(&Vector3(-0.79, 0.85, 0), 0));
	addButter(new Butter(&Vector3(0, -1.2, 0), 0));
	addButter(new Butter(&Vector3(1, 1.2, 0), 0));
	addButter(new Butter(&Vector3(-1.2, -1, 0), 0));

	/*addObstacle(new Orange(&Vector3(0, 1.25, 0)));
	addObstacle(new Orange(&Vector3(-0.9, -0.5, 0)));
	addObstacle(new Orange(&Vector3(0.9, -0.9, 0)));*/
	
	

	std::cout << "Number of obstacles:" << numObstaculos << std::endl;
	std::cout << "Number of game objects:" << numGameObjects << std::endl;

	return 0;
}

int GameManager::drawGameObjects(){
	int i;
	
	

	//draw game objects
	for (i = 1; i < numGameObjects; i++){
		_gameObjects[i]->draw();
		//std::cout << "### Drawing game object " << i << ";" << std::endl;
	}
	

	//desenhar cheerios
	for (i = 0; i < numObstaculos; i++){
		obstacles[i]->draw();
		//std::cout << "=== Drawing obstacle " << i << ";" << std::endl;
	}

	//desenhar manteigas
	for (i = 0; i < numButters; i++){
		butters[i]->draw();
		//std::cout << "=== Drawing obstacle " << i << ";" << std::endl;
	}
	

	return 0;

}

void GameManager::display(){
	//std::cout << "---> Display." << std::endl;

	glClearDepth(1.0);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);


	//		##########	camaras	################
	if (camera == 1){
		glViewport(0, 0, 800, 700);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		float rac = (float)800 / 700;
		if (rac > 1)
			glOrtho(rac*-3.0f, rac*3.0f, -3.0f, 3.0f, -5.0f, 5.0f);
		else glOrtho(-2.0f, 2.0f, -2.0f / rac, 2.0f / rac, -4.0f, 4.0f);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	}
	else if (camera == 2){
		glViewport(0, 0, 800, 700);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		float rac = (float)800 / 700;
		gluPerspective(90, rac, 0, 15);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(0, -2, 0.007, 0, 0, 0, 0, 1, 0);
	}
	else if (camera == 3){
		glViewport(0, 0, 800, 700);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		float rac = (float)800 / 700;
		gluPerspective(90, rac, 0, 15);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(0, -2.5, 1.5, 0, 0, 0, 0, 1, 0);
	}


	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//draw initial scene
	drawGameObjects();

	gameHasStarted = true;

	glFlush();
}

void GameManager::keyPressed(unsigned char key){
	switch (key){
	case '1':
		camera = 1;
		break;
	case '2':
		camera = 2;
		break;
	case '3':
		camera = 3;
		break;
	case 'a':
		if (wireframe) {
			wireframe = false;
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		}
		else{
			wireframe = true;
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		}
		break;
	}
}

void GameManager::specialPress(int key){
	Car* carro;
	carro = (Car*)getObject(CAR);

	switch (key){
	case GLUT_KEY_UP:
		if (seta_cima)
			seta_cima = false;
		else
			seta_cima = true;
		break;
	case GLUT_KEY_DOWN:
		if (seta_baixo)
			seta_baixo = false;
		else
			seta_baixo = true;
		break;
	case GLUT_KEY_RIGHT:
		if (seta_direita)
			seta_direita = false;
		else
			seta_direita = true;
		break;
	case GLUT_KEY_LEFT:
		if (seta_esquerda)
			seta_esquerda = false;
		else
			seta_esquerda = true;
		break;
	}
}
void GameManager::specialUp(int key){
	Car* carro;
	carro = (Car*)getObject(CAR);

	switch (key){
	case GLUT_KEY_UP:
		if (seta_cima)
			seta_cima = false;
		else
			seta_cima = true;
		break;
	case GLUT_KEY_DOWN:
		if (seta_baixo)
			seta_baixo = false;
		else
			seta_baixo = true;
		break;
	case GLUT_KEY_RIGHT:
		if (seta_direita)
			seta_direita = false;
		else
			seta_direita = true;
		break;
	case GLUT_KEY_LEFT:
		if (seta_esquerda)
			seta_esquerda = false;
		else
			seta_esquerda = true;
		break;
	}

	//carro->setAcc(0, 0, 0);
	//carro->setSpeed(0, 0, 0);
}

void GameManager::reshape(int h, int w){

	//std::cout << "--->Reshape" << std::endl;

	float top, right, bottom, left, near, far;
	float delta;

	left = 2., right = -2., bottom = 2., top = -2., near = -2., far = 2.;

	// Width Height Ratio
	float wh_ratio = (right - left) - (top - bottom);

	// Aspect ratio of the window
	float aspect = (float)w / h;

	//std::cerr << aspect << std::endl;

	// Set Viewport: start at (0,0)
	// and size of the whole window
	glViewport(0, 0, w, h);

	//Pushes Projection matrix to top of the stack.
	//Loads identity matrix.
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//Pushes Model-View matrix to top of the stack.
	//Loads identity matrix.
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Define  ortho projection.
	// Allow window resizing.
	if (aspect > wh_ratio)
	{
		delta = ((top - bottom) * aspect - (right - left)) / 2;

		glOrtho(left - delta, right + delta, bottom, top, near, far);

	}
	else {

		delta = ((top - bottom) / aspect - (right - left)) / 2;

		glOrtho(left, right, bottom - delta, top + delta, near, far);
	}

}

void GameManager::update(){
	int i = 0;
	
	Car* carro;
	carro = (Car*)getObject(CAR);

	Cheerio* obstacles_hit[MAX_CHEERIOS];
	int number_obstacles_hit = 0;

	Butter* butters_hit[MAX_BUTTERS];
	int number_butters_hit = 0;

	Cheerio* obs;
	Butter* butter;


	if (seta_cima)
		carro->setAcc(CAR_ACCELERATION, CAR_ACCELERATION, 0);
	else if (seta_baixo)
		carro->setAcc(-CAR_ACCELERATION, -CAR_ACCELERATION, 0);
	else{
		carro->setAcc(0, 0, 0);
		carro->setSpeed(0, 0, 0);
	}
	if (seta_direita)
		carro->rodaDireita();
	else if (seta_esquerda)
		carro->rodaEsquerda();

	
	for (i; i < numButters; i++){
		butter = butters[i];

		if (carro->getBbox()->getXMax() > butter->getBbox()->getXMin())
		{
			if (carro->getBbox()->getXMin() < butter->getBbox()->getXMax())
			{
				if (carro->getBbox()->getYMax() > butter->getBbox()->getYMin())
				{
					if (carro->getBbox()->getYMin() < butter->getBbox()->getYMax())
					{

						butter->triggerCollision();

						butters_hit[number_butters_hit] = butter;
						number_butters_hit++;

						carro->triggerCollision();
					}

				}
			}
		}
	}

	for (i; i < numObstaculos; i++){
		obs = obstacles[i];

		if (carro->getBbox()->getXMax() > obs->getBbox()->getXMin())
		{
			if (carro->getBbox()->getXMin() < obs->getBbox()->getXMax())
			{
				if (carro->getBbox()->getYMax() > obs->getBbox()->getYMin())
				{
					if (carro->getBbox()->getYMin() < obs->getBbox()->getYMax())
					{
						
						obs->triggerCollision();

						obstacles_hit[number_obstacles_hit] = obs;
						number_obstacles_hit++;

						carro->triggerCollision();
					}

				}	
			}
		}
	}

	

	currtime = glutGet(GLUT_ELAPSED_TIME);

	for (i = 0; i < number_butters_hit; i++)
	{
		butters_hit[i]->update(currtime - prevtime, carro->getDirection(), *carro->getSpeed());
	}

	currtime = glutGet(GLUT_ELAPSED_TIME);

	for (i = 0; i < number_obstacles_hit; i++)
	{
		obstacles_hit[i]->update(currtime - prevtime, carro->getDirection(), *carro->getSpeed());
	}

	carro->update(currtime - prevtime);
	prevtime = currtime;

	glutPostRedisplay();
}