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

void Idle()
{
	glutPostRedisplay();
}
void reshape(int w,int h)	
{
	width=(GLdouble)w;
	height=(GLdouble)h;
	glViewport(0,0, (GLsizei)w, (GLsizei) h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
    
    gluOrtho2D(0.0, 1.0, 0.0, 1.0);
    //glOrtho(0, w, 0, h, -1, 1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glColor3f(1.0,1.0,1.0);

}
void Initialize() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
	// Lighting set up
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);
	// Set lighting intensity and color
	GLfloat qaAmbientLight[]	= {0.2, 0.2, 0.2, 1.0};
	GLfloat qaDiffuseLight[]	= {0.8, 0.8, 0.8, 1.0};
	GLfloat qaSpecularLight[]	= {1.0, 1.0, 1.0, 1.0};
	glLightfv(GL_LIGHT0, GL_AMBIENT, qaAmbientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, qaDiffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, qaSpecularLight);
	glLightfv(GL_LIGHT1, GL_AMBIENT, qaAmbientLight);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, qaDiffuseLight);
	glLightfv(GL_LIGHT1, GL_SPECULAR, qaSpecularLight);
	glLightfv(GL_LIGHT2, GL_AMBIENT, qaAmbientLight);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, qaDiffuseLight);
	glLightfv(GL_LIGHT2, GL_SPECULAR, qaSpecularLight);
	// Set the light position
	GLfloat qaLightPosition1[]	= {xcord_first, 0.02, 0.15, 1.0};
	glLightfv(GL_LIGHT0, GL_POSITION, qaLightPosition1);
	GLfloat qaLightPosition2[]	= {xcord_second, 0.5, 0.15, 1.0};
	glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition2);
	GLfloat qaLightPosition3[]	= {xcord_third, 0.92, 0.15, 1.0};
	glLightfv(GL_LIGHT2, GL_POSITION, qaLightPosition3);
}
