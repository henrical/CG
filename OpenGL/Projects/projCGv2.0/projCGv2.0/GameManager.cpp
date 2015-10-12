#include <iostream>

#include "GameManager.h"
#include "LightSource.h"
#include "Roadside.h"
#include "generic.h"
#include "Orange.h"

GameManager* GameManager::_instance = nullptr;

// Constant arrays with color RBG(0-1 scale) codes.
// Passar isto a funçoes que pedem um "const float color[]"
// por exemplo: 
//	"road->draw(CHEERIO_BROWN);" desenha a estrada da cor dos cheerios
extern "C" const float WHITE[] = { 1, 1, 1 };
extern "C" const float LIGHT_BLUE[] = { 0.81960784, 0.8, 1 };
extern "C" const float LIGHT_GREY[] = { 0.89019607, 0.89019607, 0.89019607};
extern "C" const float LIGHT_ORANGE[] = { 1, 0.94509803, 0.72156862 };
extern "C" const float ORANGE[] = { 1, 0.61568627, 0};
extern "C" const float CHEERIO_BROWN[] = { 0.7607843137, 0.537254902, 0.1764705882 };

GameManager::GameManager()
{
	_gameObjects = 0 ;
	camera = 1;
}

void GameManager::addObject()
{
	_gameObjects += 1;
}

int GameManager::getObjects()
{
	return _gameObjects;
}

// Pass color as parameter
// i.e. LIGHT_BLUE, WHITE, LIGHT_GREY
void GameManager::drawTable(const float color[]){
	glColor3f(color[0], color[1], color[2]);
	glScalef(1.5, 1.5, 1.5);
	glPushMatrix();
	glTranslatef(0.0, 0.0, -1.5);
	glutSolidCube(3);
	glPopMatrix();
}

int GameManager::drawGameObjects(){
	std::cout << "---> Drawing game objects." << std::endl;
	
	drawTable(LIGHT_BLUE);

	Car* car = new Car();
	car->draw();
	/*delete c;*/

	Roadside *road = new Roadside();
	road->draw(CHEERIO_BROWN);

	Orange* orange = new Orange(&Vector3(0,0,0));

	orange->draw();

	return 0;

}

void GameManager::display(){
	std::cout << "---> Display." << std::endl;

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
	GameManager::instance()->drawGameObjects();
	
	gameHasStarted = true;

	glFlush();
}

int GameManager::keyPressed(unsigned char key){
	if (key == '1'){
		camera = 1;
	}
	else if (key == '2'){
		camera = 2;
	}
	else if (key == '3'){
		camera = 3;
	}
	return 0;
}

void GameManager::reshape(int h, int w){

	std::cout << "--->Reshape" << std::endl;

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