
#ifndef EA3D_Ea3dUtil_hpp
#define EA3D_Ea3dUtil_hpp

#include <string>
#include "Ea3dPayload.hpp"
namespace Ea3d {
std::string getShaderPath(Ea3dPayload *payload, std::string target);

std::string getModelPath(Ea3dPayload *payload, std::string fileName);

} // namespace Ea3d
#endif
