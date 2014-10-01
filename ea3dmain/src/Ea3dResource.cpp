
#include "Ea3dResource.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <json/json.h>
using namespace std;
using namespace Json;
Ea3dResource::Ea3dResource() {
    std::ifstream resource("setting2.json", ifstream::binary);
    Json::Value root;
    Json::Reader reader;
    bool parsedSuccess = reader.parse(resource, root);

    if (!parsedSuccess) {
        // report to the user the failure and their locations in the document.
        cout << reader.getFormatedErrorMessages() << "\n";
    }

    cout << root.toStyledString() << endl;
    cout << root["shader"]["base_path"].asString() << endl;
}
