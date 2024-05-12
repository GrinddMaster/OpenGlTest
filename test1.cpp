#include <stdio.h> 
#include <GL/glut.h> 
#include <math.h> 
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <ctime> // Include for time functions

using namespace std;

#define pi 3.142857 

int phyWidth = 700;
int phyHeight = 700;
int logWidth = 100;
int logHeight = 100;
int centerX = logWidth / 2;
int centerY = logHeight / 2;

struct Road {
    int W = 12;
    int H = 12;

    int vx1 = centerX - W / 2, vx2 = centerX + W / 2, vx3 = centerX + W / 2, vx4 = centerX - W / 2; // X vertices
    int vy1 = centerY - H / 2, vy2 = centerY - H / 2, vy3 = centerY + H / 2, vy4 = centerY + H / 2; // Y vertices

    void CreateRoad(double r, double g, double b) {
        glColor3f(r, g, b);
        glBegin(GL_POLYGON);
        glVertex2f(vx1, vy1); //Bottom left corner
        glVertex2f(vx2, vy2); //Bottom right corner
        glVertex2f(vx3, vy3); //Top Right corner
        glVertex2f(vx4, vy4); //Bottom Right corner
        glEnd();
    }

    void ChangeHorizontalPos(int x1, int x2, int x3, int x4, char z) {
        if (z == '+') {
            vx1 += x1;
            vx2 += x2;
            vx3 += x3;
            vx4 += x4;
        }
        else if (z == '-') {
            vx1 -= x1;
            vx2 -= x2;
            vx3 -= x3;
            vx4 -= x4;
        }
        else {
            //Do Nothing
        }
    }

