//
// Created by miguel on 09-03-2023.
//

#include "../include/Coordinates3D.h"
Coordinates3D::Coordinates3D() {
    this->x = 0;
    this->y = 0;
    this->z = 0;
}
Coordinates3D::Coordinates3D(float x,float y,float z) {
    this->x =x;
    this->y = y;
    this->z = z;

}

float Coordinates3D::getX() {
    return this->x;
}

float Coordinates3D::getY() {
    return this->y;
}

float Coordinates3D::getZ() {
    return this->z;
};