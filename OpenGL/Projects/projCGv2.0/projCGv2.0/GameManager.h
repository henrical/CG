#include <iostream>

#include "GL/glut.h"
#include "LightSource.h"
#include "Car.h"
#include "GameObject.h"
#include "Obstacle.h"

#define VIEW_COLLISION_BOXES 1		//0 para não ver as boxes, 1 para ver

#define CAR_ACCELERATION 0.0000005

#define ROADSIDE 0
#define CAR 1 
#define TABLE 2



//Constant arrays with the color codes.
extern "C" {
	extern const float WHITE[];
	extern const float LIGHT_BLUE[];
	extern const float LIGHT_GREY[];
	extern const float LIGHT_ORANGE[];
	extern const float ORANGE[];
	extern const float CHEERIO_BROWN[];
	extern const float YELLOW[];
}

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
		Obstacle* obstacles[200];
		int _cameras, camera, numObstaculos, numGameObjects, prevtime, currtime;
		bool gameHasStarted = false;
		bool wireframe;

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
		void addObstacle(Obstacle *obs);

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
		void specialUp();

		int onTimer(); //TODO

		void update(); //TODO
		
		

};