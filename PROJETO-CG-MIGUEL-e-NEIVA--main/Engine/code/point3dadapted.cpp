#include "point3dadapted.hpp"

Point3D::Point3D(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}
Point3D::Point3D()
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

Point3D::Point3D(Point3D p, float m)
{
    this->x = p.x * m;
    this->y = p.y * m;
    this->z = p.z * m;
}

float Point3D::getX()
{
    return x;
};
float Point3D::getY()
{
    return y;
};
float Point3D::getZ()
{
    return z;
};
bool Point3D::equals(Point3D point)
{
    if (this->getX() == point.getX() && this->getY() == point.getY() && this->getZ() == point.getZ())
        return true;
    return false;
}
