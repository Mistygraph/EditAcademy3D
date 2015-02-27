
// #include <GLFW/glfw3.h>

#ifndef EA3D_Ea3dShaderLoader_hpp
#define EA3D_Ea3dShaderLoader_hpp
#include <cstring>
namespace Ea3d {
char *textFileRead(char *);
int textFileWrite(char *, char *);
void printShaderInfoLog(GLuint);
void printProgramInfoLog(GLuint);
GLuint CreateShaders(std::string, std::string);
} // namespace Ea3d
#endif
