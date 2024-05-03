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
int MouseX = centerX;
int MouseY = centerY;
int NewCenterX = centerX;
int NewCenterY = centerY;
char* output = " ";

void MouseClick(int button, int state, int x, int y)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		MouseX = x;MouseX = 0.5+1*MouseX*logWidth/phyWidth;
		MouseY = phyHeight-y; MouseY = 0.5+1*MouseY*logHeight/phyHeight;
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		exit(1);
	}
	glutPostRedisplay();
}

void Concat( char* x)
{
			char* result;
			int length = strlen(output)+strlen(x)+1;
			result = new char[length];
			strcpy(result,output);
			strcat(result,x);
			output = result;
}

void printSome(char *str,int x,int y) {	
glColor3f (0, 0.0, 0.0);
glRasterPos2d(x,y);
for (int i=0;i<strlen(str);i++){glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str[i]);}
glFlush();
}

void TypeOnScreen(char c)
{
	printSome(&c,centerX,centerY);
}

void KeyMoves(unsigned char key, int x, int y) {
	
	
		if(key == 'a')
		{
			char* a = "a";Concat(a);
		}
		if(key == 'b')
		{
			char* a = "b";Concat(a);
		}
		if(key == 'c')
		{
			char* a = "c";Concat(a);
		}
		if(key == 'd')
		{
			char* a = "d";Concat(a);
		}

		if(key == 'e')
		{
			char* a = "e";Concat(a);
		}
		if(key == 'f')
		{
			char* a = "f";Concat(a);
		}
		if(key == 'g')
		{
			char* a = "g";Concat(a);
		}
		if(key == 'h')
		{
			char* a = "h";Concat(a);
		}
		if(key == 'j')
		{
			char* a = "j";Concat(a);
		}
		if(key == 'k')
		{
			char* a = "k";Concat(a);
		}
		if(key == 'l')
		{
			char* a = "l";Concat(a);
		}
		if(key == 'm')
		{
			char* a = "m";Concat(a);
		}
		if(key == 'o')
		{
			char* a = "o";Concat(a);
		}
		if(key == 'r')
		{
			char* a = "r";Concat(a);
		}
		if(key == 'y')
		{
			char* a = "y";Concat(a);
		}
		if(key == 'u')
		{
			char* a = "u";Concat(a);
		}
		if(key == 'i')
		{
			char* a = "i";Concat(a);
		}
		if(key == 'w')
		{
			char* a = "w";Concat(a);
		}
		if(key == ' ')
		{
			char* a = " ";Concat(a);
		}
		
	
	
	glutPostRedisplay();
}



void MotionMouse(int x,int y){
    MouseX = x;
    MouseX=0.5+1.0*MouseX*logWidth/phyWidth;
    MouseY = phyHeight - y;
    MouseY=0.5+1.0*MouseY*logHeight/phyHeight;
    glutPostRedisplay();
}

void passiveMouse(int x,int y){
    MouseX = x;
    MouseX=0.5+1.0*MouseX*logWidth/phyWidth;
    MouseY = phyHeight - y;
    MouseY=0.5+1.0*MouseY*logHeight/phyHeight;
    glutPostRedisplay();
}



void init2D (void) 
{ 
	// making background color black as first 
	// 3 arguments all are 0.0 
	glClearColor(1.0,1.0, 1.0, 1.0); 
	
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


printSome(output,NewCenterX-20,centerY+10);


glutSwapBuffers();
glFlush();


} 
//g++ Q2Assignment4.cpp -o Q24thAssignment -lglut -lGLU -lGL


int main (int argc, char** argv) 
{ 
	glutInit( &argc, argv);
glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB);
glutInitWindowPosition( 650, 100);
glutInitWindowSize(phyWidth, phyHeight);
glutCreateWindow( "Q2Assignment4");
init2D();
glutDisplayFunc(Display);
glutKeyboardFunc(KeyMoves);
glutMouseFunc(MouseClick);
//glutPassiveMotionFunc(MotionMouse);

glutMainLoop();
} 