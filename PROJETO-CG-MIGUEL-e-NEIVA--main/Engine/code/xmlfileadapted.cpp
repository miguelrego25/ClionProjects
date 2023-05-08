#include "xmlfileadapted.hpp"
#include "pugixml-1.13/src/pugixml.hpp"
#include "includes/Point3D.hpp"

pugi::xml_document doc;
pugi::xml_parse_result result = doc.load_file("../models/fase1.xml");
pugi::xml_node transform_node = doc.child("world").child("group");

XMLFile::XMLFile(string filename)
{
    this->pathname = "../XML/" + filename;
}

Camera XMLFile::getCamera(){
    pugi::xml_node window = doc.child("world").child("window");
    int width = window.attribute("width").as_int(0);
    int height = window.attribute("height").as_int(0);

    //Camera
    pugi::xml_node position = doc.child("world").child("camera").child("position");
    Point3D positionPoint = Point3D(position.attribute("x").as_float(0.0f), position.attribute("y").as_float(0.0f),
                          position.attribute("z").as_float(0.0f));

    pugi::xml_node lookAt = doc.child("world").child("camera").child("lookAt");
    Point3D lookAtPoint = Point3D(lookAt.attribute("x").as_float(0.0f), lookAt.attribute("y").as_float(0.0f),
                          lookAt.attribute("z").as_float(0.0f));

    pugi::xml_node up = doc.child("world").child("camera").child("up");
    Point3D upPoint = Point3D(up.attribute("x").as_float(0.0f), up.attribute("y").as_float(0.0f),
                          up.attribute("z").as_float(0.0f));

    pugi::xml_node projection = doc.child("world").child("camera").child("projection");
    Point3D projectionPoint = Point3D(up.attribute("fov").as_float(0.0f), up.attribute("near").as_float(0.0f),
                                      up.attribute("far").as_float(0.0f)); //cleaner

    //float fov = projection.attribute("fov").as_float(0.0f);
    //float near = projection.attribute("near").as_float(0.0f);
    //float far = projection.attribute("far").as_float(0.0f);

    return Camera(positionPoint,lookAtPoint,upPoint,projectionPoint);
}

Group XMLFile::getGroup() {
    pugi::xml_node root = doc.child("world");

    if(root != NULL){
         root = doc.child("world").child("group");
    }else{
        return Group();
    }
    return handleGroup(root);
}

Group XMLFile::handleGroup(pugi::xml_node groupXML) {
    Group group = Group();

    pugi::xml_node transformXML = groupXML.child("transform");
    //Catmull catMull;
    bool hascurve = false;
    vector<tuple<string, float, float, float, float>> transform = handleTransform(transformXML, hascurve);

    pugi::xml_node modelsXML = groupXML.child("models");
    vector<string> models = handleModels(modelsXML);

    pugi::xml_node groupsXML = groupXML.child("group");

    vector<Group> groups = {};
    while(groupsXML){
        groups.push_back(handleGroup(groupsXML));
        groupsXML = groupXML.next_sibling();
    }

    group.setTransform(transform);
    group.setModels(models);
    group.setGroups(groups);

    return group;
}
vector<tuple<string, float, float, float, float>> XMLFile::handleTransform(pugi::xml_node transformXML, bool& hasCurve){
    vector<tuple<string, float, float, float, float>> res = {};

    if(transformXML == NULL){
        return res;
    }
    pugi::xml_node transf = transformXML.first_child();

    while(transf){
        if(!strcmp(transf.name(),"translate")){
            res.push_back(make_tuple("translate",transf.attribute("x").as_float(), transf.attribute("y").as_float(), transf.attribute("z").as_float(),0));
        }
        else if(!strcmp(transf.name(),"rotate")){
            res.push_back(make_tuple("rotate",transf.attribute("angle").as_float(),transf.attribute("x").as_float(), transf.attribute("y").as_float(), transf.attribute("z").as_float()));
        }
        else if(!strcmp(transf.name(),"scale")){
            res.push_back(make_tuple("scale",transf.attribute("x").as_float(), transf.attribute("y").as_float(), transf.attribute("z").as_float(),0));
        }
        transf = transf.next_sibling();
    }
    return res;
}

vector<string> XMLFile::handleModels(pugi::xml_node modelsXML) {
    vector <string> res = {};
    if(modelsXML!=NULL){
        pugi::xml_node models = modelsXML.child("model");
        while(models){
            string name_str = models.attribute("file").as_string();
            res.push_back(name_str);
            models = models.next_sibling();
        }
    }
    return res;
}

