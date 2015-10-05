#include <iostream>

#include "GL/glut.h"
#include "Roadside.h"

Roadside::Roadside() {

}

Roadside::~Roadside(){

}

void Roadside::draw(const float color[]){
	this->drawRoadsideSegment(color);
}

void Roadside::drawRoadsideSegment(const float color[]/*Vector3 inicial,int numtorus, Vector3 direction*/){
	int i,num_cheerios=5;
	
	float pos_x = 0.5, pos_y = 0.5, pos_z = 0;
	
	//posição da outra margem da estrada
	float margin_position;
	
	glColor3f(color[0], color[1], color[2]);

	for (i = 0; i < num_cheerios; i++)
	{
		glPushMatrix();
		glTranslatef(pos_x, pos_y, pos_z);
		glutSolidTorus(0.01, 0.02, 50, 50);
		glPopMatrix();

		margin_position = pos_y + ROAD_WIDTH;

		glPushMatrix();
		glTranslatef(pos_x, margin_position , pos_z);
		glutSolidTorus(0.01, 0.02, 50, 50);
		glPopMatrix();

		pos_x += ROAD_PADDING; //ROAD_PADDING is defined in "Roadside.h"

	}
}