
#include "Ea3dUtil.hpp"
#include <iostream>
#include <boost/filesystem.hpp>
#include <fstream>

using namespace std;
namespace Ea3d {
std::string getShaderPath(Ea3dPayload *payload, std::string target) {
    boost::filesystem::path fsp(payload->getResourceRoot()["shader"]["base_path"].asString());
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

// How to read a file from c++
// @see http://insanecoding.blogspot.com/2011/11/how-to-read-in-file-in-c.html
std::string get_file_contents(const char *filename) {
    std::ifstream in(filename, std::ios::in | std::ios::binary);
    if (in) {
        std::string contents;
        in.seekg(0, std::ios::end);
        contents.resize(in.tellg());
        in.seekg(0, std::ios::beg);
        in.read(&contents[0], contents.size());
        in.close();
        return (contents);
    }
    throw(errno);
}

} // namespace Ea3d
