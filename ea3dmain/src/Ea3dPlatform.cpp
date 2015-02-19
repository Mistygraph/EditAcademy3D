
#include <GL/glew.h>
#include "Ea3dPlatform.hpp"
#include <boost/filesystem.hpp>
#include <iostream>
#include <memory>
#define BOOST_LOG_DYN_LINK 1
#include <boost/log/trivial.hpp>

using namespace std;

//-----------------------------------------------------------------------------
static void error_callback(int error, const char *description) { fputs(description, stderr); }
//-----------------------------------------------------------------------------
static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}
//-----------------------------------------------------------------------------
void Ea3dPlatform::initPlatform() {

    // init resource (models' path, shaders' paths)
    // Ea3dInit ea3dInit;
    // ea3dInit.initModelPathSetting();

    // init glfw windows
    glfwSetErrorCallback(error_callback);
    // Setting the callback, so GLFW knows to call it, is done with
    // glfwSetErrorCallback. This is one of the few GLFW functions that may be
    // called before glfwInit, which lets you be notified of errors during
    // initialization, so you should set it before you do anything else with
    // GLFW.
    if (!glfwInit())
        exit(EXIT_FAILURE);

    const Json::Value &rscRoot = this->payload.getResourceRoot();
    cout<<"heere"<<endl;
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, rscRoot["OpenGL"]["Major"].asInt());
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, rscRoot["OpenGL"]["Minor"].asInt());

    window = glfwCreateWindow(this->winWidth, this->winHeight, "Edit Academy 3D", NULL, NULL);

    if (!window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);

    BOOST_LOG_TRIVIAL(info) << "OpenGL Version: " << glGetString(GL_VERSION) ;
    BOOST_LOG_TRIVIAL(info) << "GLSL Version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) ;

    // init glew and default gl-enabled
    glewExperimental = GL_TRUE;
    glewInit();

    glEnable(GL_DEPTH_TEST);
    glfwSetKeyCallback(window, key_callback);
}
//-----------------------------------------------------------------------------
void Ea3dPlatform::render() {
    renderPipeline = new Ea3dRenderPipeline(&payload);
    renderPipeline->loadModel();
    renderPipeline->setShader();
    
    
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        renderPipeline->draw();
//        renderPipeline->execute();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    delete renderPipeline;
}
//-----------------------------------------------------------------------------
Ea3dPlatform::~Ea3dPlatform(){
    glfwDestroyWindow(this->window);
    glfwTerminate();
    // This destroys any remaining windows and releases any other resources
    // allocated by GLFW. After this call, you must call glfwInit again before
    // using any GLFW functions that require it.
}
