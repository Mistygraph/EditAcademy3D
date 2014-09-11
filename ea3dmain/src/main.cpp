
#include <GLFW/glfw3.h>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <glm/glm.hpp>
#include <string>
#include <boost/filesystem.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>
#include "ObjFileReader.hpp"
#include <unordered_map>
#include "Ea3dInit.hpp"
#include "ModelPayload.hpp"
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
int main(int argc, const char ** argv)
{
    initProgram();

    ModelPayload *mpp = ModelPayload::getInstance();
    for (auto& key1 : mpp->getModelFiles()) {
        for(auto& key2 : key1.second){
            cout<<key1.first <<'\n'<<key2.first<<'\t'<<key2.second<<endl;
        }
    }
    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    //    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    //    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    //    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    window = glfwCreateWindow(640, 480, "Edit Academy 3D", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);

    //    cout<< glGetString(GL_VERSION)<<endl;
    while (!glfwWindowShouldClose(window)){
        float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float) height;
        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);
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
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}
