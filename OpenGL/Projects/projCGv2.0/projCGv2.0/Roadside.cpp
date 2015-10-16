#include <iostream>

#include "GL/glut.h"
#include "Roadside.h"

Roadside::Roadside() {

}

Roadside::~Roadside(){

}


void Roadside::draw(){
	const float color[] = { 0.6392156863, 0.2980392157, 0 };

	//std::cout << "-----> Drawing road"<< std::endl;

	this->drawRoadsideSegment(color, Vector3( -1.3, -0.9, 0), 16, VERTICAL, INSIDE_CURVE);

	this->drawRoadsideMargin(color, Vector3(-0.85, 0.79, 0), 2, NORTHEAST);
	this->drawRoadsideMargin(color, Vector3(-1.28, 0.90, 0), 7, NORTHEAST);

	this->drawRoadsideSegment(color, Vector3( -0.82, 0.9, 0), 16, HORIZONTAL, INSIDE_CURVE); 

	this->drawRoadsideMargin(color, Vector3(0.855, 0.85, 0), 2, SOUTHEAST);
	this->drawRoadsideMargin(color, Vector3(0.96, 1.26, 0), 7, SOUTHEAST);

	this->drawRoadsideSegment(color, Vector3(0.95, -0.88, 0), 16, VERTICAL, OUTSIDE_CURVE);

	this->drawRoadsideMargin(color, Vector3(0.89, -0.845, 0), 1, SOUTHWEST);
	this->drawRoadsideMargin(color, Vector3(1.3, -0.96, 0), 6, SOUTHWEST);

	this->drawRoadsideSegment(color, Vector3(-0.98, -1.3, 0), 18, HORIZONTAL, OUTSIDE_CURVE);

	this->drawRoadsideMargin(color, Vector3(-1.3, -1, 0), 5, SOUTHEAST);

}

void Roadside::drawRoadsideSegment(const float color[], Vector3 initial, int num_torus, int direction, int curve){
	int i, num_cheerios = num_torus;

	double pos_x = initial.getX(), pos_y = initial.getY(), pos_z = initial.getZ();

	//debug
	//std::cout << "-----> Drawing road segment in " << pos_x << pos_y << pos_z << std::endl;

	//posição da outra margem da estrada
	float margin_position;

	glColor3f(color[0], color[1], color[2]);

	switch (direction)
	{
	case HORIZONTAL:
		switch (curve)
		{
		case OUTSIDE_CURVE:

			glPushMatrix();
			glTranslatef(pos_x, pos_y, pos_z);
			glutSolidTorus(0.01, 0.02, 50, 50);
			glPopMatrix();

			pos_x += ROAD_PADDING;

			for (i = 0; i < num_cheerios; i++)
			{
				glPushMatrix();
				glTranslatef(pos_x, pos_y, pos_z);
				glutSolidTorus(0.01, 0.02, 50, 50);
				glPopMatrix();

				margin_position = pos_y + ROAD_WIDTH;

				glPushMatrix();
				glTranslatef(pos_x, margin_position, pos_z);
				glutSolidTorus(0.01, 0.02, 50, 50);
				glPopMatrix();

				pos_x += ROAD_PADDING; //ROAD_PADDING is defined in "Roadside.h"

			}

			glPushMatrix();
			glTranslatef(pos_x, pos_y, pos_z);
			glutSolidTorus(0.01, 0.02, 50, 50);
			glPopMatrix();
		break;
		case INSIDE_CURVE:
			glPushMatrix();
			glTranslatef(pos_x, pos_y + ROAD_WIDTH, pos_z);
			glutSolidTorus(0.01, 0.02, 50, 50);
			glPopMatrix();

			pos_x += ROAD_PADDING;

			for (i = 0; i < num_cheerios; i++)
			{
				glPushMatrix();
				glTranslatef(pos_x, pos_y, pos_z);
				glutSolidTorus(0.01, 0.02, 50, 50);
				glPopMatrix();

				margin_position = pos_y + ROAD_WIDTH;

				glPushMatrix();
				glTranslatef(pos_x, margin_position, pos_z);
				glutSolidTorus(0.01, 0.02, 50, 50);
				glPopMatrix();

				pos_x += ROAD_PADDING; //ROAD_PADDING is defined in "Roadside.h"

			}

			glPushMatrix();
			glTranslatef(pos_x, pos_y + ROAD_WIDTH, pos_z);
			glutSolidTorus(0.01, 0.02, 50, 50);
			glPopMatrix();
		break;
		}
	break;
	case VERTICAL:
		switch (curve)
		{
		case INSIDE_CURVE:
			glPushMatrix();
			glTranslatef(pos_x, pos_y, pos_z);
			glutSolidTorus(0.01, 0.02, 50, 50);
			glPopMatrix();

			pos_y += ROAD_PADDING;

			for (i = 0; i < num_cheerios; i++)
			{
				glPushMatrix();
				glTranslatef(pos_x, pos_y, pos_z);
				glutSolidTorus(0.01, 0.02, 50, 50);
				glPopMatrix();

				margin_position = pos_x + ROAD_WIDTH;

				glPushMatrix();
				glTranslatef(margin_position, pos_y, pos_z);
				glutSolidTorus(0.01, 0.02, 50, 50);
				glPopMatrix();

				pos_y += ROAD_PADDING; //ROAD_PADDING is defined in "Roadside.h"

			}

			glPushMatrix();
			glTranslatef(pos_x, pos_y, pos_z);
			glutSolidTorus(0.01, 0.02, 50, 50);
			glPopMatrix();
		break;
		case OUTSIDE_CURVE:
			glPushMatrix();
			glTranslatef(pos_x + ROAD_WIDTH, pos_y, pos_z);
			glutSolidTorus(0.01, 0.02, 50, 50);
			glPopMatrix();

			pos_y += ROAD_PADDING;

			for (i = 0; i < num_cheerios; i++)
			{
				glPushMatrix();
				glTranslatef(pos_x, pos_y, pos_z);
				glutSolidTorus(0.01, 0.02, 50, 50);
				glPopMatrix();

				margin_position = pos_x + ROAD_WIDTH;

				glPushMatrix();
				glTranslatef(margin_position, pos_y, pos_z);
				glutSolidTorus(0.01, 0.02, 50, 50);
				glPopMatrix();

				pos_y += ROAD_PADDING; //ROAD_PADDING is defined in "Roadside.h"

			}

			glPushMatrix();
			glTranslatef(pos_x + ROAD_WIDTH, pos_y, pos_z);
			glutSolidTorus(0.01, 0.02, 50, 50);
			glPopMatrix();
		break;
		}
		break;
	}
}

