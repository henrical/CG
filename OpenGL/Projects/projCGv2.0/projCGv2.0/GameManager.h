#include <iostream>

#include "GL/glut.h"
#include "LightSource.h"
#include "Car.h"


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
		int _gameObjects;
		LightSource _lightSources[10]; 
		int _cameras, camera;

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

		void addObject(); //TODO
		int getObjects(); //TODO

		
		int idle(); //TODO
		int init();


		// #####################################//
		// Callback functions.
		void display();

		void reshape(int h, int w);

		int keyPressed(unsigned char key); 

		int onTimer(); //TODO

		int update(); //TODO
		
		

};