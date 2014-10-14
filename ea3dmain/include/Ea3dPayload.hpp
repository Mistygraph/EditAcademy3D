
#ifndef EA3D_Ea3dPayload_hpp
#define EA3D_Ea3dPayload_hpp

#include <json/json.h>
// all resource get from this paload
class Ea3dPayload {

  public:
    Ea3dPayload();

    Json::Value getResourceRoot() { return this->resRoot; }

    ~Ea3dPayload() {}

  private:
    Json::Value resRoot;
};

#endif
