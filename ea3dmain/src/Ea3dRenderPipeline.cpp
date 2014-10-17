
#include "Ea3dRenderPipeline.hpp"
#include <iostream>
#include "Ea3dUtil.hpp"
#include <assimp/Importer.hpp>  // C++ importer interface
#include <assimp/scene.h>       // Output data structure
#include <assimp/postprocess.h> // Post processing flags

using namespace std;
void Ea3dRenderPipeline::execute() {
    //    cout << Ea3d::getShaderPath(payload, "shaderToySample") << endl;
}

void Ea3dRenderPipeline::iniPipeline() {}

void Ea3dRenderPipeline::loadModel() {

    //    cout << Ea3d::getModelPath(payload, "cube.obj") << endl;
    const string pfile = Ea3d::getModelPath(payload, "cube.obj");
    Assimp::Importer importer;

    const aiScene *scene = importer.ReadFile(pfile, NULL);

    if (!scene) {
        cout << importer.GetErrorString();
    }
    aiMesh **mesh = scene->mMeshes;
    cout << (**mesh).mNumVertices << endl;
}