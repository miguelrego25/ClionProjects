#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#define _USE_MATH_DEFINES

#include <math.h>
#include <vector>
//CUBO
//CUBO
//CUBO
//CUBO
//CUBO
//CUBO
//CUBO
std::vector<Coordinates3D> list;
float posx = 0, posy = 0 , posz=0,angle = 0;

/*
void drawAxis(){ // put axis drawing in here
    glBegin(GL_LINES);
// X Axis in red
    glColor3f(1.0f, 0.0f, 0.0f);
    result.push_front({
            -100.0f, 0.0f, 0.0f);
    result.push_front({ 100.0f, 0.0f, 0.0f);
// Y Axis in Green
    glColor3f(0.0f, 1.0f, 0.0f);
    result.push_front({0.0f,
               -100.0f, 0.0f);
    result.push_front({0.0f, 100.0f, 0.0f});
// Z Axis in Blue
    glColor3f(0.0f, 0.0f, 1.0f);
    result.push_front({0.0f, 0.0f,
               -100.0f);
    result.push_front({0.0f, 0.0f, 100.0f});
    return result;

}

*/

std::list<Coordinates3D> drawplanex0z(float length, int divisions) {
    float step = length/divisions;

    std::list<Coordinates3D> result;

    for (int i = 0; i < divisions; i++) {
        for (int j = 0; j < divisions; ++j) {

            float posz = step * i - length / 2;
            float posx = step * j - length / 2;

            result.push_front({posx,length/2,posz});
            result.push_front({posx,length/2 ,posz + step});
            result.push_front({posx+step,length/2 ,posz + step });


            result.push_front({posx+step,length/2 ,posz + step});
            result.push_front({posx+step,length/2,posz});
            result.push_front({posx,length/2 ,posz});
        }
    }result.reverse();
    return result;
}
std::list<Coordinates3D> drawplanez0x( float length, int divisions) {
    float step = length / divisions;
    std::list<Coordinates3D> result;


    for (int i = 0; i < divisions; i++) {
        for (int j = 0; j < divisions; ++j) {

            float posz = step * i - length / 2;
            float posx = step * j - length / 2;

            result.push_front({posx+step, -length/2, posz+step});
            result.push_front({posx, -length/2, posz+step});
            result.push_front({posx, -length/2, posz});


            result.push_front({posx+step, -length/2, posz+step});;
            result.push_front({posx, -length/2, posz});
            result.push_front({posx+step, -length/2, posz});
        }
    }
    result.reverse();
    return result;
}

std::list<Coordinates3D> drawplaney0x(float length, int divisions) {
    float step = length / divisions;
    std::list<Coordinates3D> result;


    for (int i = 0; i < divisions; i++) {
        for (int j = 0; j < divisions; ++j) {

            float posx = step * i - length / 2;
            float posy = step * j - length / 2;


            result.push_front({posx, posy,length/2});
            result.push_front({posx + step, posy,length/2});
            result.push_front({posx + step, posy+step,length/2});


            result.push_front({posx + step, posy+step,length/2});
            result.push_front({posx, posy+step,length/2});
            result.push_front({posx, posy,length/2});
        }
    }
    result.reverse();
    return result;
}
std::list<Coordinates3D> drawplanex0y(float length, int divisions) {
    float step = length / divisions;
    std::list<Coordinates3D> result;


    for (int i = 0; i < divisions; i++) {
        for (int j = 0; j < divisions; j++) {

            float posx = step * i - length / 2;
            float posy = step * j - length / 2;


            result.push_front({posx, posy,-length/2});
            result.push_front({posx + step, posy+step,-length/2});
            result.push_front({posx + step, posy,-length/2});


            result.push_front({posx, posy,-length/2});
            result.push_front({posx, posy+step,-length/2});
            result.push_front({posx + step, posy+step,-length/2});
        }
    }
    result.reverse();
    return result;
}

std::list<Coordinates3D> drawplanez0y(float length, int divisions) {
    float step = length / divisions;
    std::list<Coordinates3D> result;


    for (int i = 0; i < divisions; i++) {
        for (int j = 0; j < divisions; ++j) {

            float posz = step * i - length / 2;
            float posy = step * j - length / 2;


            result.push_front({-length/2, posy,posz});
            result.push_front({-length/2, posy,posz + step});
            result.push_front({-length/2, posy+step,posz + step});


            result.push_front({-length/2, posy+step,posz});
            result.push_front({-length/2, posy,posz});
            result.push_front({-length/2, posy+step,posz + step});
        }
    }
    result.reverse();
    return result;
}
std::list<Coordinates3D> drawplaney0z(float length, int divisions) {
    float step = length / divisions;
    std::list<Coordinates3D> result;


    for (int i = 0; i < divisions; i++) {
        for (int j = 0; j < divisions; j++) {

            float posy = step * i - length / 2;
            float posz = step * j - length / 2;


            result.push_front({length/2, posy, posz});
            result.push_front({length/2, posy+step, posz});
            result.push_front({length/2, posy+step, posz+step});


            result.push_front({length/2, posy, posz});
            result.push_front({length/2, posy+step, posz+step});
            result.push_front({length/2, posy, posz+step});

        }
    }
    result.reverse();
    return result;
}



std::list<Coordinates3D> drawCube(float length, float division){
    std::list<Coordinates3D> result, temp;
    temp = drawplanex0z(length,division);
    result.insert(result.end(), temp.begin(), temp.end());
    temp = drawplanez0x(length,division);
    result.insert(result.end(), temp.begin(), temp.end());
    temp = drawplaney0x(length,division);
    result.insert(result.end(), temp.begin(), temp.end());
    temp = drawplanex0y(length,division);
    result.insert(result.end(), temp.begin(), temp.end());
    temp = drawplaney0z(length,division);
    result.insert(result.end(), temp.begin(), temp.end());
    temp = drawplanez0y(length,division);
    result.insert(result.end(), temp.begin(), temp.end());
    return result;
    //return temp;

}/*
std::list<Coordinates3D> cubePoints = drawCube(3,2);
*/
std::list<Coordinates3D> drawPlane(float length, float divisions) {
    return drawplanex0z(length, divisions);
}


