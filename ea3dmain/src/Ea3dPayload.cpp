
#include "Ea3dResource.hpp"
#include "Ea3dPayload.hpp"
#include <json/json.h>

Ea3dPayload::Ea3dPayload() {
    Ea3dResource eRes;
    this->resRoot = eRes.getResourceRoot();
}
