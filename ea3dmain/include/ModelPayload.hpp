//
//  SamplePayload.hpp
//  EA3D
//
//  Created by Johnny Lee on 8/10/14.
//
//


#ifndef EA3D_ModelPayload_h
#define EA3D_ModelPayload_h
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
typedef unordered_map<string, unordered_map<string, string>> uuMapss;

static bool isIniModelPayload = false;
class ModelPayload{ //singleton
public:
    static ModelPayload *getInstance();
    const uuMapss &getModelFiles(){return modelFilePaths;}
    void setModelFiles(const uuMapss model){this->modelFilePaths = model;}
    
    virtual ~ModelPayload(){}
private:
    //<file name, file path>
    uuMapss modelFilePaths;
    ModelPayload(){}
    static ModelPayload *modelPayload;
    ModelPayload(ModelPayload const&) = delete;    // disable copy constructor
    void operator=(ModelPayload const&) = delete; // disable assign 
    
};
ModelPayload* ModelPayload::modelPayload = nullptr;

ModelPayload* ModelPayload::getInstance(){
    if (modelPayload == nullptr){
        modelPayload = new ModelPayload();
    }
    return modelPayload;
}
#endif
