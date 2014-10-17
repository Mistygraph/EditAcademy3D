
#include "Ea3dUtil.hpp"
#include <iostream>
#include <boost/filesystem.hpp>
using namespace std;
namespace Ea3d {
std::string getShaderPath(Ea3dPayload *payload, std::string target) {
    boost::filesystem::path fsp(
        payload->getResourceRoot()["shader"]["base_path"].asString());
    fsp /= target;
    // std::cout << "haha\n";
    return fsp.make_preferred().string();
}

std::string getModelPath(Ea3dPayload *payload, std::string fileName) {
    size_t spliter = fileName.find('.');

    // string name = fileName.substr(0, spliter);
    string ext = fileName.substr(spliter + 1);

    boost::filesystem::path fsp(
        payload->getResourceRoot()["model"][ext]["base_path"].asString());

    fsp /= fileName;

    return fsp.make_preferred().string();
}

} // namespace Ea3d