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
int alphaX,alphaY,flag,countscore,scoreflag = 0;
double counter = 0;
double Xpos = 0.0;

struct BigSquare{
    int TopRightCornerX;
    int TopRightCornerY,BottomRightY;

    int vx1 = centerX-12/2-20,vx2=centerX+12/2-20,vx3=centerX+12/2-20,vx4=centerX-12/2-20; // X vertices
    int vy1 = centerY-12/2,vy2=centerY-12/2,vy3=centerY+12/2,vy4=centerY+12/2; // Y vertices

    void TBigSquare()
{
    glColor3f(1, 1, 1);
glBegin(GL_POLYGON);
glVertex2f(vx1,vy1);//Bottom left corner
glVertex2f(vx2,vy2);//Bottom right corner
glVertex2f(vx3,vy3);//Top Right corner
glVertex2f(vx4,vy4);//Bottom Right corner
glEnd();
TopRightCornerX = vx2;//centerX+15/2-20
TopRightCornerY = vy3;//centerY+15/2
BottomRightY = vy2;//centerY-15/2


}
   };
    struct SmallSquare{
    int TopLeftCornerX,TopRightCornerX;
    int TopRightCornerY,TopLeftCornerY;

    void TSmallSquare(int r,int g,int b)
{
    glColor3f(r, g, b);
glBegin(GL_POLYGON);
glVertex2f((centerX+10)-5/2+alphaX,(centerY+10)-5/2+alphaY);//Bottom Left Corner
glVertex2f((centerX+10)+10/2+alphaX,(centerY+10)-5/2+alphaY);//Bottom Right corner
glVertex2f((centerX+10)+10/2+alphaX,(centerY+10)+5/2+alphaY);//Top Right corner
glVertex2f((centerX+10)-5/2+alphaX,(centerY+10)+5/2+alphaY);//Top left corner
glEnd();


//The two points of the frog on the left that will collide
TopLeftCornerX = (centerX+10)-5/2+alphaX;
TopLeftCornerY = (centerY+10)+5/2+alphaY;
TopRightCornerX = (centerX+10)+5/2+alphaX;
TopRightCornerY = (centerY+10)+5/2+alphaY;
}
    };

    BigSquare Collider;
    SmallSquare Frog;

    void PostUpdt(int value)
    {
        Xpos += 0.19;

        if(Xpos >= (logWidth-20))
        {
            Xpos = 0.0;
        }

        glutPostRedisplay();
        glutTimerFunc(1000/60,PostUpdt,0);
    }



void Collide()
{
    
    if(Collider.TopRightCornerX+Xpos >= Frog.TopLeftCornerX && Collider.TopRightCornerX+Xpos <= Frog.TopRightCornerX
    && Collider.TopRightCornerY >= Frog.TopLeftCornerY && Collider.BottomRightY <= Frog.TopLeftCornerY)
    {
        Frog.TSmallSquare(0,0.0,0.0);
        if(scoreflag == 0)
        {
            scoreflag = 1;
            countscore++;
        }
        flag = 1;
    }
    if(flag == 0){
        Frog.TSmallSquare(1,1,1);
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


counter = counter+0.5;

glPushMatrix();
glTranslated(Xpos,0,0);
Collider.TBigSquare();
glPopMatrix();
Collide();

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
glutCreateWindow( "Assignment4");
init2D();
glutDisplayFunc(Display);
glutTimerFunc(1000/60,PostUpdt,0);
glutKeyboardFunc(KeyMoves);
glutMainLoop();
} 