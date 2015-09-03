#include "cg_project.h"
extern GLdouble width,height,ycord_first,ycord_second,ycord_third,xcord_first,xcord_second,xcord_third,deltax_first,deltax_second,deltax_third,velocity;
extern GLdouble eggcentrex,eggcentrey,egginbasketnumber,g,ellipsecordx,ellipsecordy,eggcentrexnext,eggcentreynext,delta;
extern float Pi;
extern bool flag;
 struct star {
    float x, y;
    float vx, vy;
};
extern struct star stars[150];


void Background(void)
{
    int i;     
    for (i = 0; i < 100; i++) 
    {
		stars[i].x += stars[i].vx;
		if (stars[i].x < glutGet(GLUT_WINDOW_WIDTH)) 
		{
	    	glBegin(GL_LINE_STRIP);
	    	GLfloat qaWhite[] = {1.0, 1.0, 1.0, 1.0};
	    	glMaterialfv(GL_FRONT, GL_AMBIENT, qaWhite);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, qaWhite);
			glMaterialfv(GL_FRONT, GL_SPECULAR, qaWhite);
			glMaterialf(GL_FRONT, GL_SHININESS, 100.0);

	    	glColor3f(0, 0, 0);
	    	glVertex3f((stars[i].x-stars[i].vx*4)/width, (stars[i].y)/height, -0.5);
	    	glColor3f(1.0, 1.0, 1.0);
	    	glVertex3f((stars[i].x)/width, (stars[i].y)/height, -0.5);
	    	glEnd();
        } 
		else
	    stars[i].x = 0;
    }
}
