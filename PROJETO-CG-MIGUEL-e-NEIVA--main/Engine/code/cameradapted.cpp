#include "cameradapted.hpp"

Camera::Camera(Point3D position, Point3D lookAt, Point3D up, Point3D projection)
{
    this->position = position;
    this->lookAt = lookAt;
    this->up = up;
    this->projection = projection;
};
Camera::Camera()
{
    this->position = Point3D(0, 0, 0);
    this->lookAt = Point3D(0, 0, 0);
    this->up = Point3D(0, 0, 0);
    this->projection = Point3D(0, 0, 0);
};

Point3D Camera::getposition()
{
    return position;
};
Point3D Camera::getlookAt()
{
    return lookAt;
};
Point3D Camera::getup()
{
    return up;
};
Point3D Camera::getprojection()
{
    return projection;
};