#ifndef _COLLISION_H_
#define _COLLISION_H_

class CollisionBox{

	private:
		float xMin;
		float yMin;
		float xMax;
		float yMax;

	public:
		CollisionBox(float xm, float ym, float xM, float yM);
		CollisionBox();
				
		~CollisionBox();

		void setCordinates(float xm, float ym, float xM, float yM);
		float* getCordinates();

		//Boxes will appear ingame if GameManager::VIEW_COLLISION_BOXES is set to 1.
		void draw();

};

#endif