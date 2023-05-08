#ifndef CAMERA
#define CAMERA
#include "point3dadapted.hpp"

class Camera
{
private:
    Point3D position;
    Point3D lookAt;
    Point3D up;
    Point3D projection;

public:

    Camera(Point3D, Point3D, Point3D,Point3D);
    Camera();
    Point3D getposition();
    Point3D getlookAt();
    Point3D getup();
    Point3D getprojection();
};

#endif