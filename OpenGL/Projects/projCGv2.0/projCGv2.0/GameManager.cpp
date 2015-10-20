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
	camera = 1;
	wireframe = false;
}

void GameManager::addObject(GameObject *obj)
{
	_gameObjects[numGameObjects] = obj;
	numGameObjects += 1;
}

void GameManager::addObstacle(Obstacle *obs){
	obstacles[numObstaculos] = obs;
	numObstaculos += 1;
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


	addObstacle(new Orange(&Vector3(0, 1.25, 0)));
	addObstacle(new Orange(&Vector3(-0.9, -0.5, 0)));
	addObstacle(new Orange(&Vector3(0.9, -0.9, 0)));
	addObstacle(new Butter(&Vector3(-0.79, 0.85, 0), 0));
	addObstacle(new Butter(&Vector3(1.25, 0.3, 0), 0));
	addObstacle(new Butter(&Vector3(0, -1.2, 0), 0));
	addObstacle(new Butter(&Vector3(1, 1.2, 0), 0));
	addObstacle(new Butter(&Vector3(-1.2, -1, 0), 0));
	/*addObstacle(new Cheerio(&Vector3(0, 0, 0)));*/
	
	

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
	

	//desenhar obstaculos
	for (i = 0; i < numObstaculos; i++){
		obstacles[i]->draw();
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
		//carro->setAcc(carro->getAcc()->getX(), 0.000005, carro->getAcc()->getZ());
		carro->setAcc(CAR_ACCELERATION, CAR_ACCELERATION, 0);
		break;
	case GLUT_KEY_DOWN:
		//carro->setAcc(carro->getAcc()->getX(),- 0.000005, carro->getAcc()->getZ());
		carro->setAcc(-CAR_ACCELERATION, -CAR_ACCELERATION, 0);
		break;
	case GLUT_KEY_RIGHT:
		//carro->setAcc( 0.00001, carro->getAcc()->getY(), carro->getAcc()->getZ());
		carro->rodaDireita();
		break;
	case GLUT_KEY_LEFT:
		//carro->setAcc( - 0.00001, carro->getAcc()->getY(), carro->getAcc()->getZ());
		carro->rodaEsquerda();
		break;
	}
}
void GameManager::specialUp(){
	Car* carro;
	carro = (Car*)getObject(CAR);
	
	carro->setAcc(0, 0, 0);
	carro->setSpeed(0, 0, 0);
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

	Obstacle* obs;

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
						std::cout << "=== OBSTACLE HIT! ===" << std::endl;
						std::cout << "===== " << i << " ===" << std::endl;

						carro->setAcc(0, 0, 0);
						carro->invertSpeed();

					}

				}	
			}
		}
	}

	currtime = glutGet(GLUT_ELAPSED_TIME);
	
	//_gameObjects[0]->update(currtime - prevtime);
	
	carro->update(currtime - prevtime);
	prevtime = currtime;
	
	glutPostRedisplay();
}