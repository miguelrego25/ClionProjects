#ifndef GROUP
#define GROUP
#include <vector>
#include <string>
#include <tuple>
#include <set>
//#include "catmull.hpp"
using namespace std;

class Group
{
private:
    vector<tuple<string, float, float, float, float>> transform;
    vector<string> models;
    vector<Group> groups;

public:
    Group();
    void setTransform(vector<tuple<string, float, float, float, float>>);
    vector<tuple<string, float, float, float, float>> getTransform();
    void setModels(vector<string>);
    vector<string> getModels();
    void setGroups(vector<Group>);
    vector<Group> getGroups();
    set<string> getAllModels();
};

#endif