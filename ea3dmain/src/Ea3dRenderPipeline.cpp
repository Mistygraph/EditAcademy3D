
#include "Ea3dRenderPipeline.hpp"
#include <iostream>
#include "Ea3dUtil.hpp"
#include "Ea3dShaderLoader.hpp"
#include <assimp/scene.h>       // Output data structure
#include <assimp/postprocess.h> // Post processing flags

using namespace std;
void Ea3dRenderPipeline::execute() {
    // ------ set vbo
//    float bufferData[] = {0.0f, 0.5f,  0.0f,  0.5f, -0.5f,
//        0.0f, -0.5f, -0.5f, 0.0f};
//    
    GLuint vboHandle, vaoHandle;
    glGenBuffers(1, &vboHandle); // vbo
//    glBindBuffer(GL_ARRAY_BUFFER, vboHandle);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(bufferData), &bufferData,
//                 GL_STATIC_DRAW);
//    
//    glGenVertexArrays(1, &vaoHandle); // vao
//    glBindVertexArray(vaoHandle);     // vao
//    
//    glEnableVertexAttribArray(0);
//    glBindBuffer(GL_ARRAY_BUFFER, vboHandle);
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
    
//    glUseProgram(loc_shader);
    
//    glBindVertexArray(vaoHandle);
//    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void Ea3dRenderPipeline::iniPipeline() {}

void Ea3dRenderPipeline::loadModel() {
    
    const string pfile = Ea3d::getModelPath(payload, "cube.obj");
    Assimp::Importer importer;
    
    const aiScene *scene = importer.ReadFile(pfile, 0);
    
    if (!scene) {
        cout << importer.GetErrorString();
    }
    aiMesh **mesh = scene->mMeshes;
    cout << (**mesh).mNumVertices << endl;
    
    string vertPath = Ea3d::getShaderPath(payload, "shaderToySample");
    string fragPath = Ea3d::getShaderPath(payload, "shaderToySample");
    GLuint loc_shader = Ea3d::CreateShaders(vertPath, fragPath);
}