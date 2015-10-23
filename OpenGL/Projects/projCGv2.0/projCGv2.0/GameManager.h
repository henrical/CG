#include <iostream>

#include "GL/glut.h"
#include "LightSource.h"
#include "Car.h"
#include "GameObject.h"
#include "Obstacle.h"
#include "Cheerio.h"
#include "Orange.h"
#include "Butter.h"

#define VIEW_COLLISION_BOXES 0		//0 para não ver as boxes, 1 para ver

#define CAR_ACCELERATION 0.0000005

#define ROADSIDE 0
#define CAR 1 
#define TABLE 2

/**
 * Singleton GameManager class.
 * This class has only one instance.
 * 
 * How to use:
 * 
 * GameManager::instance()->key_pressed();
 *
 **/
class GameManager {

	//Private Variables
	private:
		static GameManager* _instance;

		LightSource _lightSources[10];
		GameObject* _gameObjects[10];
		
		Cheerio* obstacles[200];
		Orange* oranges[50];
		Butter* butters[10];


		int _cameras, camera;
		int numObstaculos;
		int numOranges;
		int numButters;
		int numGameObjects, prevtime, currtime;
		bool gameHasStarted = false;
		bool wireframe;
		bool seta_cima, seta_baixo, seta_esquerda, seta_direita;

	//Private Methods
	private:
		GameManager();
		~GameManager();

		void drawTable(const float color[]);

	//Public Methods and Functions
	public:
		static GameManager* instance()
		{
			if (!_instance) {
				_instance = new GameManager();

			}
			return _instance;
		}

		static int viewCollisionBoxes(){
			return VIEW_COLLISION_BOXES;
		}

		void addObject(GameObject *obj);
		void addObstacle(Cheerio *obs);
		void addButter(Butter *obs);
		void addOrange(Orange *obs);

		GameObject* getObject(int object);

		
		int idle(); //TODO
		
		int init();
		int drawGameObjects();

		// #####################################//
		// Callback functions.
		void display();

		void reshape(int h, int w);

		void keyPressed(unsigned char key); 

		void specialPress(int key);
		void specialUp(int key);

		int onTimer(); //TODO

		void update(); //TODO
		
		

};