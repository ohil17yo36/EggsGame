#include "GL/glut.h"

extern GLdouble width,height,ycord_first,ycord_second,ycord_third,xcord_first,xcord_second,xcord_third,deltax_first,deltax_second,deltax_third,velocity;
extern GLdouble eggcentrex,eggcentrey,egginbasketnumber,g,ellipsecordx,ellipsecordy,eggcentrexnext,eggcentreynext,delta;
extern float Pi;
extern bool flag,slideFlag;
extern int basketBelow,basketAbove;

void addToBasket(int basket)
{
 if(basket==1)
 {
  eggcentrex=xcord_first+0.03;
  eggcentrey=ycord_first+0.045;
 }
 if(basket==2)
 {
  eggcentrex=xcord_second+0.03;
  eggcentrey=ycord_second+0.045;
 }
 if(basket==3)
 {
  eggcentrex=xcord_third+0.03;
  eggcentrey=ycord_third+0.045;
 }
}
