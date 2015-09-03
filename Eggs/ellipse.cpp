#include "cg_project.h"
extern GLdouble width,height,ycord_first,ycord_second,ycord_third,xcord_first,xcord_second,xcord_third,deltax_first,deltax_second,deltax_third,velocity;
extern GLdouble eggcentrex,eggcentrey,egginbasketnumber,g,ellipsecordx,ellipsecordy,eggcentrexnext,eggcentreynext,delta;
extern float Pi;
extern bool flag;
void ellipse(float x, float y, float a, float b) {
	//glClear(GL_COLOR_BUFFER_BIT);
	
	glPointSize(1.0);
	glBegin(GL_TRIANGLE_FAN);
	glClearColor(0.0, 0.0,0.0,0.0);
	// glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0); 
	GLfloat qaBlack[] = {0.0, 0.0, 0.0, 1.0};
	GLfloat qaEGG[] = {240.0/255.0, 234.0/255.0, 214.0/255.0, 1.0};
	GLfloat qaWhite[] = {1.0, 1.0, 1.0, 1.0};
	GLfloat qaBrown[] = {102.0/255.0, 51.0/255.0, 0.0};
	glMaterialfv(GL_FRONT, GL_AMBIENT, qaEGG);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, qaEGG);
	glMaterialfv(GL_FRONT, GL_SPECULAR, qaWhite);
	glMaterialf(GL_FRONT, GL_SHININESS, 100.0);
	glVertex3f(x, y, -0.2);
	for(int i = 0; i <= 360; ++i) {
		glVertex3f((x + a * cos(i*Pi/180)), (y + b * sin(i*Pi/180)), -0.2);
		//printf("%f %f\n", x + a * cos(i*Pi/180.0), y + b * sin(i*Pi/180.0));
	}
	glEnd();
	
}
