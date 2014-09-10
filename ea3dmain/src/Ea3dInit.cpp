#include "Ea3dInit.hpp"
#include "ModelPayload.hpp"
using namespace std;
Ea3dInit::Ea3dInit(){
    
}

//------------------------------------------------------------------------------
bool Ea3dInit::initModelPathSetting(){
    typedef unordered_map<string, unordered_map<string, string>> uuMapss;
    boost::property_tree::ptree pt;
    boost::property_tree::ini_parser::read_ini(this->settingFileName, pt);

    uuMapss modelFilePaths ;
    
    
    for(auto& section : pt) {
        for(auto& key : section.second){
            unordered_map<string, string> smodel({{key.first,key.second.get_value <std::string> ()}});
            modelFilePaths.emplace(section.first, smodel);
        }
    }
    ModelPayload::getInstance()->setModelFiles(modelFilePaths);
    
    ModelPayload *mpp = ModelPayload::getInstance();
    ModelPayload *mpp2 = ModelPayload::getInstance();
    for (auto& key1 : mpp2->getModelFiles()) {
        for(auto& key2 : key1.second){
            cout<<key1.first <<'\n'<<key2.first<<'\t'<<key2.second<<endl;
        }
    }
    
    return true;
}

