
#include <GL/glut.h>
#include "cg_project.h"
#define VEL 0.04
using namespace std;

GLdouble width=768,height=768,ycord_first=0.05,ycord_second=0.45,ycord_third=0.85,xcord_first=0.49,xcord_second=0.23,xcord_third=0.79,deltax_first=0.005,deltax_second=0.003,deltax_third=0.004;
GLdouble eggcentrex=xcord_first+0.03,eggcentrey=ycord_first+0.045,egginbasketnumber=1,velocity=VEL,g=0.0018,eggcentrexnext,eggcentreynext,delta=0.025,cross_count;
GLdouble ellipsecordx=xcord_first+0.03,ellipsecordy=0.08+0.0045;
float Pi = 3.14159265358979323846264338327952;
bool flag=false,slideFlag=false,gameoverflag=true;
int basketBelow=1,basketAbove=3,life=initiallife,points=0;
struct star {
    float x, y;
    float vx, vy;
} ;
struct star stars[150];

int main(int iArgc, char** cppArgv) {

        for (int i = 0; i < 150; i++) {
	stars[i].x = rand() % 768;
	stars[i].y = rand() % 768;
	stars[i].vx = rand() / (float)RAND_MAX * 5 + 2;
	stars[i].vy = 0;
    }
	glutInit(&iArgc, cppArgv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(width, height);
	glutInitWindowPosition(20, 20);
	glutCreateWindow("CG_project");
	Initialize();
	
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutDisplayFunc(Draw);
    glutIdleFunc(Idle);
	glutMainLoop();
	return 0;
}
