
#ifndef EA3D_Ea3dUtil_hpp
#define EA3D_Ea3dUtil_hpp

#include <string>
#include "Ea3dPayload.hpp"
namespace Ea3d {
std::string getShaderPath(Ea3dPayload *payload, std::string target);
std::string getModelPath(Ea3dPayload *payload, std::string fileName);
std::string get_file_contents(const char *filename);
    
} // namespace Ea3d
#endif
