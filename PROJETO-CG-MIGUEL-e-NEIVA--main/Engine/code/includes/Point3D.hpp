#ifndef POINT3D
#define POINT3D

class Point3D
{
private:
    float x;
    float y;
    float z;

public:
    Point3D(float, float, float);
    Point3D();
    Point3D(Point3D, float);
    float getX();
    float getY();
    float getZ();
    bool equals(Point3D);
};

#endif