#include <iostream>
#include <iomanip>
#include <time.h>
#include <stdlib.h>

#include "GameManager.h"
#include "LightSource.h"
#include "Roadside.h"
#include "generic.h"
#include "Orange.h"
#include "Butter.h"
#include "Table.h"
#include "Cheerio.h"
#include "CollisionBox.h"
#include "OrthogonalCamera.h"
#include "PerspectiveCamera.h"


GameManager* GameManager::_instance = nullptr;

GameManager::GameManager()
{
	currtime = 0;
	prevtime = 0;
	numGameObjects = 0;
	numObstaculos = 0;
	numButters = 0;
	numOranges = 0;

	camera = 1;
	wireframe = false;
	seta_baixo = seta_cima = seta_direita = seta_esquerda = false;

	game_difficulty = 1;

	srand(time(NULL));
	
	orange_timestamp = glutGet(GLUT_ELAPSED_TIME);

	orange_gen_delta = rand() % 5000 + 1;

	while (orange_gen_delta < 1500){
		orange_gen_delta += 250;
	}
}

void GameManager::addOrange(Orange* orange){
	oranges[numOranges] = orange;
	numOranges += 1;
}

void GameManager::generateOrange(){
	
	if (numOranges >= MAX_ORANGES)
		return;

	//0 = posiçao positiva do eixo x
	//1 = posiçao negativa do eixo x
	int rand_binary_x;

	rand_binary_x = rand() % 2;

	//0 = posiçao positiva do eixo y
	//1 = posiçao negativa do eixo y
	int rand_binary_y;

	rand_binary_y = rand() % 2;

	/*std::cout << "GENERATING ORANGE! " << "[" << rand_binary_x << ", " << rand_binary_y << "];" << std::endl;*/

	float init_x;
	float init_y;
	float dir_x;
	float dir_y;

	float vel_x;
	float vel_y;

	dir_x = rand() % 2;
	if (!rand_binary_x)
		dir_x = dir_x * -1;

	dir_y = rand() % 2;
	if (!rand_binary_y)
		dir_y = dir_y * -1;

	while (dir_x == 0 && dir_y == 0)
	{
		dir_x = rand() % 2;
		if (!rand_binary_x)
			dir_x = dir_x * -1;

		dir_y = rand() % 2;
		if (!rand_binary_y)
			dir_y = dir_y * -1;
	}

	init_x = rand() % 6 + 1;
	init_x = init_x / 10;
	if (rand_binary_x)
		init_x = init_x * -1;

	init_y = rand() % 6 + 1;
	init_y = init_y / 10;
	if (rand_binary_y)
		init_y = init_y * -1;

	do {
		vel_x = rand() % INITIAL_ORANGE_SPEED + 1;
	} while (vel_x < 1);

	vel_x = vel_x / 10000;

	do {
		vel_y = rand() % INITIAL_ORANGE_SPEED + 1;
	} while (vel_y < 1);

	vel_y = vel_y / 10000;


	std::cout << "GENERATING ORANGE at " << "[" << init_x << ", " << init_y << "];" << std::endl;
	
	Orange* orange;

	orange = new Orange(new Vector3(init_x, init_y,0));
	orange->setDirection(dir_x, dir_y,0);
	orange->setSpeed(vel_x * game_difficulty,  vel_y * game_difficulty, 0);

	addOrange(orange);

	//orange->set

	orange_gen_delta = rand() % MAX_ORANGE_DELTA + 1;

	while (orange_gen_delta < MIN_ORANGE_DELTA){
		orange_gen_delta += 250;
	}

	orange_timestamp = glutGet(GLUT_ELAPSED_TIME);

}

