#ifndef _TABLE_H_
#define _TABLE_H_

#include "Obstacle.h"
#include "GL\glut.h"

#define TABLE_SIDE 4.5f
#define SUBDIVISIONS 250 //250 por 250 poligonos

#define POLYGON_SIDE TABLE_SIDE / SUBDIVISIONS

#define TEXT_INF 0
#define TEXT_SUP 0.7

class Table : public Obstacle
{
private:
	GLuint texture;

public:
	Table(){}
	Table(GLuint texture);
	~Table();

	void draw();
	void setTexture(GLuint texture);

};

#endif