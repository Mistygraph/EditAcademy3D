
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <glm/glm.hpp>
#include <string>
#include "ObjFileReader.hpp"
#include <unordered_map>
#include "Ea3dInit.hpp"
#include "ModelPayload.hpp"
#include <boost/filesystem.hpp>
#include "Ea3dShaderLoader.hpp"

using namespace std;
static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
//-----------------------------------------------------------------------------
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}
//-----------------------------------------------------------------------------
void initProgram(){
    Ea3dInit ea3dInit;
    ea3dInit.initModelPathSetting();
}
//-----------------------------------------------------------------------------
void drawSceneNew(GLFWwindow* window){
    
    // ------------------ path
    string shaderPath_base = ModelPayload::getInstance()->getModelFiles().at("shader_path").at("base_path");
    string shaderSample = "sample330";
    boost::filesystem::path fsp(shaderPath_base);
    fsp /=shaderSample;
    cout<< fsp.make_preferred().string()<<endl;
    
    // -----create shader
    GLuint loc_shader = CreateShaders(fsp.make_preferred().string());
    // ------ set vbo
    float bufferData[] ={
        0.0f,  0.5f,  0.0f,
        0.5f, -0.5f,  0.0f,
        -0.5f, -0.5f,  0.0f
    };
    
    
    GLuint vboHandle, vaoHandle;
    
    cout<<sizeof(bufferData)<<'\t'<<sizeof(float)<<endl;
    glGenBuffers(1, &vboHandle);//vbo
    glBindBuffer(GL_ARRAY_BUFFER, vboHandle);
    glBufferData(GL_ARRAY_BUFFER, sizeof(bufferData), &bufferData, GL_STATIC_DRAW);
//    glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 0, (GLubyte *)NULL);
    
    
    glGenVertexArrays( 1, &vaoHandle );//vao
    glBindVertexArray(vaoHandle);//vao
    
    glEnableVertexAttribArray (0);
    glBindBuffer (GL_ARRAY_BUFFER, vboHandle);
    glVertexAttribPointer (0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
    
    // ------
    
    
    while (!glfwWindowShouldClose(window)){
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        
        
        glUseProgram(loc_shader);
        glBindVertexArray(vaoHandle);
        glDrawArrays (GL_TRIANGLES, 0, 3);
        
        
        
        glfwSwapBuffers(window);
        glfwPollEvents();
        
    }
    
}
//-----------------------------------------------------------------------------
void drawSceneOld(GLFWwindow* window){
    while (!glfwWindowShouldClose(window)){
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        glViewport(0, 0, width, height);
        float ratio = width / (float) height;
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glRotatef((float) glfwGetTime() * 50.f, 0.f, 0.f, 1.f);
        glBegin(GL_TRIANGLES);
        glColor3f(1.f, 0.f, 0.f);
        glVertex3f(-0.6f, -0.4f, 0.f);
        glColor3f(0.f, 1.f, 0.f);
        glVertex3f(0.6f, -0.4f, 0.f);
        glColor3f(0.f, 0.f, 1.f);
        glVertex3f(0.f, 0.6f, 0.f);
        glEnd();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
}
//-----------------------------------------------------------------------------
void drawScene(GLFWwindow* window){
    //    drawSceneOld(window);
    drawSceneNew(window);
    
}
//-----------------------------------------------------------------------------
int main(int argc, const char ** argv)
{
    initProgram();
    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);
    // Setting the callback, so GLFW knows to call it, is done with glfwSetErrorCallback. This is one of the few GLFW functions that may be called before glfwInit, which lets you be notified of errors during initialization, so you should set it before you do anything else with GLFW.
    if (!glfwInit())
        exit(EXIT_FAILURE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    window = glfwCreateWindow(640, 480, "Edit Academy 3D", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    
    glewExperimental = GL_TRUE;
    glewInit ();
    
    glEnable (GL_DEPTH_TEST);
    glfwSetKeyCallback(window, key_callback);
    cout<< glGetString(GL_VERSION)<<endl;
    
    drawScene(window);
    glfwDestroyWindow(window);
    glfwTerminate();
    // This destroys any remaining windows and releases any other resources allocated by GLFW. After this call, you must call glfwInit again before using any GLFW functions that require it.
    exit(EXIT_SUCCESS);
}
