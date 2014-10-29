

#include "Ea3dRenderPipeline.hpp"
#include <iostream>
#include "Ea3dUtil.hpp"
#include "Ea3dShaderLoader.hpp"
#include <assimp/scene.h>       // Output data structure
#include <assimp/postprocess.h> // Post processing flags
#include <vector>
#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#define BOOST_LOG_DYN_LINK 1
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>

using namespace std;
void Ea3dRenderPipeline::iniPipeline() {}
void Ea3dRenderPipeline::loadModel() {
    const string pfile = Ea3d::getModelPath(payload, "cube.obj");
    Assimp::Importer importer;
    const aiScene *sc =
        importer.ReadFile(pfile, aiProcess_CalcTangentSpace | aiProcess_Triangulate |
                                     aiProcess_JoinIdenticalVertices | aiProcess_SortByPType);

    if (!sc) {
        cout << importer.GetErrorString();
    }

    vector<float> mesh_vertex;
    aiMesh *mesh = *(sc->mMeshes);
    if (sc->HasMeshes()) {
        BOOST_LOG_TRIVIAL(debug) << "# of Meshes = "<<sc->mNumMeshes;
        for (auto i = 0; i < sc->mNumMeshes; ++i) {
            if (mesh->mNumVertices > 0) {
                BOOST_LOG_TRIVIAL(debug) << "# of Vertices = "<<mesh->mNumVertices;
                for (auto j = 0; j < mesh->mNumVertices; ++j) {
                    aiVector3D &vert = mesh->mVertices[j];
                    mesh_vertex.push_back(vert.x);
                    mesh_vertex.push_back(vert.y);
                    mesh_vertex.push_back(vert.z);
                }
            }
        }
    } else {
        cout << "Error: No meshes found";
    }

    BOOST_LOG_TRIVIAL(debug) << "A debug severity message";
    

    //    if ((*mesh)->mNumVertices > 0) {
    //        for (uint i = 0; i < (*mesh)->mNumVertices; ++i) {
    //            aiVector3D &vert = (*mesh)->mVertices[i];
    //            cout << i << ".\t";
    //            cout << vert.x << '\t' << vert.y << '\t' << vert.z << endl;
    //        }
    //    }
    //
    //    if ((*mesh)->mNumFaces > 0) {
    //        //        aiFace *face = (*mesh)->mFaces;
    //        cout << "Number of Faces = " << (*mesh)->mNumFaces << endl;
    //        for (unsigned int i = 0; i < (*mesh)->mNumFaces; ++i) {
    //            uint *idx = (*mesh)->mFaces[i].mIndices;
    //            cout << i << ".\t";
    //            cout << idx[0] << '\t' << idx[1] << '\t' << idx[2] << endl;
    //        }
    //    }

    //    string vertPath = Ea3d::getShaderPath(payload, "shaderToySample");
    //    string fragPath = Ea3d::getShaderPath(payload, "shaderToySample");
    //    GLuint loc_shader = Ea3d::CreateShaders(vertPath, fragPath);

    //    GLuint vboHandle, vaoHandle;
    //    glGenBuffers(1, &vboHandle); // vbo
    //    glBindBuffer(GL_ARRAY_BUFFER, vboHandle);
    //    glBufferData(GL_ARRAY_BUFFER, sizeof(bufferData), &bufferData,
    //    GL_STATIC_DRAW);
    //
    //    glGenVertexArrays(1, &vaoHandle); // vao
    //    glBindVertexArray(vaoHandle);     // vao
    //
    //    glEnableVertexAttribArray(0);
    //    glBindBuffer(GL_ARRAY_BUFFER, vboHandle);
    //    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

    //---------------------------------------------------------------
    //    glGenVertexArrays( 1, &vaoHandle);
    //    glBindVertexArray(vaoHandle);
    //
    //    glGenBuffers(3, vboHandles);
    //
    //    glBindBuffer(GL_ARRAY_BUFFER, vboHandles[0]);
    //    //The GL_ARRAY_BUFFER​ binding is NOT part of the VAO's state!
    //    //I know that's confusing, but that's the way it is.
    //    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float),
    //    &vertices[0],
    //    GL_STATIC_DRAW);
    //    glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 0, (GLubyte *)NULL);
    //    glEnableVertexAttribArray(0);  // Vertex Data
    //
    //    glBindBuffer(GL_ARRAY_BUFFER, vboHandles[1]);
    //    glBufferData(GL_ARRAY_BUFFER, normal.size() * sizeof(float), &normal[0],
    //    GL_STATIC_DRAW);
    //    glVertexAttribPointer( 1, 3, GL_FLOAT, GL_FALSE, 0, (GLubyte *)NULL);
    //    glEnableVertexAttribArray(1);  // Normal Data
    //
    //    //index data
    //    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboHandles[2]);
    //    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint),
    //    &indices[0],
    //    GL_STATIC_DRAW);
}
void Ea3dRenderPipeline::execute() {

    /*
        if model not create || change model
            -> loadModel
        if shader info not create || change shader
            -> create shader
    */

    // ------ set vbo
    // float bufferData[] = {0.0f, 0.5f, 0.0f, 0.5f, -0.5f, 0.0f, -0.5f, -0.5f, 0.0f};

    //    glUseProgram(loc_shader);

    //    glBindVertexArray(vaoHandle);
    //    glDrawArrays(GL_TRIANGLES, 0, 3);
}
