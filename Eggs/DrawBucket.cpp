#include "cg_project.h"
extern GLdouble width,height,ycord_first,ycord_second,ycord_third,xcord_first,xcord_second,xcord_third,deltax_first,deltax_second,deltax_third,velocity;
extern GLdouble eggcentrex,eggcentrey,egginbasketnumber,g,ellipsecordx,ellipsecordy,eggcentrexnext,eggcentreynext,delta;
extern float Pi;
extern bool flag;
void DrawBucket(GLdouble xcord,GLdouble ycord)
{
	glColor3f(102.0/255.0, 51.0/255.0, 0.0);
	// Set material properties
	GLfloat qaBlack[] = {0.0, 0.0, 0.0, 1.0};
	GLfloat qaGreen[] = {0.0, 1.0, 0.0, 1.0};
	GLfloat qaWhite[] = {1.0, 1.0, 1.0, 1.0};
	GLfloat qaBrown[] = {102.0/255.0, 51.0/255.0, 0.0};
	glMaterialfv(GL_FRONT, GL_AMBIENT, qaBrown);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, qaBrown);
	glMaterialfv(GL_FRONT, GL_SPECULAR, qaWhite);
	glMaterialf(GL_FRONT, GL_SHININESS, 100.0);
	glBegin(GL_POLYGON);
		glVertex3f(xcord, ycord+0.03, 0.0);
		glVertex3f(xcord+0.02, ycord, 0.0);
		glVertex3f(xcord+0.04, ycord, 0.0);
		glVertex3f(xcord+0.06, ycord+0.03, 0.0);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(xcord-0.005,ycord+0.008+0.03,0.0);
		glVertex3f(xcord-0.005,ycord+0.03,0.0);
		glVertex3f(xcord+0.06+0.005,ycord+0.03,0.0);
		glVertex3f(xcord+0.06+0.005,ycord+0.008+0.03,0.0);
	glEnd();
}
