
#include "groupadapted.hpp"
Group::Group(){
    this->transform = {};
    this->models = {};
    this->groups = {};
}

void Group::setTransform(vector<tuple<std::string, float, float, float, float>> transforms) {
    this->transform = transforms;
}

vector<tuple<string, float, float, float, float>> Group::getTransform() {
    return this->transform;
}

void Group::setModels(vector<std::string> models) {
    this->models = models;
}
vector<Group> Group::getGroups(){
    return this->groups;
}
void Group::setGroups(vector<Group> groups)
{
    this->groups = groups;
}


set<string> Group::getAllModels() {
    set<string> res = {};
    for (string model : this->models){
        res.insert(model);
    }
    for (Group g : this->groups){
        set<string> m = g.getAllModels();
        res.insert(m.begin(),m.end());
    }
    return res;
}

//void Group::setCatmull(CatMull catmull) {
//    this->catmull = catmull;
//}
//CatMull Group::getCatmull(){
//    return this->catmull;
//}
