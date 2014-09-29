
#ifndef EA3D_Ea3dPlatform_hpp
#define EA3D_Ea3dPlatform_hpp

#include <GLFW/glfw3.h>
class Ea3dPlatform {

  public:
    Ea3dPlatform(int width = 640, int height = 480):winWidth(width), winHeight(height){}
    
    void initPlatform();
    void run();
    void drawSceneNew();
    ~Ea3dPlatform();

  private:
    int winWidth, winHeight;
    GLFWwindow *window;

};

#endif
