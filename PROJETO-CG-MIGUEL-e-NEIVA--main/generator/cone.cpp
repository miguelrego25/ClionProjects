#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#define _USE_MATH_DEFINES
#include "../include/Coordinates3D.h"
#include <list>
#include <math.h>
#include <vector>

//float posx = 0, posy = 0 , posz=0,angle = 0;
/*
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
*/

std::list<Coordinates3D> drawCone(float radius, float height, int slices, int stacks) {

    std::list<Coordinates3D> vertices;
    float stackHeight = height / stacks;
    float stackRadius = radius / stacks;

    // generate the cone sides
    for (int i = 0; i < stacks; i++) {
        float y1 = i * stackHeight;
        float y2 = (i+1) * stackHeight;
        float r1 = radius - i * stackRadius;
        float r2 = radius - (i+1) * stackRadius;

        for (int j = 0; j < slices; j++) {
            float angle1 = j * 2.0f * M_PI / slices;
            float angle2 = (j+1) * 2.0f * M_PI / slices;

            float x1 = r1 * cos(angle1);
            float z1 = r1 * sin(angle1);
            float x2 = r1 * cos(angle2);
            float z2 = r1 * sin(angle2);
            float x3 = r2 * cos(angle1);
            float z3 = r2 * sin(angle1);
            float x4 = r2 * cos(angle2);
            float z4 = r2 * sin(angle2);

            Coordinates3D v1 = {x2, y1, z2};
            Coordinates3D v2 = {x1, y1, z1};
            Coordinates3D v3 = {x3, y2, z3};
            Coordinates3D v4 = {x4, y2, z4};

            vertices.push_back(v1);
            vertices.push_back(v2);
            vertices.push_back(v3);

            vertices.push_back(v2);
            vertices.push_back(v4);
            vertices.push_back(v3);
        }
    }

    // generate the cone base
    Coordinates3D center = {0.0f, 0.0f, 0.0f};
    vertices.push_back(center);
    float angleStep = 2.0f * M_PI / slices;
    for (int i = 0; i < slices; i++) {
        float angle1 = i * angleStep;
        float angle2 = (i+1) * angleStep;
        float x1 = radius * cos(angle1);
        float z1 = radius * sin(angle1);
        float x2 = radius * cos(angle2);
        float z2 = radius * sin(angle2);
        Coordinates3D v1 = {x1, 0.0f, z1};
        Coordinates3D v2 = {x2, 0.0f, z2};
        vertices.push_back(v1);
        vertices.push_back(v2);
        vertices.push_back(center);
    }

    return vertices;
}
//std::list<Coordinates3D> conePoints = DrawConeVertices(1.0f, 2.0f, 4, 3);
/*
void drawConeall(float radius, float height, int slices, int stacks) {

    float stackHeight = height / stacks;
    float stackRadius = radius / stacks;

    // draw the cone sides
    for (int i = 0; i < stacks; i++) {
        float y1 = i * stackHeight;
        float y2 = (i+1) * stackHeight;
        float r1 = radius - i * stackRadius;
        float r2 = radius - (i+1) * stackRadius;

        glBegin(GL_TRIANGLES);
        for (int j = 0; j < slices; j++) {
            float angle1 = j * 2.0f * M_PI / slices;
            float angle2 = (j+1) * 2.0f * M_PI / slices;

            float x1 = r1 * cos(angle1);
            float z1 = r1 * sin(angle1);
            float x2 = r1 * cos(angle2);
            float z2 = r1 * sin(angle2);
            float x3 = r2 * cos(angle1);
            float z3 = r2 * sin(angle1);
            float x4 = r2 * cos(angle2);
            float z4 = r2 * sin(angle2);

            glNormal3f(x2 / radius, r1 / radius, z2 / radius);
            glVertex3f(x2, y1, z2);
            glNormal3f(x1 / radius, r1 / radius, z1 / radius);
            glVertex3f(x1, y1, z1);
            glNormal3f(x3 / radius, r2 / radius, z3 / radius);
            glVertex3f(x3, y2, z3);

            glNormal3f(x4 / radius, r2 / radius, z4 / radius);
            glVertex3f(x4, y2, z4);
            glNormal3f(x2 / radius, r1 / radius, z2 / radius);
            glVertex3f(x2, y1, z2);
            glNormal3f(x3 / radius, r2 / radius, z3 / radius);
            glVertex3f(x3, y2, z3);
        }
        glEnd();
    }

    // draw the cone base
    glBegin(GL_TRIANGLES);
    glNormal3f(0.0f, -1.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f); // center of the base
    float angleStep = 2.0f * M_PI / slices;
    for (int i = 0; i < slices; i++) {
        float angle1 = i * angleStep;
        float angle2 = (i+1) * angleStep;
        float x1 = radius * cos(angle1);
        float z1 = radius * sin(angle1);
        float x2 = radius * cos(angle2);
        float z2 = radius * sin(angle2);
        glNormal3f(0.0f, -1.0f, 0.0f);
        glVertex3f(x1, 0.0f, z1);
        glVertex3f(x2, 0.0f, z2);
        glVertex3f(0.0f, 0.0f, 0.0f);
    }
    glEnd();
}
*/


/*
void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -5.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    drawAxis();
    drawConeall(1.0f, 2.0f, 4, 3);

    glutSwapBuffers();
}
*/
/*
void renderSceneCone(void){
    // clear buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // set the camera
    glLoadIdentity();
    gluLookAt(5.0,5.0,5.0,
              0.0,0.0,0.0,
              0.0f,1.0f,0.0f);
    // put axis drawing in here
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

    glBegin(GL_TRIANGLES) ;

    glColor3f(1,1,1);
    glVertex3f(-0.4,0.0,-0.4);
    glVertex3f(-0.4,0.0,0.4);
    glVertex3f(0.0,1.0,0.0);

    glEnd();
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    // draw the sphere
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 2.0f, 4.0f);
    for(auto& point : DrawConeVertices(1.0f, 2.0f, 4, 3)) {
        glVertex3f(point.getX(), point.getY(), point.getZ());
    }
    glEnd();
    // End of frame
    glutSwapBuffers();
}
*/


/*
void processKeys(unsigned char key, int xx, int yy) {
    if(key == 'a'){
        posx+= -1;
    }
    if(key == 'd'){
        posx+= 1;
    }
    if(key == 'w'){
        posz+= 1;
    }
    if (key == 's'){
        posz+= -1;
    }
    if(key == 'r'){
        angle+=1;
    }
    if(key=='t'){
        angle-=1;
    }
    glutPostRedisplay();
}

void processSpecialKeys(int key, int xx, int yy) {

// put code to process special keys in here



int buildCone(int argc, char **argv) {

    glutInit(&argc, argv);

    // set up the display mode
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Cone");

    // enable depth testing
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    // set up the projection matrix
    glMatrixMode(GL_PROJECTION);
    gluPerspective(45.0f, 1.0f, 0.1f, 100.0f);

    // set up the model-view matrix
    glMatrixMode(GL_MODELVIEW);

    glutDisplayFunc(renderSceneCone);

    // enter the main loop
    glutMainLoop();

    // return success
    return 0;
}
 */