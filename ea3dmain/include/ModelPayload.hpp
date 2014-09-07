//
//  SamplePayload.hpp
//  EA3D
//
//  Created by Johnny Lee on 8/10/14.
//
//

#ifndef EA3D_ModelPayload_h
#define EA3D_ModelPayload_h
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
class ModelPayload{
    
public:
	ModelPayload(){}
	
	unordered_map<string, unordered_map<string, string>> &getModelFiles();
	
	virtual ~ModelPayload(){}
private:
	//<file name, file path>
	unordered_map<string, unordered_map<string, string>> modelFilePaths;
	
};

#endif