void Roadside::drawRoadsideMargin(const float color[], Vector3 initial, int num_torus, int direction){
	int i, num_cheerios = num_torus;

	double pos_x = initial.getX(), pos_y = initial.getY(), pos_z = initial.getZ();

	glColor3f(color[0], color[1], color[2]);

	switch (direction)
	{
	case SOUTHEAST:
		for (i = 0; i < num_cheerios; i++)
		{
			glPushMatrix();
			glTranslatef(pos_x, pos_y, pos_z);
			glutSolidTorus(0.01, 0.02, 50, 50);
			glPopMatrix();

			pos_x += ANGLED_ROAD_PADDING; 
			pos_y = pos_y - ANGLED_ROAD_PADDING;
		}
	break;
	case NORTHEAST:
		for (i = 0; i < num_cheerios; i++)
		{
			glPushMatrix();
			glTranslatef(pos_x, pos_y, pos_z);
			glutSolidTorus(0.01, 0.02, 50, 50);
			glPopMatrix();

			pos_x += ANGLED_ROAD_PADDING;
			pos_y = pos_y + ANGLED_ROAD_PADDING;
		}
	break;
	case SOUTHWEST:
		for (i = 0; i < num_cheerios; i++)
		{
			glPushMatrix();
			glTranslatef(pos_x, pos_y, pos_z);
			glutSolidTorus(0.01, 0.02, 50, 50);
			glPopMatrix();

			pos_x = pos_x - ANGLED_ROAD_PADDING;
			pos_y = pos_y - ANGLED_ROAD_PADDING;
		}
	break;
	case NORTHWEST:
		for (i = 0; i < num_cheerios; i++)
		{
			glPushMatrix();
			glTranslatef(pos_x, pos_y, pos_z);
			glutSolidTorus(0.01, 0.02, 50, 50);
			glPopMatrix();

			pos_x = pos_x - ANGLED_ROAD_PADDING;
			pos_y = pos_y + ANGLED_ROAD_PADDING;
		}
	break;
	}
}

