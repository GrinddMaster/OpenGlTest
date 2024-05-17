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
#include"Character.cpp"
#include"BoatNRiverSide.cpp"


using namespace std;
#define pi 3.142857 

// function to initializ

int flag,countscore,scoreflag,position= 0;
int HoldTheStipsDown = 1;
double XposC1,XposC2,XposC3 = 0.0;
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
        if (z == '+' && HoldTheStipsDown == 1) {
            vx1 += x1;
            vx2 += x2;
            vx3 += x3;
            vx4 += x4;
        }
        else if (z == '-'&& HoldTheStipsDown == 1) {
            vx1 -= x1;
            vx2 -= x2;
            vx3 -= x3;
            vx4 -= x4;
        }
       
    }

    void ChangeVerticalPos(int y1, int y2, int y3, int y4, char z) {
        if (z == '+'&& HoldTheStipsDown == 1) {
            vy1 += y1;
            vy2 += y2;
            vy3 += y3;
            vy4 += y4;
        }
        else if (z == '-'&& HoldTheStipsDown == 1) {
            vy1 -= y1;
            vy2 -= y2;
            vy3 -= y3;
            vy4 -= y4;
        }
        
    }
};
Road rd1, rd2, rd3;
RoadStrips rs1, rs2, rs3;

void printSome(char *str,int x,int y) {
	
glColor3f (1, 1.0, 1.0);
glRasterPos2d(x,y);
for (int i=0;i<strlen(str);i++){glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str[i]);}
glFlush();
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
struct CollideCar{
    int TopRightCornerX;
    int TopRightCornerY,BottomRightY;

    int vx1 = centerX-12/2-20,vx2=centerX+12/2-20,vx3=centerX+12/2-20,vx4=centerX-12/2-20; // X vertices
    int vy1 = centerY-12/2,vy2=centerY-12/2,vy3=centerY+12/2,vy4=centerY+12/2; // Y vertices

    void CarC()
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
    struct SmallSquare{
    int TopLeftCornerX,TopRightCornerX;
    int TopRightCornerY,TopLeftCornerY;

    void TSmallSquare(int r,int g,int b)
{
    
CreateCharacter(r, g, b);


//The two points of the frog on the left that will collide
TopLeftCornerX = (centerX)-10/2+alphaX;
TopLeftCornerY = (centerY-45)+7.5/2+alphaY;
TopRightCornerX = (centerX)+10/2+alphaX;
TopRightCornerY = (centerY-45)+7.5/2+alphaY;
}
    };

    CollideCar Collider1,Collider2,Collider3;
    SmallSquare Frog;

    void PostUpdt(int value)
    {
        XposC1 += 0.2;XposC2 += 0.3;XposC3 += 0.1;

        if(XposC1 >= (logWidth+20))
        {
            XposC1 = 0.0;
        }
        else if (XposC2 >= (logWidth+20))
        {XposC2 = 0.0;}
        else if (XposC3 >= (logWidth+20))
        {XposC3 = 0.0;}

        glutPostRedisplay();
        glutTimerFunc(1000/60,PostUpdt,0);
    }



void Collide()
{
    if(Collider3.TopRightCornerX+XposC3 >= Frog.TopLeftCornerX && Collider3.TopRightCornerX+XposC3 <= Frog.TopRightCornerX
    && Collider3.TopRightCornerY >= Frog.TopLeftCornerY && Collider3.BottomRightY <= Frog.TopLeftCornerY)
    {
        Frog.TSmallSquare(0,0.0,0.0);
        if(scoreflag == 0)
        {
            scoreflag = 1;
            countscore++;
        }
        flag = 1;
    }
    
    if(Collider2.TopRightCornerX+XposC2 >= Frog.TopLeftCornerX && Collider2.TopRightCornerX+XposC2 <= Frog.TopRightCornerX
    && Collider2.TopRightCornerY >= Frog.TopLeftCornerY && Collider2.BottomRightY <= Frog.TopLeftCornerY)
    {
        Frog.TSmallSquare(0,0.0,0.0);
        if(scoreflag == 0)
        {
            scoreflag = 1;
            countscore++;
        }
        flag = 1;
    }
    if(Collider1.TopRightCornerX+XposC1 >= Frog.TopLeftCornerX && Collider1.TopRightCornerX+XposC1 <= Frog.TopRightCornerX
    && Collider1.TopRightCornerY >= Frog.TopLeftCornerY && Collider1.BottomRightY <= Frog.TopLeftCornerY)
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



void CallTheRoads(int MapFlag) {
    Road1(120, 16);
    rd1.ChangeVerticalPos(32, 32, 32, 32, '-');
    rd1.CreateRoad(0, 0, 0);
    Road2(120, 16);
    rd2.ChangeVerticalPos(5, 5, 5, 5, '-');
    rd2.CreateRoad(0, 0, 0);
    Road3(120, 16);
    rd3.ChangeVerticalPos(33, 33, 33, 33, '+');
    rd3.CreateRoad(0, 0, 0);
    
    rs1.ChangeVerticalPos(5, 5, 5, 5, '-');
    rs1.BuildRoadStrips(1, 1, 1);
    rs2.ChangeVerticalPos(33, 33, 33, 33, '+');
    rs2.BuildRoadStrips(1, 1, 1);
    rs3.ChangeVerticalPos(32, 32, 32, 32, '-');
    rs3.BuildRoadStrips(1, 1, 1);
    HoldTheStipsDown = 0;//This flag prevents the Road strips from Running away.
    

    
    
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

void Colliders()
{
 string s = to_string(countscore);
char* str = new char[s.length()+1];
strcpy(str, s.c_str());


printSome(str,centerX-30,centerY+45);
printSome("Score: ",centerX-40,centerY+45);
    


if(position == 0)// To make sure the solhefa stay in the same position
{
    Collider1.ChangeHorizontalPos(40,40,40,40,'-');
    Collider1.ChangeVerticalPos(32,32,32,32,'-');
    Collider2.ChangeHorizontalPos(40,40,40,40,'-');
    Collider2.ChangeVerticalPos(5,5,5,5,'-');
    Collider3.ChangeHorizontalPos(40,40,40,40,'-');
    Collider3.ChangeVerticalPos(33,33,33,33,'+');
    position = 1;
}


glPushMatrix();
glTranslated(XposC1,0,0);
Collider1.CarC();
glPopMatrix();

glPushMatrix();
glTranslated(XposC2,0,0);
Collider2.CarC();
glPopMatrix();

glPushMatrix();
glTranslated(XposC3,0,0);
Collider3.CarC();
glPopMatrix();

Collide();
   
}




void init2D (void) 
{ 
	// making background color black as first 
	// 3 arguments all are 0.0 
	glClearColor(0, 0.7, 0.0, 0.0); 
	
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
CallTheRoads(0);

        CreateRiver();
        displayTimer();

    
    glPushMatrix();
Colliders();
glPopMatrix();

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
glutCreateWindow( "Collision");
init2D();
glutDisplayFunc(Display);
glutTimerFunc(1000/60,PostUpdt,0);
glutKeyboardFunc(KeyMoves);
glutMainLoop();
} 