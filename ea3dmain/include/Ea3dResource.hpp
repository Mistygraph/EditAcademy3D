
#ifndef EA3D_Ea3dResource_hpp
#define EA3D_Ea3dResource_hpp
#include <json/json.h>
// get resource from json
class Ea3dResource {
  private:
    Json::Value resRoot;

  public:
    Ea3dResource();

    Json::Value getResourceRoot() { return this->resRoot; }
    ~Ea3dResource(){};
};

#endif
