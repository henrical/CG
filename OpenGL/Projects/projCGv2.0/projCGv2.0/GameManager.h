#include <iostream>

#include "GL/glut.h"
#include "LightSource.h"
#include "Car.h"
#include "GameObject.h"
#include "Obstacle.h"
#include "Cheerio.h"
#include "Orange.h"
#include "Butter.h"
#include "GameMessageUI.h"
#include "Camera.h"

#define VIEW_COLLISION_BOXES 0		//0 para não ver as boxes, 1 para ver

#define VIEWPORT_X 800
#define VIEWPORT_Y 700

#define ASPECT_RATIO (float)VIEWPORT_X/VIEWPORT_Y

#define ORTHOGONAL_CAM 1
#define FIXED_PERSPECTIVE_CAM 2
#define MOBILE_PERSPECTIVE_CAM 3

/**
 * Camara 1 (Ortogonal)
**/
#define ORTHO_LEFT -3.0f
#define ORTHO_RIGHT 3.0f
#define ORTHO_BOTTOM -3.0f
#define ORTHO_TOP 3.0f
#define ORTHO_NEAR -5.0f
#define ORTHO_FAR 5.0f

/**
* Camara 2 e 3 (perspectiva)
**/
#define FOVY 90
#define ZNEAR 0.4
#define ZFAR 15


#define MAX_CHEERIOS 200
#define MAX_BUTTERS 10
#define MAX_ORANGES 150
#define MAX_LIGHTSOURCES 10
#define MAX_TEXTURES 10

#define CAR_ACCELERATION 0.0000005

#define NUMBER_LIVES 1

#define INITIAL_ORANGE_SPEED 2

//max time between orange spawns
#define MAX_ORANGE_DELTA 8000

//min time between orange spawns
#define MIN_ORANGE_DELTA 3000



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

		LightSource* _lightSources[MAX_LIGHTSOURCES];
		GameObject* _gameObjects[10];
		
		Cheerio* obstacles[MAX_CHEERIOS];
		Orange* oranges[MAX_ORANGES];
		Butter* butters[MAX_BUTTERS];

		Camera* cameras[3];

		LightSource* luz_cena;

		bool paused;
		GameMessageUI interface_window;
		
		int lives;
		bool game_over;
		GameMessageUI endgame_window;


		GLuint textures[MAX_TEXTURES];

		int game_difficulty;
		
		int pause_timestamp;

		int candlelight_active;
		// Spawn time of last orange
		int orange_timestamp;

		// Interval between generation of oranges
		// Randomly generated
		int orange_gen_delta;

		int  camera;
		int numObstaculos;
		int numOranges;
		int numButters;
		int numGameObjects, prevtime, currtime;
		bool gameHasStarted = false;
		bool wireframe;
		bool seta_cima, seta_baixo, seta_esquerda, seta_direita;
		bool iluminacao;
		bool smooth;

		int lastGameResetTimestamp;

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

		void restartGame();
		void resetGame();

		void generateOrange();

		void loadBMP();

		void addObject(GameObject *obj);
		void addObstacle(Cheerio *obs);
		void addButter(Butter *obs);
		void addOrange(Orange *obs);

		GameObject* getObject(int object);

		Camera* getCamera(int camera);
		
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

		int onTimer(); 

		void update();
		
		

};