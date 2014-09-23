
// #include <GLFW/glfw3.h>
#include <string>
char *textFileRead(char *);
int textFileWrite(char *, char *);
void printShaderInfoLog(GLuint);
void printProgramInfoLog(GLuint);
GLuint CreateShaders(std::string);

GLuint LoadShader(const char *vertex_path, const char *fragment_path);