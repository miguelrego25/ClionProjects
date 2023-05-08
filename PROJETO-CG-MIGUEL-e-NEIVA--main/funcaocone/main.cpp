#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <cmath>
#include <GL/glut.h>

void changeSize(int w, int h) {

    // Prevent a divide by zero, when window is too short
    // (you cant make a window with zero width).
    if(h == 0)
        h = 1;

    // compute window's aspect ratio
    float ratio = w * 1.0 / h;

    // Set the projection matrix as current
    glMatrixMode(GL_PROJECTION);
    // Load Identity Matrix
    glLoadIdentity();

    // Set the viewport to be the entire window
    glViewport(0, 0, w, h);

    // Set perspective
    gluPerspective(45.0f ,ratio, 1.0f ,1000.0f);

    // return to the model view matrix mode
    glMatrixMode(GL_MODELVIEW);
}

void drawAxis(){ // put axis drawing in here
    glBegin(GL_LINES);
// X Axis in red
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(
            -100.0f, 0.0f, 0.0f);
    glVertex3f( 100.0f, 0.0f, 0.0f);
// Y Axis in Green
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0f,
               -100.0f, 0.0f);
    glVertex3f(0.0f, 100.0f, 0.0f);
// Z Axis in Blue
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.0f, 0.0f,
               -100.0f);
    glVertex3f(0.0f, 0.0f, 100.0f);
    glEnd();

}


void drawCone(float radius, float height, int slices, int stacks) {
    float stackHeight = height / stacks;
    float stackRadius = radius / stacks;

    for (int i = 0; i < stacks; i++) {
        float y1 = i * stackHeight;
        float y2 = (i+1) * stackHeight;
        float r1 = radius - i * stackRadius;
        float r2 = radius - (i+1) * stackRadius;

        glBegin(GL_TRIANGLE_STRIP);
        for (int j = 0; j <= slices; j++) {
            float angle = j * 2.0f * M_PI / slices;
            float x = r1 * cos(angle);
            float z = r1 * sin(angle);
            glNormal3f(x / radius, r1 / radius, z / radius);
            glVertex3f(x, y1, z);
            x = r2 * cos(angle);
            z = r2 * sin(angle);
            glNormal3f(x / radius, r2 / radius, z / radius);
            glVertex3f(x, y2, z);
        }
        glEnd();
    }
}


void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -5.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    drawAxis();
    drawCone(1.0f, 2.0f, 4, 3);

    glutSwapBuffers();
}


void renderScene(void) {

    // clear buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // set the camera
    glLoadIdentity();
    gluLookAt(5.0,5.0,5.0,
              0.0,0.0,0.0,
              0.0f,1.0f,0.0f);
    drawAxis();
    drawCone(1.0f, 2.0f, 4, 3);

    // End of frame
    glutSwapBuffers();
}


void processKeys(unsigned char c, int xx, int yy) {

// put code to process regular keys in here

}


void processSpecialKeys(int key, int xx, int yy) {

// put code to process special keys in here

}


int main(int argc, char **argv) {

// init GLUT and the window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(800,800);
    glutCreateWindow("CG@DI-UM");

// Required callback registry
    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);

// Callback registration for keyboard processing
    glutKeyboardFunc(processKeys);
    glutSpecialFunc(processSpecialKeys);

//  OpenGL settings
    glEnable(GL_DEPTH_TEST);
    glPolygonMode(GL_FRONT, GL_LINE);
    glEnable(GL_CULL_FACE);

// enter GLUT's main cycle
    glutMainLoop();

    return 1;
}