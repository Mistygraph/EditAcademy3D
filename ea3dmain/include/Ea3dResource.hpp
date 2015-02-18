
#ifndef EA3D_Ea3dResource_hpp
#define EA3D_Ea3dResource_hpp

#include <jsoncpp/json/json.h>

#include <string>
// get resource from json
class Ea3dResource {
  private:
    Json::Value rscRoot;
    
  public:
    Ea3dResource();

    Json::Value getResourceRoot() { return this->rscRoot; }
    ~Ea3dResource(){};
};

#endif
