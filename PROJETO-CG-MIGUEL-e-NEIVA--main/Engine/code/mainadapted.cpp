#include <iostream> // std::cout
#include <fstream>  // std::ifstream
#include <vector>
#include <tuple>
#include <map>
#include <string>
#ifdef __APPLE__
#include <GLUT/glut.h>
#include <GLUT/glew.h>
#else
#include <GL/glew.h>
#include <GL/glut.h>
#endif

#define _USE_MATH_DEFINES
#include <math.h>

//#include "tinyxml/tinyxml2.h"
//#include "../include/engine/xmlfile.hpp"
//#include "../include/common/point3d.hpp"
#include "point3dadapted.hpp"
#include "cameradapted.hpp"
#include "groupadapted.hpp"
#include "xmlfileadapted.hpp"
#include "pugixml-1.13/src/pugixml.hpp"


using namespace std;

map<string, tuple<GLuint, GLuint, unsigned int>> solidsVBO;
Group group;
Camera camera_from_xml;

GLenum mode[3] = {GL_LINE, GL_FILL, GL_POINT};
int nmode = 0;
float camX = 0, camY = 0, camZ = 0;
int startX, startY, tracking = 0;

float alpha, beta, r;
bool showCurves = true;

pugi::xml_document doc;
pugi::xml_parse_result result = doc.load_file("../models/solar_system.xml");
pugi::xml_node transform_node = doc.child("world").child("group");


void runXML(string name_of_file){
    XMLFile xmlfile =  XMLFile(name_of_file);

    camera_from_xml = xmlfile.getCamera();
    Point3D pos = camera_from_xml.getposition();

    camX = pos.getX();
    camY = pos.getY();
    camZ = pos.getZ();

    group = xmlfile.getGroup();
}

void read3dFile(string name_of_file){
    std::string path = "../models/" + name_of_file;
    std::ifstream file(path);

    vector<float> p;
    vector<unsigned int> indexes;


    int numIndex;
    file >> numIndex;
    unsigned int ind;

    for(int i = 0; (i < numIndex) && (file >> ind); i++) indexes.push_back(ind);

    float x,y,z;
    for(int i = 0;(i < numIndex) && (file >> x >> y >> z); i-- ){
        p.push_back(x);
        p.push_back(y);
        p.push_back(z);
    }

    GLuint verticesBuffer, verticeCount, indexesBuffer, indexCount;
    verticeCount = p.size()/3;

    glGenBuffers(1,&verticesBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, verticesBuffer);
    glBufferData(GL_ARRAY_BUFFER,sizeof(float) * p.size(), p.data(), GL_STATIC_DRAW);

    glGenBuffers(1,&indexesBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, indexesBuffer);
    glBufferData(GL_ARRAY_BUFFER,sizeof(unsigned int) * indexes.size(), indexes.data(), GL_STATIC_DRAW);

    tuple<GLuint, GLuint, unsigned int> t = make_tuple(verticesBuffer, indexesBuffer, indexCount);

    solidsVBO.insert(pair<string, tuple<GLuint, GLuint, unsigned int>>(name_of_file, t));
}

void coordinatesAxis(){
    glBegin(GL_LINES);

    // X Axis in Red
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-23000.0f, 0.0f, 0.0f);
    glVertex3f( 23000.0f, 0.0f, 0.0f);

    // Y Axis in Green
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0f,-23000.0f, 0.0f);
    glVertex3f(0.0f, 23000.0f, 0.0f);

    // Z Axis in Blue
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.0f, 0.0f,-23000.0f);
    glVertex3f(0.0f, 0.0f, 23000.0f);

    glEnd();
}

void buildGroup(Group group){
    int time = glutGet(GLUT_ELAPSED_TIME);
    //transformations
    for(tuple<string, float, float, float, float> transformations : group.getTransform()){
        if(std::get<0>(transformations).c_str() == "translate"){
            gltranslatef(get<1>(transformations), get<2>(transformations), get<3>(transformations))
        }else if(std::get<0>(transformations).c_str() == "translate"){
            glRotatef(get<1>(transformations), get<2>(transformations), get<3>(transformations))
        }if(std::get<0>(transformations).c_str() == "translate"){
            glRotatef(get<1>(transformations), get<2>(transformations), get<3>(transformations))
        }if(std::get<0>(transformations).c_str() == "translate"){
            glRotatef(get<1>(transformations), get<2>(transformations), get<3>(transformations))
        }

    }
}

void renderScene(void){
    int size;
    glPolygonMode(GL_FRONT, GL_LINE);
    // clear buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // set the camera
    glLoadIdentity();

    glPolygonMode(GL_FRONT, mode[nmode]);

    gluLookAt(camX, camY, camZ,
              camera_from_xml.getlookAt().getX(), camera_from_xml.getlookAt().getY(), camera_from_xml.getlookAt().getZ(),
              camera_from_xml.getup().getX(), camera_from_xml.getup().getY(), camera_from_xml.getup().getZ());


    coordinatesAxis();
    buildGroup(group);

    // End of frame
    glutSwapBuffers();
}
void changeSize(int w, int h)
{
    // Prevent a divide by zero, when window is too short
    // (you can�t make a window with zero width).
    if (h == 0)
        h = 1;
    // compute window's aspect ratio
    float ratio = w * 1.0f / h;
    // Set the projection matrix as current
    glMatrixMode(GL_PROJECTION);
    // Load the identity matrix
    glLoadIdentity();
    // Set the viewport to be the entire window
    glViewport(0, 0, w, h);
    // Set the perspective
    gluPerspective(45.0f, ratio, 1.0f, 1000.0f);
    // return to the model view matrix mode
    glMatrixMode(GL_MODELVIEW);
}

void processSpecialKeys();
void processMouseButtons();
void processMouseMotion();

int main(int argc, char **argv)
{
    runXML(argv[1]);
    set<string> loadingFiles = group.getAllModels();

    // put GLUT init here
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Trabalho fase 3");

    // put callback registration here
    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);
    glutIdleFunc(renderScene);

    // Callback registration for keyboard processing
    glutSpecialFunc(processSpecialKeys);
    glutMouseFunc(processMouseButtons);
    glutMotionFunc(processMouseMotion);

#ifndef __APPLE__
    glewInit();
#endif

    // loads all 3dFiles in XML file
    for (string file : loadingFiles)
        read3dFile(file);

    // OpenGL settings
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    // enter GLUT's main loop
    glutMainLoop();

    return 0;
}