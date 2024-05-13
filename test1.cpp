#include <stdio.h>
#include <GL/glut.h>
#include <math.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <ctime> 

using namespace std;

//#define pi 3.142857

int phyWidth = 700;
int phyHeight = 700;
int logWidth = 100;
int logHeight = 100;
int centerX = logWidth / 2;
int centerY = logHeight / 2;
int alphaX,alphaY = 0;

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
            // nothing
        }
    }
};

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
void circle()
{
    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {

            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.02;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
	glEnd();
}

void wheel()
{
    glPushMatrix();
    glColor3f(1.0f, 0.0f, 0.0f);
    glTranslatef(-0.45f, -0.5f, 0.0f);
    circle();
	glPopMatrix();

	glPushMatrix();
    glColor3f(1.0f, 0.0f, 0.0f);
    glTranslatef(-0.29f, -0.5f, 0.0f);
    circle();
	glPopMatrix();
}

void car(){

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 1.f);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(-0.5f, -0.44f);
    glVertex2f(-0.22f, -0.44f);
    glVertex2f(-0.22f, -0.5f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.5f, -0.44f);
    glVertex2f(-0.45f, -0.39f);
    glVertex2f(-0.3f, -0.39f);
    glVertex2f(-0.25f, -0.44f);
    glEnd();

}

void DrawCircle(float cx, float cy, float r, int num_segments) {
glBegin(GL_POLYGON);
for (int i = 0; i < num_segments; i++) {
float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
float x = r * cosf(theta);
float y = r * sinf(theta);
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

void printSome(char* str, int x, int y) {
    glColor3f(1, 1.0, 1.0);
    glRasterPos2d(x, y);
    for (int i = 0; i < strlen(str); i++) { glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str[i]); }
    glFlush();
}

void init2D(void) {
    glClearColor(0, 0.0, 0.0, 0.0); 
    glColor3f(0.0, 0.0, 0.5); 
    glPointSize(2.0); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, logWidth, 0.0, logHeight); 




}

Road rd1, rd2, rd3;
RoadStrips rs1, rs2, rs3;
River river;
riverSides riverSides;
Boat boat;

time_t startTime;


void initTimer() {
    startTime = time(NULL);
}


void displayTimer() {
    // Calculate elapsed time by subtracting current time from start time
    time_t currentTime = time(NULL);
    int elapsedTime = difftime(currentTime, startTime);

    // Convert elapsed time to minutes and seconds
    int minutes = elapsedTime / 60;
    int seconds = elapsedTime % 60;

   
    char timerString[50];
    sprintf(timerString, "Time: %02d:%02d", minutes, seconds);

    
    printSome(timerString, 10, 10); 
}

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

void Display(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the roads
    Road1(120, 16);
    rd1.ChangeVerticalPos(32, 32, 32, 32, '-');
    rd1.CreateRoad(0, 0, 0);
    Road2(120, 16);
    rd2.ChangeVerticalPos(5, 5, 5, 5, '-');
    rd2.CreateRoad(0, 0, 0);
    Road3(120, 16);
    rd3.ChangeVerticalPos(33, 33, 33, 33, '+');
    rd3.CreateRoad(0, 0, 0);

    // Draw the river between the roads
    river.SetRiver(0, 100, 59); 
    river.DrawRiver();

    riverSides.SetRiverSides(0, 100, 68); 
    riverSides.DrawRiverSides();
    riverSides.SetRiverSides(0, 100, 57); 
    riverSides.DrawRiverSides();

 boat.SetBoat(46, 60, 10, 6); 
    boat.DrawBoat();

    glPushMatrix();

        car();
        wheel();
    glPopMatrix();

     CreateCharacter(0.0, 0.0, 0.0);

    // Draw road strips
    rs1.ChangeVerticalPos(5, 5, 5, 5, '-');
    rs1.BuildRoadStrips(1, 1, 1);
    rs2.ChangeVerticalPos(33, 33, 33, 33, '+');
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
