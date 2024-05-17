#include <stdio.h> 
#include <GL/glut.h> 
#include <math.h> 
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <ctime> // Include for time functions
int phyWidth1 = 700;
int phyHeight1 = 700;
int logWidth1 = 100;
int logHeight1 = 100;
int centX = logWidth1 / 2;
int centY = logHeight1 / 2;

using namespace std;

#define pi 3.142857 

void DrawACircle(float cx, float cy, float r, int num_segments) {
glBegin(GL_POLYGON);
for (int i = 0; i < num_segments; i++) {
float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);//get the current angle
float x = r * cosf(theta);//calculate the x component
float y = r * sinf(theta);//calculate the y component
glVertex2f(x + cx, y + cy);//output vertex
}
glEnd();
}

struct Car{


void CarWheels(int IncXPos)
{
    glColor3f(0.0,0.0,0.0);
    DrawACircle(50+IncXPos,50,2,100);
    DrawACircle(50+IncXPos,50,2,100);
    glColor3f(0.5,0.5,0.5);
    DrawACircle(50+IncXPos,50,1,100);
    DrawACircle(50+IncXPos,50,1,100);
    glColor3f(0.0,0.0,0.0);
    DrawACircle(60+IncXPos,50,2,100);
    DrawACircle(60+IncXPos,50,2,100);
    glColor3f(0.5,0.5,0.5);
    DrawACircle(60+IncXPos,50,1,100);
    DrawACircle(60+IncXPos,50,1,100);
}
void CarHood(int IncXPos)
{
 
glBegin(GL_POLYGON);
glVertex2f((centX+8)-20/2,(centY+5)-10/2);//Bottom Left Corner
glVertex2f((centX+8)+15/2,(centY+5)-10/2);//Bottom Right corner
glVertex2f((centX+8)+15/2,(centY+5)+10/2);//Top Right corner
glVertex2f((centX+8)-20/2,(centY+5)+10/2);//Top left corner
glEnd();
}



};

Car c1;

void PrintAWord(char *str,int x,int y) {
	
glColor3f (1, 1.0, 1.0);
glRasterPos2d(x,y);
for (int i=0;i<strlen(str);i++){glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str[i]);}
glFlush();
}







void init2D(void) {
    glClearColor(0, 0.7, 0.0, 0.0); // making background color black as first 3 arguments all are 0.0 
    glColor3f(0.0, 0.0, 0.5); // making picture color green (in RGB mode), as middle argument is 1.0 
    glPointSize(2.0); // breadth of picture boundary is 1 pixel 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, logWidth1, 0.0, logHeight1); // setting window dimension in X- and Y- direction 
}





void Display(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    c1.CarHood(1);
    c1.CarWheels(1);
    


    

    glutSwapBuffers();
    glFlush();
}//g++ CarShape.cpp -o SCarShape -lglut -lGLU -lGL

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(650, 100);
    glutInitWindowSize(phyWidth1, phyHeight1);
    glutCreateWindow("CarShape");
    init2D();

   
    glutDisplayFunc(Display);
    glutMainLoop();
    return 0;
}