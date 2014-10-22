
#include "Ea3dResource.hpp"
#include "Ea3dPayload.hpp"

Ea3dPayload::Ea3dPayload() {
    Ea3dResource eRes;
    this->resRoot = eRes.getResourceRoot();
}
