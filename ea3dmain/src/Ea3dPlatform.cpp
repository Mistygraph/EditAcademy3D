
#include <GL/glew.h>
#include "Ea3dPlatform.hpp"
#include "Ea3dInit.hpp"
#include "ModelPayload.hpp"
#include <boost/filesystem.hpp>
#include "Ea3dShaderLoader.hpp"
#include <iostream>
#include <string>
#include "Ea3dResource.hpp"
using namespace std;

//-----------------------------------------------------------------------------
static void error_callback(int error, const char *description) {
    fputs(description, stderr);
}
//-----------------------------------------------------------------------------
static void key_callback(GLFWwindow *window, int key, int scancode, int action,
                         int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}
//-----------------------------------------------------------------------------
void Ea3dPlatform::initPlatform(){
    
    Ea3dResource res;
    
    
    // init resource (models' path, shaders' paths)
    Ea3dInit ea3dInit;
    ea3dInit.initModelPathSetting();
    
    // init glfw windows
    glfwSetErrorCallback(error_callback);
    // Setting the callback, so GLFW knows to call it, is done with
    // glfwSetErrorCallback. This is one of the few GLFW functions that may be
    // called before glfwInit, which lets you be notified of errors during
    // initialization, so you should set it before you do anything else with
    // GLFW.
    if (!glfwInit())
        exit(EXIT_FAILURE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    window = glfwCreateWindow(640, 480, "Edit Academy 3D", NULL, NULL);
    if (!window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    
    // init glew and default gl-enabled
    glewExperimental = GL_TRUE;
    glewInit();
    
    glEnable(GL_DEPTH_TEST);
    glfwSetKeyCallback(window, key_callback);
    cout <<"Current OpenGL condition: "<< glGetString(GL_VERSION) << endl;

}
//-----------------------------------------------------------------------------
void Ea3dPlatform::run() {
    drawSceneNew();
    
}
//-----------------------------------------------------------------------------
void Ea3dPlatform::drawSceneNew() {
    
    // ------------------ path
    string shaderPath_base =
    ModelPayload::getInstance()->getModelFiles().at("shader_path").at(
                                                                      "base_path");
    string shaderSample = "sample330";
    boost::filesystem::path fsp(shaderPath_base);
    fsp /= shaderSample;
    cout << fsp.make_preferred().string() << endl;
    
    // -----create shader
    GLuint loc_shader = CreateShaders(fsp.make_preferred().string());
    // ------ set vbo
    float bufferData[] = {0.0f, 0.5f,  0.0f,  0.5f, -0.5f,
        0.0f, -0.5f, -0.5f, 0.0f};
    
    GLuint vboHandle, vaoHandle;
    
    cout << sizeof(bufferData) << '\t' << sizeof(float) << endl;
    glGenBuffers(1, &vboHandle); // vbo
    glBindBuffer(GL_ARRAY_BUFFER, vboHandle);
    glBufferData(GL_ARRAY_BUFFER, sizeof(bufferData), &bufferData,
                 GL_STATIC_DRAW);
    //    glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 0, (GLubyte *)NULL);
    
    glGenVertexArrays(1, &vaoHandle); // vao
    glBindVertexArray(vaoHandle);     // vao
    
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vboHandle);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
    
    // ------
    
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        glUseProgram(loc_shader);
        glBindVertexArray(vaoHandle);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}
//-----------------------------------------------------------------------------
Ea3dPlatform::~Ea3dPlatform() {
    glfwDestroyWindow(this->window);
    glfwTerminate();
    // This destroys any remaining windows and releases any other resources
    // allocated by GLFW. After this call, you must call glfwInit again before
    // using any GLFW functions that require it.
}