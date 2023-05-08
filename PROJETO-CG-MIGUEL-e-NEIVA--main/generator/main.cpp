//
// Created by miguel on 08-03-2023.
//
#include "../generator/sphere.cpp"
#include "../generator/cone.cpp"
#include "../generator/plane&cube.cpp"
#include "../include/Coordinates3D.h"
#include <list>
#include <iostream>
#include <fstream>
#include <string.h>
#include "../generator/Coordinates3D.cpp"

// function that writes a list of points in optional file

/*void writeCoord_3d(const std::list<Coordinates3D>& coords, const std::string& fileName) {
    std::ofstream outFile(fileName})

    if (!outFile) {
        std::cerr << "Error: unable to open file " << fileName << " for writing\n";
        return;
    }

    outFile << coords.size() << '\n';

    for (Coordinates3D c : coords) {
        outFile << c.getX() << ' ' << c.getY() << ' ' << c.getZ() << '\n';
    }

    outFile.close();
}
 */
using namespace std;

void write_3d(string s, std::list<Coordinates3D> lista, string fileName) {
    std::ofstream myfile;

    if(s == "cone.3d"){
        myfile.open("cone.3d", std::ios::trunc);
    }
    if(s == "box.3d"){
        myfile.open("box.3d", std::ios::trunc);
    }
    if(s == "plane.3d"){
        myfile.open("plane.3d", std::ios::trunc);
    }
    if(s == "sphere.3d"){
        myfile.open("sphere.3d", std::ios::trunc);
    }

    myfile << lista.size() << '\n';

    for (Coordinates3D p : lista) {
        myfile << p.getX() << ' ' << p.getY() << ' ' << p.getZ() << '\n';
    }

    myfile.close();
}

int main(int argc, char* argv[]) {
    //add custom path to the 3d files
    //string filename = "../../../3dFiles/";
    string filename = "";
    std::list<Coordinates3D> list;

    if (argc == 5 && strcmp(argv[1], "plane") == 0) {
        float lenght = stof(argv[2]),
                divisions = stof(argv[3]);
        filename = filename.append(argv[4]);
        list = drawPlane(lenght, divisions);
        write_3d("plane.3d",list,filename);
    }

    if (argc == 5 && strcmp(argv[1], "box") == 0) {
        float lenght = stof(argv[2]),
                divisions = stof(argv[3]);
        filename = filename.append(argv[4]);
        list = drawCube(lenght, divisions);
        write_3d("cube.3d",list,filename);
    }

    if (argc == 6 && strcmp(argv[1], "sphere") == 0) {
        float radius = stof(argv[2]);
        int slices = atoi(argv[3]);
        int stacks = atoi(argv[4]);
        filename = filename.append( argv[5]);
        list = drawSphere(radius, slices, stacks);
        write_3d("sphere.3d",list,filename);
    }

    if (argc == 7 && strcmp(argv[1], "cone") == 0) {
        float raio = stof(argv[2]);
        float altura = stof(argv[3]);
        int slices = atoi(argv[4]);
        int stacks = atoi(argv[5]);
        filename = filename.append(argv[6]);
        list = drawCone(raio, altura, slices, stacks);
        write_3d("cone.3d",list,filename);
    }

    //check if list has anything
    /*
    for(Coordinates3D i : list){
        std::cout << i.getX() << ' ' << i.getY() << ' ' << i.getZ() << '\n';
    }
    std::cout << std::endl;
    */

    //check if path is correct
    //printf(" %s \n", filename.c_str());

    //write_3d(list, filename);

    return 0;
}