Camera* GameManager::getCamera(int camera){
	
	switch (camera)
	{
	case ORTHOGONAL_CAM:
		return cameras[0];
		break;
	case FIXED_PERSPECTIVE_CAM:
		return cameras[1];
		break;
	case MOBILE_PERSPECTIVE_CAM:
		return cameras[2];
		break;
	default:
		return nullptr;
		break;
	}

	return nullptr;
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

int GameManager::init(){

	OrthogonalCamera *cam1 = new OrthogonalCamera(ASPECT_RATIO*ORTHO_LEFT, ASPECT_RATIO*ORTHO_RIGHT, ORTHO_BOTTOM, ORTHO_TOP, ORTHO_NEAR, ORTHO_FAR);
	PerspectiveCamera *cam2 = new PerspectiveCamera(new Vector3(0, -2, 0.007), new Vector3(0, 0, 0), new Vector3(0, 1, 0), FOVY, ASPECT_RATIO, ZNEAR, ZFAR, FIXED_PERSPECTIVE_CAM);
	PerspectiveCamera *cam3 = new PerspectiveCamera(new Vector3(0, 0, 0), new Vector3(0, 0, 0), new Vector3(0, 1, 0), FOVY, ASPECT_RATIO, ZNEAR, ZFAR, MOBILE_PERSPECTIVE_CAM);

	cameras[0] = cam1;
	cameras[1] = cam2;
	cameras[2] = cam3;

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

	for (i = 0; i < numOranges; i++){
		
		if (!oranges[i]->destroyedp())
			oranges[i]->draw();
	}
	

	return 0;

}

void GameManager::display(){
	Car* car;
	car = (Car*)getObject(CAR);

	glClearDepth(1.0);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	glViewport(0, 0, VIEWPORT_X, VIEWPORT_Y);

	if (camera == 1){

		OrthogonalCamera* camera = (OrthogonalCamera*)getCamera(ORTHOGONAL_CAM);

		camera->computeProjectionMatrix();
		camera->computeVisualizationMatrix();
	}
	else if (camera == 2){
		
		PerspectiveCamera* camera = (PerspectiveCamera*)getCamera(FIXED_PERSPECTIVE_CAM);

		camera->computeProjectionMatrix();
		camera->computeVisualizationMatrix();
	}
	else if (camera == 3){
		
		PerspectiveCamera* camera = (PerspectiveCamera*)getCamera(MOBILE_PERSPECTIVE_CAM);
		
		camera->computeProjectionMatrix();
		camera->computeVisualizationMatrix();
		
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
	
	currtime = glutGet(GLUT_ELAPSED_TIME);

	if (currtime > 15000)
	{
		game_difficulty = 2;

		if (currtime > 30000)
		{
			game_difficulty = 3;

			if (currtime > 45000)
			{
				game_difficulty = 4;
			}
		}
	}


	Car* carro;
	carro = (Car*)getObject(CAR);

	Cheerio* obstacles_hit[MAX_CHEERIOS];
	int number_obstacles_hit = 0;

	Butter* butters_hit[MAX_BUTTERS];
	int number_butters_hit = 0;

	Cheerio* obs;
	Butter* butter;
	Orange* orange;


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

	
	for (i = 0; i < numButters; i++){
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

	for (i = 0; i < numObstaculos; i++){
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

	


	for (i = 0; i < numOranges; i++){
		orange = oranges[i];

		if (orange->destroyedp())
			continue;

		if (carro->getBbox()->getXMax() > orange->getBbox()->getXMin())
		{
			if (carro->getBbox()->getXMin() < orange->getBbox()->getXMax())
			{
				if (carro->getBbox()->getYMax() > orange->getBbox()->getYMin())
				{
					if (carro->getBbox()->getYMin() < orange->getBbox()->getYMax())
					{
						carro->restartPosition();
					}

				}
			}
		}

		if (orange->getPosition()->getX() >= 2.3 || orange->getPosition()->getX() <= -2.3 || orange->getPosition()->getY() >= 2.3 || orange->getPosition()->getY() <= -2.3)
			orange->destroy();

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

	


	currtime = glutGet(GLUT_ELAPSED_TIME);

	for (i = 0; i < numOranges; i++)
	{
		oranges[i]->update(currtime - prevtime);
	}

	


	carro->update(currtime - prevtime);
	prevtime = currtime;


	currtime = glutGet(GLUT_ELAPSED_TIME);
	
	if (currtime - orange_gen_delta >= orange_timestamp)
		generateOrange();

	Entity* veiculo = getObject(CAR);
	Car* car = (Car*)getObject(CAR);
	PerspectiveCamera* cameraMovel = (PerspectiveCamera*)cameras[2];
	cameraMovel->update(new Vector3(veiculo->getPosition()->getX(), veiculo->getPosition()->getY() - 0.3, veiculo->getPosition()->getZ() + 0.5), new Vector3(veiculo->getPosition()->getX(), veiculo->getPosition()->getY() + 0.5, veiculo->getPosition()->getZ()));
	cameras[2] = cameraMovel;
	
	
	glutPostRedisplay();
}