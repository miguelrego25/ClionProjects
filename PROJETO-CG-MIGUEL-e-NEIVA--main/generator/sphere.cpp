#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include "../include/Coordinates3D.h"
#include <iostream>
#include <math.h>
#include <list>

class Spherical
{
private:
    float alpha;
    float beta;
    float radius;
public:
    Spherical(float, float, float);
    float SphericalX();
    float SphericalY();
    float SphericalZ();
};
Spherical::Spherical(float alpha, float beta, float radius)
{
    this->alpha = alpha;
    this->beta = beta;
    this->radius = radius;
}

float Spherical::SphericalX()
{
    return radius * cos(beta) * sin(alpha);
}
float Spherical::SphericalY()
{
    return radius * sin(beta);
}
float Spherical::SphericalZ()
{
    return radius * cos(beta) * cos(alpha);
}



void drawPole(std::list<Coordinates3D>& list, float radius, int slices, int stacks, bool isTop) {
    float alpha = 2 * M_PI / slices;
    float beta = M_PI / stacks;
    float angle = 0;

    while(angle < 2 * M_PI) {
        float pi = M_PI;
        Spherical p1 = {angle, isTop ? (pi/2) - beta : - (pi/2) + beta, radius};
        angle += alpha;
        Spherical p2 = {angle, isTop ? (pi/2) - beta : - (pi/2) + beta, radius};

        if (isTop){
            list.push_front({0.0f, radius, 0.0f});
            list.push_front({p2.SphericalX(), p2.SphericalY(), p2.SphericalZ()});
            list.push_front({p1.SphericalX(), p2.SphericalY(), p1.SphericalZ()});
        }
        else{
            list.push_front({0.0f, - radius, 0.0f});
            list.push_front({p1.SphericalX(), p2.SphericalY(), p1.SphericalZ()});
            list.push_front({p2.SphericalX(), p2.SphericalY(), p2.SphericalZ()});
        }
    }
}

void circularSurface(std::list<Coordinates3D>& list, float radius, float slices, float stacks) {
    float alpha = 2 * M_PI / slices;
    float beta = M_PI / stacks;
    float angle = 0;
    float angleY = (M_PI/2) - beta;
    float b1, b2;

    while (angleY > - (M_PI/2) + beta) {
        b1 = angleY;
        angleY -= beta;
        b2 = angleY;

        while(angle < 2 * M_PI) {
            Spherical p1 = {angle, b1, radius};
            Spherical p2 = {angle, b2, radius};

            angle += alpha;
            Spherical p3 = {angle, b1, radius};
            Spherical p4 = {angle, b2, radius};

            list.push_front({p1.SphericalX(), p1.SphericalY(), p1.SphericalZ()});
            list.push_front({p4.SphericalX(), p4.SphericalY(), p4.SphericalZ()});
            list.push_front({p2.SphericalX(), p2.SphericalY(), p2.SphericalZ()});

            list.push_front({p4.SphericalX(), p4.SphericalY(), p4.SphericalZ()});
            list.push_front({p1.SphericalX(), p1.SphericalY(), p1.SphericalZ()});
            list.push_front({p3.SphericalX(), p3.SphericalY(), p3.SphericalZ()});
        }
        angle = 0;
    }
}

std::list<Coordinates3D> drawSphere(float radius, int slices, int stacks) {
    std::list<Coordinates3D> result;

    drawPole(result, radius, slices, stacks, true);
    circularSurface(result, radius, slices, stacks);
    drawPole(result, radius, slices, stacks, false);

    return result;
}
/*
// create the sphere
std::list<Coordinates3D> spherePoints = drawSphere(2.0f, 10, 10);

void renderScenesphere(void){
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
    for(auto& point : spherePoints) {
        glVertex3f(point.getX(), point.getY(), point.getZ());
    }
    glEnd();
    // End of frame
    glutSwapBuffers();
}

int buildsphere(int argc, char** argv) {
    // initialize GLUT
    glutInit(&argc, argv);

    // set up the display mode
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Sphere");

    // enable depth testing
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    // set up the projection matrix
    glMatrixMode(GL_PROJECTION);
    gluPerspective(45.0f, 1.0f, 0.1f, 100.0f);

    // set up the model-view matrix
    glMatrixMode(GL_MODELVIEW);

    glutDisplayFunc(renderScenesphere);

    // enter the main loop
    glutMainLoop();

    // return success
    return 0;
}
*/