    void ChangeVerticalPos(int y1, int y2, int y3, int y4, char z) {
        if (z == '+') {
            vy1 += y1;
            vy2 += y2;
            vy3 += y3;
            vy4 += y4;
        }
        else if (z == '-') {
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

struct RoadStrips {
    int vx1 = centerX - 5 / 2, vx2 = centerX + 10 / 2, vx3 = centerX + 10 / 2, vx4 = centerX - 5 / 2; // X vertices
    int vy1 = centerY - 3.2 / 2, vy2 = centerY - 3.2 / 2, vy3 = centerY + 3.2 / 2, vy4 = centerY + 3.2 / 2; // Y vertices

    void BuildRoadStrips(int r, int g, int b) {
        glColor3f(r, g, b);
        glBegin(GL_POLYGON);
        glVertex2f(vx1, vy1); //Bottom Left Corner
        glVertex2f(vx2, vy2); //Bottom Right corner
        glVertex2f(vx3, vy3); //Top Right corner
        glVertex2f(vx4, vy4); //Top left corner
        glEnd();
        glColor3f(r, g, b);
        glBegin(GL_POLYGON);
        glVertex2f(vx1 + 20, vy1); //Bottom Left Corner
        glVertex2f(vx2 + 20, vy2); //Bottom Right corner
        glVertex2f(vx3 + 20, vy3); //Top Right corner
        glVertex2f(vx4 + 20, vy4); //Top left corner
        glEnd();
        glColor3f(r, g, b);
        glBegin(GL_POLYGON);
        glVertex2f(vx1 + 40, vy1); //Bottom Left Corner
        glVertex2f(vx2 + 40, vy2); //Bottom Right corner
        glVertex2f(vx3 + 40, vy3); //Top Right corner
        glVertex2f(vx4 + 40, vy4); //Top left corner
        glEnd();
        glColor3f(r, g, b);
        glBegin(GL_POLYGON);
        glVertex2f(vx1 - 20, vy1); //Bottom Left Corner
        glVertex2f(vx2 - 20, vy2); //Bottom Right corner
        glVertex2f(vx3 - 20, vy3); //Top Right corner
        glVertex2f(vx4 - 20, vy4); //Top left corner
        glEnd();
        glColor3f(r, g, b);
        glBegin(GL_POLYGON);
        glVertex2f(vx1 - 40, vy1); //Bottom Left Corner
        glVertex2f(vx2 - 40, vy2); //Bottom Right corner
        glVertex2f(vx3 - 40, vy3); //Top Right corner
        glVertex2f(vx4 - 40, vy4); //Top left corner
        glEnd();
        glColor3f(r, g, b);
    }

    void ChangeHorizontalPos(int x1, int x2, int x3, int x4, char z) {
        if (z == '+') {
            vx1 += x1;
            vx2 += x2;
            vx3 += x3;
            vx4 += x4;
        }
        else if (z == '-') {
            vx1 -= x1;
            vx2 -= x2;
            vx3 -= x3;
            vx4 -= x4;
        }
        else {
            //Do Nothing
        }
    }

    void ChangeVerticalPos(int y1, int y2, int y3, int y4, char z) {
        if (z == '+') {
            vy1 += y1;
            vy2 += y2;
            vy3 += y3;
            vy4 += y4;
        }
        else if (z == '-') {
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

void printSome(char* str, int x, int y) {

    glColor3f(1, 1.0, 1.0);
    glRasterPos2d(x, y);
    for (int i = 0; i < strlen(str); i++) { glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str[i]); }
    glFlush();
}

void init2D(void) {
    glClearColor(0, 0.7, 0.0, 0.0); // making background color black as first 3 arguments all are 0.0 
    glColor3f(0.0, 0.0, 0.5); // making picture color green (in RGB mode), as middle argument is 1.0 
    glPointSize(2.0); // breadth of picture boundary is 1 pixel 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, logWidth, 0.0, logHeight); // setting window dimension in X- and Y- direction 
}

Road rd1, rd2, rd3;
RoadStrips rs1, rs2, rs3;

void Road1(int Width, int Height) {
    rd1.W = Width;
    rd1.H = Height;
    rd1.vx1 = centerX - rd1.W / 2;
    rd1.vx2 = centerX + rd1.W / 2;
    rd1.vx3 = centerX + rd1.W / 2;
    rd1.vx4 = centerX - rd1.W / 2;
    rd1.vy1 = centerY - rd1.H / 2;
    rd1.vy2 = centerY - rd1.H / 2;
    rd1.vy3 = centerY + rd1.H / 2;
    rd1.vy4 = centerY + rd1.H / 2;
}

void Road2(int Width, int Height) {
    rd2.W = Width;
    rd2.H = Height;
    rd2.vx1 = centerX - rd2.W / 2;
    rd2.vx2 = centerX + rd2.W / 2;
    rd2.vx3 = centerX + rd2.W / 2;
    rd2.vx4 = centerX - rd2.W / 2;
    rd2.vy1 = centerY - rd2.H / 2;
    rd2.vy2 = centerY - rd2.H / 2;
    rd2.vy3 = centerY + rd2.H / 2;
    rd2.vy4 = centerY + rd2.H / 2;
}

void Road3(int Width, int Height) {
    rd3.W = Width;
    rd3.H = Height;
    rd3.vx1 = centerX - rd3.W / 2;
    rd3.vx2 = centerX + rd3.W / 2;
    rd3.vx3 = centerX + rd3.W / 2;
    rd3.vx4 = centerX - rd3.W / 2;
    rd3.vy1 = centerY - rd3.H / 2;
    rd3.vy2 = centerY - rd3.H / 2;
    rd3.vy3 = centerY + rd3.H / 2;
    rd3.vy4 = centerY + rd3.H / 2;
}

// Global variable to store starting time
time_t startTime;

// Function to initialize the timer
void initTimer() {
    startTime = time(NULL); // Get the current time and store it as the start time
}

// Function to calculate and display elapsed time
void displayTimer() {
    // Calculate elapsed time by subtracting current time from start time
    time_t currentTime = time(NULL);
    int elapsedTime = difftime(currentTime, startTime);

    // Convert elapsed time to minutes and seconds
    int minutes = elapsedTime / 60;
    int seconds = elapsedTime % 60;

    // Convert minutes and seconds to string format
    char timerString[50];
    sprintf(timerString, "Time: %02d:%02d", minutes, seconds);

    // Display the timer string on the screen
    printSome(timerString, 10, 10); // Assuming (10, 10) is the desired position to display the timer
}

void Display(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    Road1(120, 16);
    rd1.ChangeVerticalPos(32, 32, 32, 32, '-');
    rd1.CreateRoad(0, 0, 0);
    Road2(120, 16);
    rd2.ChangeVerticalPos(5, 5, 5, 5, '-');
    rd2.CreateRoad(0, 0, 0);
    Road3(120, 16);
    rd3.ChangeVerticalPos(22, 22, 22, 22, '+');
    rd3.CreateRoad(0, 0, 0);
    rs1.ChangeVerticalPos(5, 5, 5, 5, '-');
    rs1.BuildRoadStrips(1, 1, 1);
    rs2.ChangeVerticalPos(22, 22, 22, 22, '+');
    rs2.BuildRoadStrips(1, 1, 1);
    rs3.ChangeVerticalPos(32, 32, 32, 32, '-');
    rs3.BuildRoadStrips(1, 1, 1);

    // Display timer
    displayTimer();

    glutSwapBuffers();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(650, 100);
    glutInitWindowSize(phyWidth, phyHeight);
    glutCreateWindow("GameMap");
    init2D();

    // Initialize the timer
    initTimer();

    glutDisplayFunc(Display);
    glutMainLoop();
    return 0;
}
