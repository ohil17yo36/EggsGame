#include <GL/glut.h>
#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<stdio.h>
#define VEL 0.04
#define initiallife 12
using namespace std;

void Initialize();
void reshape(int w,int h);
void Draw();
void DrawBucket(GLdouble xcord,GLdouble ycord);
void ellipse(float x, float y, float a, float b);
void mouse(int button,int state,int x,int y);
void launch();
void Idle();
void Background();
void decrement();
void addToBasket(int);
void changeSpeed();
void DrawNum(int num,GLdouble cordx,GLdouble cordy);
void DrawDigit(int num,GLdouble cordx,GLdouble cordy);
void GameOver();