#include "cg_project.h"
#include<stdio.h>
extern GLdouble width,height,ycord_first,ycord_second,ycord_third,xcord_first,xcord_second,xcord_third,deltax_first,deltax_second,deltax_third,velocity;
extern GLdouble eggcentrex,eggcentrey,egginbasketnumber,g,ellipsecordx,ellipsecordy,eggcentrexnext,eggcentreynext,delta;
extern float Pi;
extern bool flag,slideFlag,gameoverflag;
extern int basketBelow,basketAbove,life,points;
void Draw() 
{	

    
    if(gameoverflag==true)
      GameOver();
  else
  { 
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);   
    Background();
	
	if(xcord_first+0.06>=1.0 || xcord_first<=0.0)
		deltax_first=-deltax_first;
	xcord_first+=deltax_first;
	if(xcord_second+0.06>=1.0 || xcord_second<=0.0)
		deltax_second=-deltax_second;
	xcord_second+=deltax_second;
	if(xcord_third+0.06>=1.0 || xcord_third<=0.0)
		deltax_third=-deltax_third;
	xcord_third+=deltax_third;
	
	if(slideFlag==true)
	  decrement();
	
  DrawBucket(xcord_first,ycord_first);
	DrawBucket(xcord_second,ycord_second);
	DrawBucket(xcord_third,ycord_third);
	
	if(egginbasketnumber==1)
	{
		eggcentrex=xcord_first+0.03;
		if(flag==true)
		{
         eggcentrey+=velocity;
         velocity-=g;
        }
	}
	else if(egginbasketnumber==2) 
	{
		eggcentrex=xcord_second+0.03;
		if(flag==true)
		{
         eggcentrey+=velocity;
         velocity-=g;
        }
	}
	else
	{
		eggcentrex=xcord_third+0.03;
 	    if(flag==true)
        {
         eggcentrey+=velocity;
         velocity-=g;
        }
	}               
                     	
	if(flag==true)
	{
    if(velocity<0 && eggcentrex>=(xcord_first+0.01) && eggcentrex<=(xcord_first+0.05) && eggcentrey>=(ycord_first+0.06) && eggcentrey<=(ycord_first+0.08))
    {
       if(egginbasketnumber==1)
       life--;
       else
       points++;           
       egginbasketnumber=1;
       eggcentrex=xcord_first+0.03;
       eggcentrey=ycord_first+0.045;
       velocity=VEL;
       flag=false;
    }
    if(velocity<0 && eggcentrex>=(xcord_second +0.01)&& eggcentrex<=(xcord_second+0.05) && eggcentrey>=(ycord_second+0.06) && eggcentrey<=(ycord_second+0.08))
    {
        if(egginbasketnumber==2)
       life--;          
       else
       points++;
       egginbasketnumber=2;
       eggcentrex=xcord_second+0.03;
       eggcentrey=ycord_second+0.045;
       velocity=VEL;
       flag=false;
    }
    if(velocity<0 && eggcentrex>=(xcord_third+0.01) && eggcentrex<=(xcord_third+0.05) && eggcentrey>=(ycord_third+0.06) && eggcentrey<=(ycord_third+0.08))
    {
       if(egginbasketnumber==3)
       life--;
       else
       points++;
       egginbasketnumber=3;
       eggcentrex=xcord_third+0.03;
       eggcentrey=ycord_third+0.045;
       velocity=VEL;
       flag=false;
    }
    if(eggcentrey<0.05)
    {

      addToBasket(basketBelow);
      velocity=VEL;
      flag=false;
    }
    }
       
    ellipse(eggcentrex, eggcentrey, 0.015, 0.025);
    DrawNum(life,0.025,0.95);
    DrawNum(points,0.87,0.95);
    if(life==0)
    { 
      printf("Game Over and u have scored %d points\n",points);
      gameoverflag=true;
    }
    if(egginbasketnumber==basketAbove)
      slideFlag=true;
    glutSwapBuffers();
	glutPostRedisplay();
  }
}
