#include <iostream>

#include "GL/glut.h"
#include "LightSource.h"

/**
 * Singleton GameManager class.
 * This class has only one instance.
 * 
 * How to use:
 * 
 * GameManager::instance()->instance_method();
 *
 **/
class GameManager {

	//Private Variables
	private:
		static GameManager* _instance;
		int _gameObjects;
		LightSource _lightSources[10]; 
		int _cameras;

	//Private Methods
	private:
		GameManager();
		~GameManager();

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

		int keyPressed(); //TODO
		int onTimer(); //TODO
		int idle(); //TODO
		int update(); //TODO
		int init(); //TODO


		// #####################################//
		// Display and Reshape callback functions.
		static void display()
		{
			//Set clearing value.
			glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

			//Clear screen.
			glClear(GL_COLOR_BUFFER_BIT);
			
			//TODO

			glFlush();
		}

		static void reshape(int h, int w)
		{
			float top, right, bottom, left, near, far;
			float delta;

			left = 2., right = -2., bottom = 2., top = -2., near =-2., far= 2.;

			// Width Height Ratio
			float wh_ratio = (right - left) - (top - bottom); // ratio = 0

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

				glOrtho(left - delta, right + delta, bottom, top,near,far);

			}
			else {

				delta = ((top - bottom) / aspect - (right - left)) / 2;

				glOrtho(left, right, bottom - delta, top + delta, near, far);
			}
		}

};