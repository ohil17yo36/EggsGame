#include "cg_project.h"
extern GLdouble width,height,ycord_first,ycord_second,ycord_third,xcord_first,xcord_second,xcord_third,deltax_first,deltax_second,deltax_third,velocity;
extern GLdouble eggcentrex,eggcentrey,egginbasketnumber,g,ellipsecordx,ellipsecordy,eggcentrexnext,eggcentreynext,delta;
extern float Pi;
extern bool flag,slideFlag,gameoverflag;
extern int life,points,basketBelow;
void mouse(int button,int state,int x,int y) 
{
	float x1=x/(float)width;
	float y1=y/(float)height;
 	if(button==GLUT_LEFT_BUTTON && state==GLUT_UP ) 
 	{
 		if(gameoverflag==true)
 		{
 		
 			if(x1>=0.2 && x1<=0.72 && (1-y1)>=0.35 && (1-y1)<=0.75)
 				{
 					egginbasketnumber=basketBelow;
 					if(basketBelow==1)
 						eggcentrey=ycord_first+0.045;
 					else if(basketBelow==2)
 						eggcentrey=ycord_second+0.045;
 					else
 						eggcentrey=ycord_third+0.045;
 					gameoverflag=false;
 					life=initiallife;
 					points=0;
  				}
 		
 			if(x1>=0.2 && x1<=0.72 && (1-y1)>=0.1 && (1-y1)<=0.3)
 			exit(0);
 			
 		}
 		else
 		{
 			if(slideFlag==false)
 			flag=true;
 		}
	}
}
