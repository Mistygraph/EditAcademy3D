/**
        Take advantages from the book "OpenGL 4.0 Shading Language Cookbook"
*/
#ifndef EA3D_Ea3dGLHandler_hpp
#define EA3D_Ea3dGLHandler_hpp

#include <glm/glm.hpp>
#include <GLFW/glfw3.h>
using glm::vec2;
using glm::vec3;
using glm::vec4;
using glm::mat4;
using glm::mat3;

class Ea3dGLHandler {
  public:
    Ea3dGLHandler() {}
    Ea3dGLHandler(GLuint _loc_shader) : loc_shader(_loc_shader) {}
    ~Ea3dGLHandler() {}

    int getUniformLocation(const char *name);
    void sendUniform(const char *name, float x, float y, float z);
    void sendUniform(const char *name, const vec2 &v);
    void sendUniform(const char *name, const vec3 &v);
    void sendUniform(const char *name, const vec4 &v);
    void sendUniform(const char *name, const mat4 &m);
    void sendUniform(const char *name, const mat3 &m);
    void sendUniform(const char *name, float val);
    void sendUniform(const char *name, int val);
    void sendUniform(const char *name, bool val);

    void setLocShader(GLuint);

  private:
    GLuint loc_shader;
};

#endif // Ea3dGLHandler_H
