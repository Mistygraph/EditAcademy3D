
#include <iostream>
#include "Ea3dPlatform.hpp"

int main(int argc, const char **argv) {
		
    Ea3dPlatform myPlatform(640, 480);
    myPlatform.initPlatform();
    myPlatform.render();
    exit(EXIT_SUCCESS);
    
}
