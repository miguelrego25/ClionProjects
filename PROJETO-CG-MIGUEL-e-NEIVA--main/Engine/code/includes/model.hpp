#ifndef MODEL_H
#define MODEL_H

#include <list>
#include <vector>
#include <string>

using namespace std;

struct vector3
{
    float x, y, z;
    //Constructor
    vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
    vector3() {
        x = y = z = 0;
    }

    std::string print(){
        return "(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ")";
    }
};

enum TransformationType {
    TRANSLATION,
    ROTATION,
    SCALE
};

// Define the Transform struct
struct Transform {
    const char *type;
    float parameters[4];
};

struct model
{
    model() {}

    std::vector<vector3> vertices; // Vertices of the model
    vector3 scale;
    float rotationAngle;           // Rotation angle in degrees
    vector3 rotationAxis;         // Rotation axis as a vector
    vector3 translation;
    // Translation vector for x, y, z axes
    std::list<Transform> transformations;
    std::vector<model> group;
    // Constructor
    model(const std::vector<vector3>& _vertices,
          const vector3& _scale = vector3(1.0f, 1.0f, 1.0f),
          float _rotationAngle = 0.0,
          const vector3& _rotationAxis = vector3(0.0f, 0.0f, 0.0f),
          const vector3& _translation = vector3(1.0f, 1.0f, 1.0f))
            : vertices(_vertices),
              scale(_scale),
              rotationAngle(_rotationAngle),
              rotationAxis(_rotationAxis),
              translation(_translation)
    {}
};



struct settings
{
    // Window
    int width, height;

    // Camera
    vector3 position, lookAt, up;

    // Projection
    float fov, near, far;

    //Group
    std::list<model> modelGroup;

    //Constructor
    settings(int _width, int _height, vector3 _position, vector3 _lookAt, vector3 _up, float _fov, float _near, float _far, std::list<model> _mod) : width(_width), height(_height), position(_position), lookAt(_lookAt), up(_up), fov(_fov), near(_near), far(_far){}
};

#endif // VECTOR3_H