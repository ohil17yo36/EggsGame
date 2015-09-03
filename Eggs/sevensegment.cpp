#include "cg_project.h"
#include <stdio.h>
extern GLdouble width,height,ycord_first,ycord_second,ycord_third,xcord_first,xcord_second,xcord_third,deltax_first,deltax_second,deltax_third,velocity;
extern GLdouble eggcentrex,eggcentrey,egginbasketnumber,g,ellipsecordx,ellipsecordy,eggcentrexnext,eggcentreynext,delta;
extern float Pi;
extern bool flag,slideFlag;
extern int basketBelow,basketAbove,life,points;

void DrawDigit(int num,GLdouble cordx,GLdouble cordy)
{	
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0,0.0,0.0,1.0);
	glColor3f(0.0,1.0,0.0);
	glLineWidth(4.0);
	GLfloat qaWhite[] = {1.0, 1.0, 1.0, 1.0};
	GLfloat qaGreen[]=	{0.0, 1.0, 0.0, 1.0};
	glMaterialfv(GL_FRONT, GL_AMBIENT, qaGreen);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, qaGreen);
	glMaterialfv(GL_FRONT, GL_SPECULAR, qaWhite);
	glMaterialf(GL_FRONT, GL_SHININESS, 100.0);
	switch(num)
	{
		case 0:	
				glBegin(GL_LINE_LOOP);
				glVertex3f(cordx,cordy,-0.3);
				glVertex3f(cordx,cordy+0.04,-0.3);
				glVertex3f(cordx+0.04,cordy+0.04,-0.3);
				glVertex3f(cordx+0.04,cordy,-0.3);
				glEnd();
				break;
				
		case 1:	
				glBegin(GL_LINES);
				glVertex3f(cordx+0.04,cordy,-0.3);
				glVertex3f(cordx+0.04,cordy+0.04,-0.3);
				glEnd();
				//glutSwapBuffers();
				break;

		case 2: 
				glBegin(GL_LINE_STRIP);
				glVertex3f(cordx,cordy+0.04,-0.3);
				glVertex3f(cordx+0.04,cordy+0.04,-0.3);
				glVertex3f(cordx+0.04,cordy+0.02,-0.3);
				glVertex3f(cordx,cordy+0.02,-0.3);
				glVertex3f(cordx,cordy,-0.3);
				glVertex3f(cordx+0.04,cordy,-0.3);
				glEnd();
				//glutSwapBuffers();
				break;
		case 3:	
				glBegin(GL_LINES);
				glVertex3f(cordx+0.04,cordy,-0.3);
				glVertex3f(cordx+0.04,cordy+0.04,-0.3);
				glVertex3f(cordx,cordy+0.04,-0.3);
				glVertex3f(cordx+0.04,cordy+0.04,-0.3);
				glVertex3f(cordx,cordy,-0.3);
				glVertex3f(cordx+0.04,cordy,-0.3);
				glVertex3f(cordx,cordy+0.02,-0.3);
				glVertex3f(cordx+0.04,cordy+0.02,-0.3);
				glEnd();
				//glutSwapBuffers();
				break;
		case 4:
				glBegin(GL_LINE_STRIP);
				glVertex3f(cordx,cordy+0.04,-0.3);
				glVertex3f(cordx,cordy+0.02,-0.3);
				glVertex3f(cordx+0.04,cordy+0.02,-0.3);
				glVertex3f(cordx+0.04,cordy+0.04,-0.3);
				glEnd();
				glBegin(GL_LINES);
				glVertex3f(cordx+0.04,cordy+0.02,-0.3);
				glVertex3f(cordx+0.04,cordy,-0.3);
				glEnd();
				//glutSwapBuffers();
				break;
		case 5:
				glBegin(GL_LINE_STRIP);
				glVertex3f(cordx+0.04,cordy+0.04,-0.3);
				glVertex3f(cordx,cordy+0.04,-0.3);
				glVertex3f(cordx,cordy+0.02,-0.3);
				glVertex3f(cordx+0.04,cordy+0.02,-0.3);
				glVertex3f(cordx+0.04,cordy,-0.3);
				glVertex3f(cordx,cordy,-0.3);
				glEnd();
				//glutSwapBuffers();
				break;
		case 6:
				glBegin(GL_LINE_STRIP);										
				glVertex3f(cordx+0.04,cordy+0.04,-0.3);
				glVertex3f(cordx,cordy+0.04,-0.3);
				glVertex3f(cordx,cordy+0.02,-0.3);
				glEnd();
				glBegin(GL_LINE_LOOP);
				glVertex3f(cordx,cordy+0.02,-0.3);
				glVertex3f(cordx,cordy,-0.3);
				glVertex3f(cordx+0.04,cordy,-0.3);
				glVertex3f(cordx+0.04,cordy+0.02,-0.3);
				glEnd();
				//glutSwapBuffers();
				break;
		case 7:
				glBegin(GL_LINE_STRIP);
				glVertex3f(cordx,cordy+0.04,-0.3);
				glVertex3f(cordx+0.04,cordy+0.04,-0.3);
				glVertex3f(cordx+0.04,cordy,-0.3);
				glEnd();
				//glutSwapBuffers();
				break;
		case 8:
				glBegin(GL_LINE_LOOP);
				glVertex3f(cordx,cordy,-0.3);
				glVertex3f(cordx,cordy+0.04,-0.3);
				glVertex3f(cordx+0.04,cordy+0.04,-0.3);
				glVertex3f(cordx+0.04,cordy,-0.3);
				glEnd();
				glBegin(GL_LINES);
				glVertex3f(cordx,cordy+0.02,-0.3);
				glVertex3f(cordx+0.04,cordy+0.02,-0.3);
				glEnd();				
				//glutSwapBuffers();
				break;
		case 9:
				glBegin(GL_LINE_LOOP);
				glVertex3f(cordx,cordy+0.04,-0.3);
				glVertex3f(cordx+0.04,cordy+0.04,-0.3);
				glVertex3f(cordx+0.04,cordy+0.02,-0.3);
				glVertex3f(cordx,cordy+0.02,-0.3);
				glEnd();
				glBegin(GL_LINE_STRIP);
				glVertex3f(cordx+0.04,cordy+0.02,-0.3);
				glVertex3f(cordx+0.04,cordy,-0.3);
				glVertex3f(cordx,cordy,-0.3);
				glEnd();
				//glutSwapBuffers();
				break;			
	}		
	glLineWidth(1.0);
}

void DrawNum(int num,GLdouble cordx,GLdouble cordy)
{
	int num_of_digits=0,temp=num,digit;
	if(num==0)
	{
		DrawDigit(0,cordx,cordy);
		return ;
	}
	while(temp!=0)
	{
		num_of_digits++;
		temp/=10;
	}
	temp=num;
	while(num_of_digits>0)
	{
		digit=(temp/(int)(pow(10,num_of_digits-1)));
		temp=temp%((int)pow(10,num_of_digits-1));
		num_of_digits--;
		DrawDigit(digit,cordx,cordy);
		cordx+=0.05;	
	}
	
}

