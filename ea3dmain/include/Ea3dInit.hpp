//
//  Ea3dInit.hpp
//  EA3D
//
//  Created by Johnny Lee on 9/6/14.
//
//

#ifndef EA3D_Ea3dInit_hpp
#define EA3D_Ea3dInit_hpp
#include <iostream>
#include <unordered_map>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>
#include <string>

class Ea3dInit {

  public:
    Ea3dInit();
    bool initModelPathSetting();
    virtual ~Ea3dInit() {}

  private:
    const std::string settingFileName = "setting.ini";
};

#endif
