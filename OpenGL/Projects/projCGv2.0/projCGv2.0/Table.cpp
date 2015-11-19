#include "generic.h"
#include "Table.h"
#include "GL/Glut.h"

void Table::draw(){
	
	glEnable(GL_TEXTURE_2D);

	GLfloat ambi[] = { 0.5, 0.5, 1.0, 1.f };
	GLfloat diff[] = { 0.0, 0.1, 0.2, 1.f };
	GLfloat spec[] = { 0.3, 0.4, 0.2, 1.f };
	//glColor3f(0.5, 0.78, 1.0);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambi);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, spec);

	int collumn = 0;
	int row = 0;

	float curr_x, curr_y;

	// The drawing begins at point (root_cordinate, root_cordinate)
	// in the bottom left corner.
	float root_cordinate = - 1 * TABLE_SIDE / 2;;

	curr_y = curr_x = root_cordinate;


	for (row; row < SUBDIVISIONS; row++)
	{
		if (row > 0){
			curr_y += POLYGON_SIDE - 0.001 ;
			curr_x = root_cordinate;
		}

		collumn = 0;

		for (collumn; collumn < SUBDIVISIONS; collumn++)
		{

			glBegin(GL_QUADS);

			glNormal3f(0.0, 0.0, 1);

			glTexCoord2f(TEXT_INF, TEXT_INF);
			glVertex3f(curr_x, curr_y, 0.0);

			glTexCoord2f(TEXT_INF, TEXT_SUP);
			glVertex3f(curr_x + POLYGON_SIDE, curr_y, 0.0);

			glTexCoord2f(TEXT_SUP, TEXT_SUP);
			glVertex3f(curr_x + POLYGON_SIDE, curr_y + POLYGON_SIDE, 0.0);

			glTexCoord2f(TEXT_SUP, TEXT_INF);
			glVertex3f(curr_x, curr_y + POLYGON_SIDE, 0.0);

			glEnd();

			curr_x += POLYGON_SIDE - 0.001;


			/*glPopMatrix();*/
			//glPopMatrix();

		}

	}

	glDisable(GL_TEXTURE_2D);
}