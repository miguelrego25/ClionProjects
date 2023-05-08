#ifndef XMLFILE
#define XMLFILE
#include <string>
#include <cstring>
#include "point3dadapted.hpp"
#include "cameradapted.hpp"
#include "groupadapted.hpp"
#include "pugixml-1.13/src/pugixml.hpp"

using namespace std;


class XMLFile
{
private:
    string pathname;
    Group handleGroup(pugi::xml_node);
    vector<tuple<string, float, float, float, float>> handleTransform(pugi::xml_node, bool&);
    vector<string> handleModels(pugi::xml_node);

public:
    XMLFile(string);
    Camera getCamera();
    Group getGroup();
};

#endif