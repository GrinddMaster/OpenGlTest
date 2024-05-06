// C program to demonstrate 
// drawing a circle using 
// OpenGL 
//g++ *filename.cpp* -o *FolderName* -lglut -lGLU -lGL
#include<stdio.h> 
#include<GL/glut.h> 
#include<math.h> 
#include<string.h>
#include<unistd.h>
#include<iostream>

using namespace std;
#define pi 3.142857 

// function to initializ
int phyWidth= 700;
int phyHeight= 700;
int logWidth=100;
int logHeight=100;
int centerX=logWidth/2;
int centerY=logHeight/2;


struct Road{
    int W=12;
    int H=12;
        
    int vx1 = centerX-W/2,vx2=centerX+W/2,vx3=centerX+W/2,vx4=centerX-W/2; // X vertices
    int vy1 = centerY-H/2,vy2=centerY-H/2,vy3=centerY+H/2,vy4=centerY+H/2; // Y vertices

    void CreateRoad()
{
    glColor3f(1, 1, 1);
glBegin(GL_POLYGON);
glVertex2f(vx1,vy1);//Bottom left corner
glVertex2f(vx2,vy2);//Bottom right corner
glVertex2f(vx3,vy3);//Top Right corner
glVertex2f(vx4,vy4);//Bottom Right corner
glEnd();
}
    void ChangeHorizontalPos(int x1,int x2,int x3,int x4,char z)
    {
        if(z=='+')
        {
            vx1 += x1;
            vx2 += x2;
            vx3 += x3;
            vx4 += x4;
        }
        else if (z=='-')
        {
            vx1 -= x1;
            vx2 -= x2;
            vx3 -= x3;
            vx4 -= x4;
        }
        else
        {
            //Do Nothing
        }  
    }

    void ChangeVerticalPos(int y1,int y2,int y3,int y4,char z)
    {
        if(z=='+')
        {
            vy1 += y1;
            vy2 += y2;
            vy3 += y3;
            vy4 += y4;
        }
        else if (z=='-')
        {
            vy1 -= y1;
            vy2 -= y2;
            vy3 -= y3;
            vy4 -= y4;
        }
        else
        {
            //Do nothing
        }
    }   
   };
    struct SmallSquare{
    int TopLeftCornerX,TopRightCornerX;
    int TopRightCornerY,TopLeftCornerY;

    void TSmallSquare(int r,int g,int b)
{
    glColor3f(r, g, b);
glBegin(GL_POLYGON);
glVertex2f((centerX+10)-5/2,(centerY+10)-5/2);//Bottom Left Corner
glVertex2f((centerX+10)+10/2,(centerY+10)-5/2);//Bottom Right corner
glVertex2f((centerX+10)+10/2,(centerY+10)+5/2);//Top Right corner
glVertex2f((centerX+10)-5/2,(centerY+10)+5/2);//Top left corner
glEnd();


//The two points of the frog on the left that will collide
TopLeftCornerX = (centerX+10)-5/2;
TopLeftCornerY = (centerY+10)+5/2;
TopRightCornerX = (centerX+10)+5/2;
TopRightCornerY = (centerY+10)+5/2;
}
    };




void printSome(char *str,int x,int y) {
	
glColor3f (1, 1.0, 1.0);
glRasterPos2d(x,y);
for (int i=0;i<strlen(str);i++){glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str[i]);}
glFlush();
}






void init2D (void) 
{ 
	// making background color black as first 
	// 3 arguments all are 0.0 
	glClearColor(0, 0, 0.5, 0.5); 
	
	// making picture color green (in RGB mode), as middle argument is 1.0 
	glColor3f(0.0, 0.0, 0.5); 
	
	// breadth of picture boundary is 1 pixel 
	glPointSize(2.0); 
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity(); 
	
	// setting window dimension in X- and Y- direction 
	gluOrtho2D(0.0, logWidth, 0.0, logHeight); 
} 

/*
*
*Objects Used
*
*/

Road rd1;

void Display (void) 
{ 
glClear(GL_COLOR_BUFFER_BIT);


rd1.ChangeHorizontalPos(5,5,5,5,'+');
rd1.CreateRoad();


glutSwapBuffers();
glFlush();


} 
//g++ Collision.cpp -o Collision -lglut -lGLU -lGL


int main (int argc, char** argv) 
{ 
	glutInit( &argc, argv);
glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB);
glutInitWindowPosition( 650, 100);
glutInitWindowSize(phyWidth, phyHeight);
glutCreateWindow( "GameMap");
init2D();
glutDisplayFunc(Display);
glutMainLoop();
} 