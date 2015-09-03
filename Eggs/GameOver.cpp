#include "cg_project.h"
#include <stdio.h>
extern GLdouble width,height,ycord_first,ycord_second,ycord_third,xcord_first,xcord_second,xcord_third,deltax_first,deltax_second,deltax_third,velocity;
extern GLdouble eggcentrex,eggcentrey,egginbasketnumber,g,ellipsecordx,ellipsecordy,eggcentrexnext,eggcentreynext,delta;
extern float Pi;
extern bool flag,slideFlag,gameoverflag;
extern int basketBelow,basketAbove,life,points;

void GameOver()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0,0,0,0);
	glColor3f(1,1,0);
	glLineWidth(3.0);
	GLfloat qaWhite[] = {1.0, 1.0, 1.0, 1.0};
	GLfloat qaYellow[] = {1.0,1.0,0.0,1.0};
	GLfloat qaRed[]={1.0,0.0,0.0,1.0};

	glBegin(GL_QUADS);
	glMaterialfv(GL_FRONT, GL_AMBIENT, qaYellow);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, qaYellow);
	glMaterialfv(GL_FRONT, GL_SPECULAR, qaWhite);
	glMaterialf(GL_FRONT, GL_SHININESS, 100.0);
		glVertex3f(0.2,0.35,0.0);
		glVertex3f(0.2,0.75,0.0);
		glVertex3f(0.72,0.75,0.0);
		glVertex3f(0.72,0.35,0.0);
	glEnd();

	glBegin(GL_QUADS);
	glMaterialfv(GL_FRONT, GL_AMBIENT, qaYellow);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, qaYellow);
	glMaterialfv(GL_FRONT, GL_SPECULAR, qaWhite);
	glMaterialf(GL_FRONT, GL_SHININESS, 100.0);
		glVertex3f(0.2,0.1,0.0);
		glVertex3f(0.2,0.3,0.0);
		glVertex3f(0.72,0.3,0.0);
		glVertex3f(0.72,0.1,0.0);
	glEnd();
		glColor3f(1,0,0);
	glMaterialfv(GL_FRONT, GL_AMBIENT, qaRed);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, qaRed);
	glMaterialfv(GL_FRONT, GL_SPECULAR, qaWhite);
	glMaterialf(GL_FRONT, GL_SHININESS, 100.0);
	glBegin(GL_LINE_LOOP);
		glVertex3f(0.25,0.5,0.0);
		glVertex3f(0.25,0.65,0.0);
		glVertex3f(0.35,0.65,0.0);
		glVertex3f(0.35,0.6,0.0);
		glVertex3f(0.25,0.6,0.0);
	glEnd();
	glBegin(GL_LINES);
		glVertex3f(0.45,0.5,0.0);
		glVertex3f(0.36,0.5,0.0);
		glVertex3f(0.36,0.5,0.0);
		glVertex3f(0.36,0.65,0.0);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex3f(0.47,0.6,0.0);
		glVertex3f(0.47,0.65,0.0);
		glVertex3f(0.56,0.65,0.0);
		glVertex3f(0.56,0.6,0.0);
	glEnd();
	glBegin(GL_LINES);
		glVertex3f(0.47,0.6,0.0);
		glVertex3f(0.47,0.5,0.0);
		glVertex3f(0.56,0.6,0.0);
		glVertex3f(0.56,0.5,0.0);
		glVertex3f(0.60,0.65,0.0);
		glVertex3f(0.65,0.6,0.0);
		glVertex3f(0.65,0.6,0.0);
		glVertex3f(0.70,0.65,0.0);
		glVertex3f(0.65,0.6,0.0);
		glVertex3f(0.65,0.5,0.0);
		glVertex3f(0.25,0.12,0.0);
		glVertex3f(0.25,0.28,0.0);
		glVertex3f(0.25,0.12,0.0);
		glVertex3f(0.35,0.12,0.0);
		glVertex3f(0.25,0.2,0.0);
		glVertex3f(0.35,0.2,0.0);
		glVertex3f(0.25,0.28,0.0);
		glVertex3f(0.35,0.28,0.0);
		glVertex3f(0.36,0.28,0.0);
		glVertex3f(0.46,0.12,0.0);
		glVertex3f(0.36,0.12,0.0);
		glVertex3f(0.46,0.28,0.0);
		glVertex3f(0.47,0.12,0);
		glVertex3f(0.57,0.12,0);
		glVertex3f(0.47,0.28,0);
		glVertex3f(0.57,0.28,0);
		glVertex3f(0.52,0.12,0);
		glVertex3f(0.52,0.28,0);
		glVertex3f(0.58,0.28,0.0);
		glVertex3f(0.68,0.28,0.0);
		glVertex3f(0.63,0.12,0.0);
		glVertex3f(0.63,0.28,0.0);
	glEnd();
	glutSwapBuffers();
	glutPostRedisplay();
}