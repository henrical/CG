#include <iostream>

/**
 * Singleton GameManager class.
 *
 **/
class GameManager {

	//Private Variables
	private:
		static GameManager* _instance;
		int _gameObjects;

	//Private Methods
	private:
		GameManager();
		~GameManager();

	//Public Methods and Functions
	public:
		static GameManager* instance()
		{
			if (!_instance) 
				_instance = new GameManager();

			return _instance;
		}

		//Placeholders
		void addObject();
		int getObjects();
};