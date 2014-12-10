

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
    vector<float> mesh_normal;
    vector<float> mesh_index;
    aiMesh *mesh = *(sc->mMeshes);
    // http://www.lighthouse3d.com/cg-topics/code-samples/importing-3d-models-with-assimp/
    if (sc->HasMeshes()) {
        BOOST_LOG_TRIVIAL(debug) << "Number of Meshes = " << sc->mNumMeshes;
        // For each mesh
        for (auto i = 0; i < sc->mNumMeshes; ++i) {
            // Faces (index / 3)
            BOOST_LOG_TRIVIAL(debug) << "Number of Faces = " << mesh->mNumFaces;
            for (unsigned int t = 0; t < mesh->mNumFaces; ++t){
                unsigned int *ver = mesh->mFaces[t].mIndices;
                cout<<ver[0]<<" "<<ver[1]<<" "<< ver[2]<<endl;
                
                mesh_index.push_back(ver[0]);
                mesh_index.push_back(ver[1]);
                mesh_index.push_back(ver[2]);
            }
            
            // Get vertex info
            if (mesh->mNumVertices > 0) {
                BOOST_LOG_TRIVIAL(debug) << "Number of Vertices = " << mesh->mNumVertices;
                // while obj loaded into assimp, they reorganize the content
                // For each set of vertices
                for (auto j = 0; j < mesh->mNumVertices; ++j) {
                    cout << j << endl;
                    // Vertices
                    if (mesh->HasPositions()) {
                        aiVector3D &vert = mesh->mVertices[j];
                        cout << vert.x << " " << vert.y << " " << vert.z << endl;
                        mesh_vertex.push_back(vert.x);
                        mesh_vertex.push_back(vert.y);
                        mesh_vertex.push_back(vert.z);
                    }

                    // Normals
                    if (mesh->HasNormals()) {
                        // BOOST_LOG_TRIVIAL(debug) << "has Normals";
                        auto vert = mesh->mNormals[j];
                        cout << vert.x << " " << vert.y << " " << vert.z << endl;
                        mesh_normal.push_back(vert.x);
                        mesh_normal.push_back(vert.y);
                        mesh_normal.push_back(vert.z);
                    }
                }
                
            }
        }
    } else {
        cout << "Error: No meshes found";
    }

    BOOST_LOG_TRIVIAL(trace) << "trace message";
    BOOST_LOG_TRIVIAL(info) << "info message";
    BOOST_LOG_TRIVIAL(error) << "error message";

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
