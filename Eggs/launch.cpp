#include "cg_project.h"
extern GLdouble width,height,ycord_first,ycord_second,ycord_third,xcord_first,xcord_second,xcord_third,deltax_first,deltax_second,deltax_third,velocity;
extern GLdouble eggcentrex,eggcentrey,egginbasketnumber,g,ellipsecordx,ellipsecordy,eggcentrexnext,eggcentreynext,delta,cross_count;
extern float Pi;
extern bool flag;
void launch()
{
	ellipsecordy+=velocity;
	velocity-=g;
	
	if(ellipsecordy>=eggcentreynext)
		cross_count=1;
	if(ellipsecordy<=eggcentreynext && cross_count==1)
		cross_count=2;

	if((abs(ellipsecordx - eggcentrexnext) <= delta) && (abs(ellipsecordy -eggcentreynext)<=delta) && cross_count==2)
	{
		cross_count=0;
		flag=false;
		velocity=0.085;
		egginbasketnumber=((int)(egginbasketnumber)%3)+1;
	}
	if(ellipsecordy<=0.001)
	{
		cross_count=0;
		flag=false;
		velocity=0.085;
		egginbasketnumber=1;
	}
}
