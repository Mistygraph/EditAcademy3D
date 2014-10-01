
#ifndef EA3D_Ea3dResource_hpp
#define EA3D_Ea3dResource_hpp
#include <json/json.h>
// get resource from json
class Ea3dResource {
  public:
    Ea3dResource();
    Json::Value resRoot;
    
    ~Ea3dResource(){};
};

#endif
