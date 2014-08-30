//
//  ObjFileReader.h
//  EA3D
//
//  Created by Johnny Lee on 8/10/14.
//
//

#ifndef EA3D_ObjFileReader_h
#define EA3D_ObjFileReader_h
#include <iostream>

class ObjFileReader{
    
public:
	ObjFileReader(){}
	void getTest(){std::cout<<"objFileReader getTest"<<std::endl;}
    
	void getFileName();
	virtual ~ObjFileReader(){}
    
    
};

#endif
