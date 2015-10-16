#include <iostream>

#include "GL/glut.h"
#include "LightSource.h"
#include "Car.h"
#include "GameObject.h"
#include "Obstacle.h"

#define ACCELERATION 0.0000005


//Constant arrays with the color codes.
// F.E.: LIGHT_BLUE = {209,204,255}
// Pass these as parameters to certain functions
// to specify color of objects.
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

		void addObject(GameObject *obj);
		void addObstacle(Obstacle *obs);

		int getObjects(); //TODO

		
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