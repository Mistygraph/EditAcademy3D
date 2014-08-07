
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <glm/glm.hpp>
#include <string>
#include <unistd.h>
#include <boost/filesystem.hpp>


using namespace std;
//using boost::filesystem;
static void error_callback(int error, const char* description)
{
	fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}
void getSetting(){

//    boost::filesystem::path full_path(boost::filesystem::current_path());
    
//    std::cout << "Current path is : " << full_path << std::endl;
    
//    const char* testFileName = "../resource/setting.ini";
//    string line;
//    
//    std::ifstream myfile;
//    myfile.open(  testFileName );
//    if (myfile.is_open())
//    {
//        while ( getline (myfile,line) )
//        {
//            cout << line << '\n';
//        }
//        myfile.close();
//    }
//    
//    myfile.close();
}

int main(int argc, const char ** argv)
{
    getSetting();
    
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
	while (!glfwWindowShouldClose(window))
	{
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
