#include <stdio.h> 
#include <GL/glut.h> 
#include <math.h> 
#include <string.h>
#include <unistd.h>
#include <iostream>

int phyWidth = 700;
int phyHeight = 700;
int logWidth = 100;
int logHeight = 100;
int centerX = logWidth / 2;
int centerY = logHeight / 2;
int alphaX,alphaY = 0;

void DrawCircle(float cx, float cy, float r, int num_segments) {
glBegin(GL_POLYGON);
for (int i = 0; i < num_segments; i++) {
float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);//get the current angle
float x = r * cosf(theta);//calculate the x component
float y = r * sinf(theta);//calculate the y component
glVertex2f(x + cx, y + cy);//output vertex
}
glEnd();
}

void CreateCharacter(double r, double g, double b)
{
glColor3f(r, g, b);
glBegin(GL_POLYGON);
glVertex2f((centerX)-10/2+alphaX,(centerY-45)-7.5/2+alphaY);//Bottom Left Corner
glVertex2f((centerX)+10/2+alphaX,(centerY-45)-7.5/2+alphaY);//Bottom Right corner
glVertex2f((centerX)+10/2+alphaX,(centerY-45)+7.5/2+alphaY);//Top Right corner
glVertex2f((centerX)-10/2+alphaX,(centerY-45)+7.5/2+alphaY);//Top left corner
glEnd();
glColor3f(0, 0.5, 0.5);
DrawCircle((centerX), (centerY-45), 5, 100);

glColor3f(0.5, 1, 0.5);
DrawCircle((centerX), (centerY-45), 1.5, 6);
glColor3f(0.5, 1, 0.5);
DrawCircle((centerX+3), (centerY-43), 1.5, 6);

glColor3f(0.5, 1, 0.5);
DrawCircle((centerX-3), (centerY-43.5), 1.5, 6);

glColor3f(0.5, 1, 0.5);
DrawCircle((centerX), (centerY-42), 1.5, 6);

glColor3f(0.5, 1, 0.5);
DrawCircle((centerX), (centerY-48), 1.5, 6);

glColor3f(0.5, 1, 0.5);
DrawCircle((centerX+2.9), (centerY-46.5), 1.5, 6);

glColor3f(0.5, 1, 0.5);
DrawCircle((centerX-2.9), (centerY-46.5), 1.5, 6);


glColor3f(0.5, 1, 0.5);
DrawCircle((centerX), (centerY-40), 1.5, 100);
}











