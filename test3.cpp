// C program to demonstrate 
// drawing a circle using 
// OpenGL 
//g++ *filename.cpp* -o *FolderName* -lglut -lGLU -lGL
#include<stdio.h> 
#include<GL/glut.h> 
#include<math.h> 
#include<string.h>
#define pi 3.142857 

// function to initializ
int phyWidth= 600;
int phyHeight= 600;
int logWidth=300;
int logHeight=300;


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

void Apples()
{
glColor3f(1.0, 0.0, 0.0);
DrawCircle(-510,110,7,1000);
DrawCircle(-550,120,7,1000);
DrawCircle(-525,155,7,1000);
DrawCircle(590,110,7,1000);
DrawCircle(510,110,7,1000);
DrawCircle(520,159,7,1000);

}

void printSome(char *str,int x,int y) {
glColor3f (1, 1.0, 1.0);
glRasterPos2d(x,y);
for (int i=0;i<strlen(str);i++){glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,str[i]);}
glFlush();
}

void RoadAndMoon()
{
glColor3f(1.0, 1.0, 1.0);
DrawCircle(550,330,60,1000);
glColor3f(0.0, 0.0, 1.0);
DrawCircle(520,330,60,1000);

glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex2i(400,-400);
glVertex2i(-400,-400);
glVertex2i(-100,50);
glVertex2i(100,50);
glEnd();
}

void WelcomeSign()
{

glBegin(GL_LINE_STRIP);
glColor3f(1, 1, 1);
glVertex2i(490,-25);
glVertex2i(525,45);
glVertex2i(550,-25);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0, 1);

glVertex2i(600,0);
glVertex2i(600,-50);
glVertex2i(450,-50);
glVertex2i(450,0);
glEnd();
printSome("Welcome",450,-25);
}

void RoadSides()
{
glBegin(GL_POLYGON);
glColor3f(0, 0.5, 1);
glVertex2i(-800,-400);
glVertex2i(-400,-400);
glVertex2i(-100,50);
glVertex2i(-800,50);

glEnd();

glBegin(GL_POLYGON);
glColor3f(0, 0.5, 0);
glVertex2i(800,-400);
glVertex2i(350,-400);
glVertex2i(100,50);
glVertex2i(800,50);
glEnd();	
}

void RoadStripes()
{
glBegin(GL_QUADS);
glColor3f(1, 1, 1);
glVertex2i(25,-400);
glVertex2i(-25,-400);
glVertex2i(-25,-250);
glVertex2i(25,-250);
glEnd();


glBegin(GL_QUADS);
glColor3f(1, 1, 1);
glVertex2i(25,-100);
glVertex2i(-25,-100);
glVertex2i(-25,50);
glVertex2i(25,50);
glEnd();
}

void Trees()
{
	glBegin(GL_QUADS);
glColor3f(0, 0.35f, 0.05f);
glVertex2i(-600,-200);
glVertex2i(-600,100);
glVertex2i(-450,100);
glVertex2i(-450,-200);
glEnd();

glColor3f(0, 0, 0);
DrawCircle(-590,110,60,1000);
DrawCircle(-550,150,60,1000);
DrawCircle(-490,110,60,1000);

glBegin(GL_QUADS);
glColor3f(0.5f, 0.35f, 0.05f);
glVertex2i(600,-200);
glVertex2i(600,100);
glVertex2i(450,100);
glVertex2i(450,-200);
glEnd();

WelcomeSign();

glColor3f(0, 1, 0);
DrawCircle(590,110,60,1000);
DrawCircle(550,150,60,1000);
DrawCircle(490,110,60,1000);

Apples();
}

void Stars()
{
glColor3f(1, 1, 1);
DrawCircle(290,100,7,1000);
DrawCircle(350,290,7,1000);
DrawCircle(-190,260,7,1000);
DrawCircle(187,243,7,1000);
DrawCircle(-250,255,7,1000);
DrawCircle(-290,117,7,1000);
DrawCircle(-275,210,7,1000);
DrawCircle(-150,159,7,1000);
DrawCircle(-180,110,7,1000);
DrawCircle(-375,410,7,1000);
DrawCircle(-350,359,7,1000);
DrawCircle(-480,410,7,1000);
}




void init2D (void) 
{ 
	// making background color black as first 
	// 3 arguments all are 0.0 
	glClearColor(0, 0, 0.1, 0.5); 

	
	// making picture color green (in RGB mode), as middle argument is 1.0 
	glColor3f(0.0, 0.0, 0.5); 
	
	// breadth of picture boundary is 1 pixel 
	glPointSize(2.0); 
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity(); 
	
	// setting window dimension in X- and Y- direction 
	gluOrtho2D(-780, 780, -420, 420); 
} 

void Display (void) 
{ 
glClear(GL_COLOR_BUFFER_BIT);

glBegin(GL_QUADS);
glColor3f(1, 0.5, 1);
glVertex2i(0,-200);
glVertex2i(0,100);
glVertex2i(-250,100);
glVertex2i(-250,-200);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.5f, 0.35f, 0.05f);
glVertex2i(0,-200);
glVertex2i(0,100);
glVertex2i(500,200);
glVertex2i(500,-100);
glEnd();


glColor3f(0.5, 0, 0);
DrawCircle(-125,-50,70,1000);

glBegin(GL_QUADS);       //door
glColor3f(0.0f, 0.35f, 0.1f);
glVertex2i(-50,-200);
glVertex2i(-50,-50);
glVertex2i(-200,-50);
glVertex2i(-200,-200);
glEnd();



glBegin(GL_TRIANGLES);
glColor3f(1, 1, 0.5);
glVertex2i(-110,200);
glVertex2i(0,100);
glVertex2i(-250,100);
glEnd();

glColor3f(1, 1, 1);
DrawCircle(-125,150,20,1000);

glBegin(GL_QUADS);
glColor3f(0.0f, 0.35f, 0.1f);
glVertex2i(0,100);
glVertex2i(-110,200);
glVertex2i(400,300);
glVertex2i(500,200);
glEnd();
glColor3f(0, 0, 0);
printSome("Home",-200,50);
printSome("Sweet Home",-200,30);

int flag =0;
	for(int i = 0;i<11;i++)
	{		int z = -300;
	int y = 200;
		if (flag == 0)
		{ 
			glColor3f(1, 0.5, 0);
			DrawCircle(z,y,10,1000);
			flag = 1;
		}
		if(flag == 1)
		{glColor3f(1, 1, 1);
			DrawCircle(z,y,10,1000);
			flag = 0;
		}
		z += 10;
		
	}
glutSwapBuffers();
glFlush();


} 
//g++ test2.cpp -o test2 -lglut -lGLU -lGL


int main (int argc, char** argv) 
{ 
	glutInit( &argc, argv);
glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB);
glutInitWindowPosition( 300, 300);
glutInitWindowSize(phyWidth, phyHeight);
glutCreateWindow( "Assignment2");
init2D();
glutDisplayFunc(Display);
glutMainLoop();
} 