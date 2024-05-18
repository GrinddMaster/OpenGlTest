#include <stdio.h> 
#include <GL/glut.h> 
#include <math.h> 
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <ctime> // Include for time functions
//g++ CarShape.cpp -o SCarShape -lglut -lGLU -lGL
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


int vx1 = centX-12/2-20,vx2=centX+12/2-20,vx3=centX+12/2-20,vx4=centX-12/2-20; // X vertices
    int vy1 = centY-12/2,vy2=centY-12/2,vy3=centY+12/2,vy4=centY+12/2; // Y vertices

void CarWheels(int IncXPos)
{
    glColor3f(0.0,0.0,0.0);
    DrawACircle(vx1+IncXPos,vy1,2,100);
    DrawACircle(vx1+IncXPos,vy1,2,100);
    glColor3f(0.5,0.5,0.5);
    DrawACircle(vx1+IncXPos,vy1,1,100);
    DrawACircle(vx1+IncXPos,vy1,1,100);
    glColor3f(0.0,0.0,0.0);
    DrawACircle(vx2+IncXPos,vy1,2,100);
    DrawACircle(vx2+IncXPos,vy1,2,100);
    glColor3f(0.5,0.5,0.5);
    DrawACircle(vx2+IncXPos,vy1,1,100);
    DrawACircle(vx2+IncXPos,vy1,1,100);
}
void CarHood(int IncXPos)
{
 glColor3f(1,1,1);
 glBegin(GL_POLYGON);
glVertex2f(vx1-3+IncXPos,vy1);//Bottom Left Corner
glVertex2f(vx2+IncXPos,vy2);//Bottom Right corner
glVertex2f(vx3-2+IncXPos,vy3-1);//Top Right corner
glVertex2f(vx4-2+IncXPos,vy4-0.5);//Top left corner
glEnd();
glColor3f(0.5,0,1);
glBegin(GL_POLYGON);
glVertex2f(vx1-3+IncXPos,vy1);//Bottom Left Corner
glVertex2f(vx2+3+IncXPos,vy2);//Bottom Right corner
glVertex2f(vx3+3+IncXPos,vy3-5.5);//Top Right corner
glVertex2f(vx4-3+IncXPos,vy4-5.5);//Top left corner
glEnd();

}

void ChangeHorizontalPos(int x1, int x2, int x3, int x4, char z, int key) {
        if (z == '+' && key == 1) {
            vx1 += x1;
            vx2 += x2;
            vx3 += x3;
            vx4 += x4;
        }
        else if (z == '-' && key == 1) {
            vx1 -= x1;
            vx2 -= x2;
            vx3 -= x3;
            vx4 -= x4;
        }
        else {
            //Do Nothing
        }
    }
    void ChangeVerticalPos(int y1, int y2, int y3, int y4, char z,int key) {
        if (z == '+' && key == 1) {
            vy1 += y1;
            vy2 += y2;
            vy3 += y3;
            vy4 += y4;
        }
        else if (z == '-' && key == 1) {
            vy1 -= y1;
            vy2 -= y2;
            vy3 -= y3;
            vy4 -= y4;
        }
        else {
            //Do nothing
        }
    }


};

Car c1,c2,c3;

void PrintAWord(char *str,int x,int y) {
	
glColor3f (1, 1.0, 1.0);
glRasterPos2d(x,y);
for (int i=0;i<strlen(str);i++){glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str[i]);}
glFlush();
}


/*void init2D(void) {
    glClearColor(0, 0.7, 0.0, 0.0); // making background color black as first 3 arguments all are 0.0 
    glColor3f(0.0, 0.0, 0.5); // making picture color green (in RGB mode), as middle argument is 1.0 
    glPointSize(2.0); // breadth of picture boundary is 1 pixel 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, logWidth1, 0.0, logHeight1); // setting window dimension in X- and Y- direction 
}*/

void ShowCarShapes(int XPosC1,int XposC2,int XposC3)
{

    
    c1.CarHood(XPosC1);
    c1.CarWheels(XPosC1);
    c2.CarHood(XposC2);
    c2.CarWheels(XposC2);
    c3.CarHood(XposC3);
    c3.CarWheels(XposC3);
}


/*void Display(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    
    ShowCarShapes(1,1,1);

    glutSwapBuffers();
    glFlush();
}

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
}*/