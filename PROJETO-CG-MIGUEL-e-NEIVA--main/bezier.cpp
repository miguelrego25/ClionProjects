#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <cmath>
#include "../Engine/code/includes/model.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

    // Calculate a Point in a bezier curve
  vector3 CubicBezier(vector3 p0, vector3 p1, vector3 p2, vector3 p3,float t) {
    //t->position
    //f(t)=(1−t)^3p0+3t(1−t)^2p1+3t^2(1−t)p2+t^3p4
    p0 = vector3(p0.x*pow(1-t,3),p0.y*pow(1-t,3),p0.z*pow(1-t,3));
    p1 = vector3(p1.x*3*t*pow(1-t,2),p1.y*3*t*pow(1-t,2),p1.z*3*t*pow(1-t,2));
    p2 = vector3(p2.x*pow(3*t,2)*(1-t),p2.y*pow(3*t,2)*(1-t),p2.z*pow(3*t,2)*(1-t));
    p3 = vector3(p3.x*pow(t,3),p3.y*pow(t,3),p3.z*pow(t,3));
    //Sum respective axis coordinates
    float x = p0.x + p1.x + p2.x + p3.x;
    float y = p0.y + p1.y + p2.y + p3.y;
    float z = p0.z + p1.z + p2.z + p3.z;

    return vector3(x,y,z);

}
    // t_u,t_v bidimensional Matrix
    //t_u , t_v (two curves result in a point)
    vector3 BezierSurface(float t_u, float t_v, vector<vector3> controlPoints, unsigned int *ind) {
        vector<vector3> bezierAccumulator;

        for (int i = 0; i < 4; i++) {
            vector3 p0 = controlPoints[ind[i*4]];
            vector3 p1 = controlPoints[ind[i*4 + 1]];
            vector3 p2 = controlPoints[ind[i*4 + 2]];
            vector3 p3 = controlPoints[ind[i*4 + 3]];

            bezierAccumulator.push_back(CubicBezier(p0, p1, p2, p3, t_u));
        }

        return CubicBezier(bezierAccumulator[0], bezierAccumulator[1], bezierAccumulator[2], bezierAccumulator[3], t_v);
    }

    void getBezierPoints(vector<vector3> &bezierPoints,
                     unsigned int *indexes,
                     vector<vector3> controlPoints,
                     int tesselagem) {
        for (int i = 0; i < tesselagem; i++) {
            for (int j = 0; j < tesselagem; j++) {
                float t_u = (float) i / (float) (tesselagem - 1);
                float t_v = (float) j / (float) (tesselagem - 1);
                bezierPoints.push_back(BezierSurface(t_u, t_v, controlPoints, indexes));
            }
        }
    }
void parseBezierPatch(string filePath, vector<vector3> &points ){
    // Read Patch File
    ifstream inputFile(filePath);
    string line;

    if(!inputFile.is_open()) {
        cerr << "Could not open file" << filePath << endl;
    }
    int numPatches;
    inputFile >> numPatches;
        cout << numPatches;

        //Matrix that stores the index of each
    int** patch_indices = new int*[numPatches+1];
    getline(inputFile,line);
    for(int i = 0; i < numPatches; ++i ) {
        getline(inputFile,line);
        patch_indices[i] = new int[16];
        char* token = strtok(&line[0], ",");
        int j = 0;
        while (token != NULL) {
            patch_indices[i][j] = stoi(token);
            token = strtok(NULL, ",");
            j++;
        }
    }
    // imprime os indices dos patches
    for (int i = 0; i < numPatches; i++) {
        cout << "Patch " << i << ": ";
        for (int j = 0; j < 16; j++) {
            cout << patch_indices[i][j] << " ";
        }
        cout << endl;
    }
    //Read number of controlPoints
    getline(inputFile, line);
    int numControlPoints = atoi(line.c_str());
    cout << numControlPoints << endl;

    //Read control points
    vector<vector3> controlPoints;
    for (int i = 0; i < numControlPoints; ++i)
    {
        getline(inputFile,line);
        // Read point.
        float coord[3];
        char* token = strtok(&line[0], ",");
        int j = 0;
        while (token != NULL) {
            coord[j] = stof(token);
            token = strtok(NULL, ",");
            j++;
        }

        // Push point to vector.
        controlPoints.push_back({coord[0], coord[1], coord[2]});
    }
// imprime os pontos de controle
    for (int i = 0; i < numControlPoints; ++i) {
        cout << "Control Point " << i << ": " << controlPoints[i].x << " " << controlPoints[i].y << " " << controlPoints[i].z << endl;
    }

    // convertBezier points to 3d
    vector<vector3> bezierPonts;
    //process patch's
    for(int i=0;i<numPatches;i++) {
        getBezierPoints(bezierPonts, reinterpret_cast<unsigned int *>(patch_indices[i]), controlPoints, 2)
    }
    }

