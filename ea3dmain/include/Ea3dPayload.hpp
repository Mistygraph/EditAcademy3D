
#ifndef EA3D_Ea3dPayload_hpp
#define EA3D_Ea3dPayload_hpp

#include <jsoncpp/json/json.h>
#include "Ea3dResource.hpp"
// all resource get from this paload
class Ea3dPayload {

  public:
    Ea3dPayload() : rscRoot(this->eRes.getResourceRoot()) {}

    Json::Value getResourceRoot() { return this->rscRoot; }

    ~Ea3dPayload() {}

  private:
    Ea3dResource eRes;
    Json::Value rscRoot;
};

#endif
