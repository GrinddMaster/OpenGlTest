#include <GL/glut.h>
#include <stdio.h>
#include <string.h>

#define WINDOW_WIDTH 700
#define WINDOW_HEIGHT 700

// Function declarations
void display();
void reshape(int width, int height);
void drawText(float x, float y, void *font, char *string);
void drawButton(float x, float y, float width, float height, char *label, int hoverEffect);

// Global variables
int selectedButton = -1; // -1 means no button is selected
int MenuFlag = 1;

// Button properties
float buttonWidth = 200;
float buttonHeight = 50;
float buttonX = (WINDOW_WIDTH - buttonWidth) / 2;
float buttonStartY = WINDOW_HEIGHT / 2 - buttonHeight / 2;

// Font properties
void *fontTitle = GLUT_BITMAP_TIMES_ROMAN_24;
void *fontButtons = GLUT_BITMAP_HELVETICA_18;

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);

    // Title
    glPushMatrix();
    glTranslatef((WINDOW_WIDTH - 120) / 2, WINDOW_HEIGHT - 80, 0);
    glScalef(2.0, 2.0, 1);
    drawText(0, 0, fontTitle, "Cross Road");

    drawText(1, 0, fontTitle, "Cross Road");

    glPopMatrix();

    // Buttons
    drawButton(buttonX, buttonStartY + 2 * (buttonHeight + 20), buttonWidth, buttonHeight, "Start", selectedButton == 0);
    drawButton(buttonX, buttonStartY, buttonWidth, buttonHeight, "High Scores", selectedButton == 1);
    drawButton(buttonX, buttonStartY - 2 * (buttonHeight + 20), buttonWidth, buttonHeight, "Exit", selectedButton == 2);

    glutSwapBuffers();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, width, 0, height);
    glMatrixMode(GL_MODELVIEW);
}

void drawText(float x, float y, void *font, char *string) {
    glRasterPos2f(x, y);
    int len = strlen(string);
    for (int i = 0; i < len; i++) {
        glutBitmapCharacter(font, string[i]);
    }
}

void drawButton(float x, float y, float width, float height, char *label, int hoverEffect) {
    // Draw button background
    glColor3f(0.0, hoverEffect ? 1.0 : 0.5, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y - height);
    glVertex2f(x, y - height);
    glEnd();

    // Draw button label
    glColor3f(1.0, 1.0, 1.0);
    glPushMatrix();
    glTranslatef(x + (width - strlen(label) * 9) / 2, y - height / 2 + 5, 0);
    drawText(0, 0, fontButtons, label);
    glPopMatrix();
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        // Check if any button is clicked
        if (selectedButton == 0) {
            printf("Start button clicked!\n");
            MenuFlag = 0;
        } else if (selectedButton == 1) {
            printf("High Scores button clicked!\n");
        } else if (selectedButton == 2) {
            printf("Exit button clicked!\n");
        }
    }
}

void passiveMotion(int x, int y) {
    if (x >= buttonX && x <= buttonX + buttonWidth) {
        // Calculate which button the mouse is over
        int hoverButton = (y - buttonStartY) / (buttonHeight + 20);

        // Check if the calculated button index is valid
        if (hoverButton >= 0 && hoverButton <= 2) {
            selectedButton = hoverButton;
        } else {
            selectedButton = -1; // No button is hovered
        }
    } else {
        selectedButton = -1; // No button is hovered
    }
    glutPostRedisplay();
}





