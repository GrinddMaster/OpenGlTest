#include <stdio.h>
#include <GL/glut.h>
#include <math.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <ctime> 

void PrintSome(char* str, int x, int y) {
    glColor3f(1, 1.0, 1.0);
    glRasterPos2d(x, y);
    for (int i = 0; i < strlen(str); i++) { glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str[i]); }
    glFlush();
}
time_t startTime;
void initTimer() {
    startTime = time(NULL);
}void displayTimer() {
    // Calculate elapsed time by subtracting current time from start time
    time_t currentTime = time(NULL);
    int elapsedTime = difftime(currentTime, startTime);

    // Convert elapsed time to minutes and seconds
    int minutes = elapsedTime / 60;
    int seconds = elapsedTime % 60;

   
    char timerString[50];
    sprintf(timerString, "Time: %02d:%02d", minutes, seconds);

    
    PrintSome(timerString, 65, 96); 
}
struct River {
    int startX = 0; 
    int endX = 0;   
    int y = 0;      

    
    void SetRiver(int start, int end, int yPos) {
        startX = start;
        endX = end;
        y = yPos;
    }

    
    void DrawRiver() {
        glColor3f(0.0, 0.0, 1.0); 
        glBegin(GL_POLYGON);
        glVertex2f(startX, y);
        glVertex2f(endX, y);
        glVertex2f(endX, y + 10); 
        glVertex2f(startX, y + 10);
        glEnd();
    }
};

struct riverSides {
    int startX = 0; 
    int endX = 0;   
    int y = 0;      

    
    void SetRiverSides(int start, int end, int yPos) {
        startX = start;
        endX = end;
        y = yPos;
    }

    
    void DrawRiverSides() {
        glColor3f(0.5,0.4,0.5); 
        glBegin(GL_POLYGON);
        glVertex2f(startX, y);
        glVertex2f(endX, y);
        glVertex2f(endX, y + 2); 
        glVertex2f(startX, y + 2);
        glEnd();
    }
};
struct Boat {
    
    int posX;
    int posY;
    int width;
    int length;

    
    void SetBoat(int x, int y, int w, int l) {
        posX = x;
        posY = y;
        width = w;
        length = l;
    }

   
    void DrawBoat() {
        glColor3f(0.6, 0.3, 0.0); 
        glBegin(GL_POLYGON);
       
        glVertex2f(posX, posY);
        glVertex2f(posX + width, posY);
        glVertex2f(posX + width, posY + length);
        glVertex2f(posX, posY + length);
        glEnd();
        glColor3f(0, 0, 0); 
      glBegin(GL_LINES);
    glVertex2f(46,61);
    glVertex2f(56,61);


    glVertex2f(46,62);
    glVertex2f(56,62);


    glVertex2f(46,63);
    glVertex2f(56,63);

    glVertex2f(46,64);
    glVertex2f(56,64);

    glVertex2f(46,65);
    glVertex2f(56,65);
glEnd();

    }
};

River river;
riverSides r1;
Boat boat;

void CreateRiver()
{

    river.SetRiver(0, 100, 59); 
    river.DrawRiver();

    r1.SetRiverSides(0, 100, 68); 
    r1.DrawRiverSides();
    r1.SetRiverSides(0, 100, 57); 
    r1.DrawRiverSides();

 boat.SetBoat(46, 60, 10, 6); 
    boat.DrawBoat();

   
}