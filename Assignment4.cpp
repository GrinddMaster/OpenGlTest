// C program to demonstrate 
// drawing a circle using 
// OpenGL 
//g++ *filename.cpp* -o *FolderName* -lglut -lGLU -lGL
#include<stdio.h> 
#include<GL/glut.h> 
#include<math.h> 
#include<string.h>
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
int alphaX,alphaY,flag,countscore,scoreflag = 0;

struct BigSquare{
    int VertexX,VertexXneg;
    int VertexYneg,VertexY;

    void TBigSquare()
{
    glColor3f(1, 1, 1);
glBegin(GL_POLYGON);
glVertex2f(centerX-15/2+alphaX,centerY-15/2+alphaY);
glVertex2f(centerX+15/2+alphaX,centerY-15/2+alphaY);
glVertex2f(centerX+15/2+alphaX,centerY+15/2+alphaY);
glVertex2f(centerX-15/2+alphaX,centerY+15/2+alphaY);
glEnd();
VertexX = centerX-15/2+alphaX;
VertexY = centerY-15/2+alphaY;
}
   };
    struct SmallSquare{
    int VertexX,VertexXneg;
    int VertexYneg,VertexY;

    void TSmallSquare(int r,int g,int b)
{
    glColor3f(r, g, b);
glBegin(GL_POLYGON);
glVertex2f((centerX+10)-5/2,(centerY+10)-5/2);
glVertex2f((centerX+10)+5/2,(centerY+10)-5/2);
glVertex2f((centerX+10)+5/2,(centerY+10)+5/2);
glVertex2f((centerX+10)-5/2,(centerY+10)+5/2);
glEnd();



VertexX = (centerX+10)-5/2;
VertexY = (centerY+10)-5/2;
}
    };

    BigSquare theeater;
    SmallSquare theeaten;

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

void Eat()
{
    if(theeater.VertexX == theeaten.VertexX && theeater.VertexY == theeaten.VertexY)
    {
        theeaten.TSmallSquare(0,0.5,0.5);
        if(scoreflag == 0)
        {
            scoreflag = 1;
            countscore++;
        }
        flag = 1;
    }
    if(flag == 0){
        theeaten.TSmallSquare(1,1,1);
    }
}



void printSome(char *str,int x,int y) {
	
glColor3f (1, 1.0, 1.0);
glRasterPos2d(x,y);
for (int i=0;i<strlen(str);i++){glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str[i]);}
glFlush();
}
void KeyMoves(unsigned char key, int x, int y) {

    if(key == 'w')
    {
        alphaY += 5;
    }
    if(key == 's')
    {
        alphaY -= 5;
    }
    if(key == 'a')
    {
        alphaX -= 5;
    }
    if(key == 'd')
    {
        alphaX += 5;
    }
    
    glutPostRedisplay();
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

void Display (void) 
{ 
glClear(GL_COLOR_BUFFER_BIT);

string s = to_string(countscore);
char* str = new char[s.length()+1];
strcpy(str, s.c_str());

printSome(str,centerX-30,centerY+40);
printSome("Score: ",centerX-40,centerY+40);
theeater.TBigSquare();
Eat();

glutSwapBuffers();
glFlush();


} 
//g++ Assignment4.cpp -o 4thAssignment -lglut -lGLU -lGL


int main (int argc, char** argv) 
{ 
	glutInit( &argc, argv);
glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB);
glutInitWindowPosition( 650, 100);
glutInitWindowSize(phyWidth, phyHeight);
glutCreateWindow( "Assignment4");
init2D();
glutDisplayFunc(Display);
glutKeyboardFunc(KeyMoves);
glutMainLoop();
} 