#include "GL/glut.h"
//#include "cg_project.h"
#include<stdlib.h>
#include<stdio.h>

extern GLdouble width,height,ycord_first,ycord_second,ycord_third,xcord_first,xcord_second,xcord_third,deltax_first,deltax_second,deltax_third,velocity;
extern GLdouble eggcentrex,eggcentrey,egginbasketnumber,g,ellipsecordx,ellipsecordy,eggcentrexnext,eggcentreynext,delta;
extern float Pi;
extern bool flag,slideFlag;
extern int basketBelow,basketAbove;

void changeSpeed()
{
 deltax_first=((rand()%700)+100)/((GLdouble)(100000));
 deltax_second=((rand()%700)+100)/((GLdouble)(100000));
 deltax_third=((rand()%700)+100)/((GLdouble)(100000));
}

void decrement()
{
 ycord_first-=0.01;
 ycord_second-=0.01;
 ycord_third-=0.01;
 eggcentrey-=0.01;
 
 if(ycord_first<0.05 && egginbasketnumber==1)
  {
  ycord_first=0.05;
  slideFlag=false;
  basketBelow=1;
  basketAbove=3;
  ycord_second+=0.01;
  ycord_third+=0.01;
  changeSpeed();
  return;
  }
  if(ycord_second<0.05 && egginbasketnumber==2)
  {
   ycord_second=0.05;
   slideFlag=false;
   basketBelow=2;
   basketAbove=1;
   ycord_first+=0.01;
   ycord_third+=0.01;
   changeSpeed();
   return;
  }
  if(ycord_third<0.05 && egginbasketnumber==3)
  {
  ycord_third=0.05;
  slideFlag=false;
  basketBelow=3;
  basketAbove=2;
  ycord_first+=0.01;
  ycord_second+=0.01;
  changeSpeed();
  return ;
  }
  if(ycord_first <-0.34)
    ycord_first=0.85;
  if(ycord_second<-0.34)
    ycord_second=0.85;
  if(ycord_third<-0.34)
    ycord_third=0.85;
  return ;
}
