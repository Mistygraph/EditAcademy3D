
#include <GL/glew.h>
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
#include <glm/gtc/type_ptr.hpp>
#define BOOST_LOG_DYN_LINK 1
#include <boost/log/trivial.hpp>

//#define TO_STREAM(stream,variable) (stream) <<#variable": "<<(variable)

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

    //    vector<float> mesh_vertex;
    //    vector<float> mesh_normal;
    //    vector<GLuint> mesh_index;
    aiMesh *mesh = *(sc->mMeshes);
    if (sc->HasMeshes()) {
        BOOST_LOG_TRIVIAL(debug) << "Number of Meshes = " << sc->mNumMeshes;
        // For each mesh
        for (auto i = 0; i < sc->mNumMeshes; ++i) {
            // Faces (index / 3)
            BOOST_LOG_TRIVIAL(debug) << "Number of Faces = " << mesh->mNumFaces;
            for (auto t = 0; t < mesh->mNumFaces; ++t) {
                unsigned int *ver = mesh->mFaces[t].mIndices;
                BOOST_LOG_TRIVIAL(trace) << ver[0] << " " << ver[1] << " " << ver[2];
                this->num_indices += 3;
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

                    // Vertices
                    if (mesh->HasPositions()) {
                        aiVector3D &vert = mesh->mVertices[j];
                        BOOST_LOG_TRIVIAL(trace) << vert.x << " " << vert.y << " " << vert.z;
                        mesh_vertex.push_back(vert.x);
                        mesh_vertex.push_back(vert.y);
                        mesh_vertex.push_back(vert.z);
                    }

                    // Normals
                    if (mesh->HasNormals()) {
                        // BOOST_LOG_TRIVIAL(debug) << "has Normals";
                        auto vert = mesh->mNormals[j];
                        BOOST_LOG_TRIVIAL(trace) << vert.x << " " << vert.y << " " << vert.z;
                        mesh_normal.push_back(vert.x);
                        mesh_normal.push_back(vert.y);
                        mesh_normal.push_back(vert.z);
                    }
                }
            }
        }
    } else {
        BOOST_LOG_TRIVIAL(error) << "Error: No meshes found";
    }
}
void Ea3dRenderPipeline::setShader() {
    // --------------------------------------------------------------
    //    vector<float> mesh_vertex{0.0f, 0.5f, 0.0f,
    //                            -0.5f, -0.5f, 0.0f,
    //                            0.5f, -0.5f, 0.0f};
    //
    //    vector<float> mesh_normal;
    //    vector<GLuint> mesh_index{0, 1, 2};
    // setup shader
    string vertPath = Ea3d::getShaderPath(payload, "sample");
    string fragPath = Ea3d::getShaderPath(payload, "sample");
    this->loc_shader = Ea3d::CreateShaders(vertPath, fragPath);
    BOOST_LOG_TRIVIAL(debug) << "loc_shader = " << loc_shader;
    // Pass shader into glHandler
    this->glHandler.setLocShader(loc_shader);

    // Bind vao
    glGenVertexArrays(1, &this->vaoHandle);
    glBindVertexArray(this->vaoHandle);

    // Bind vbo
    glGenBuffers(3, vboHandles);

    // Vertex data
    glBindBuffer(GL_ARRAY_BUFFER, vboHandles[0]);
    glBufferData(GL_ARRAY_BUFFER, this->mesh_vertex.size() * sizeof(float), &mesh_vertex[0],
                 GL_DYNAMIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (GLubyte *)NULL);
    glEnableVertexAttribArray(0);

    // Normal data
    glBindBuffer(GL_ARRAY_BUFFER, vboHandles[1]);
    glBufferData(GL_ARRAY_BUFFER, mesh_normal.size() * sizeof(float), &mesh_normal[0],
                 GL_DYNAMIC_DRAW);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (GLubyte *)NULL);
    glEnableVertexAttribArray(1); // Normal Data

    // Index data
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboHandles[2]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh_index.size() * sizeof(GLuint), &mesh_index[0],
                 GL_DYNAMIC_DRAW);

    //-------------------------------------------------------------------
    // set uniform matrix

    // translate
    
    glm::mat4 m_rotate1 = glm::rotate(glm::mat4(1.0f), 180.0f, glm::vec3(0.0f, 1.0f, 0.0f));
    glm::mat4 m_rotate = glm::rotate(m_rotate1, 60.0f, glm::vec3(1.0f, 0.0f, 0.0f));

    glm::mat4 m_trans = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -3.0f));

    // matrix view
    glm::mat4 m_view = glm::lookAt(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, -1.0f),
                                   glm::vec3(0.0f, 1.0f, 0.0f));
    BOOST_LOG_TRIVIAL(debug) << "m-view";
    //    for(int i = 0; i< 4; ++i)
    //    {
    //        for(int j = 0; j< 4; ++j)
    //            cout<<m_view[i][j]<<" ";
    //        cout<<endl;
    //    }

    // Model View Matrix
    this->ModelViewMatrix = m_view * m_trans;// * m_rotate;

    BOOST_LOG_TRIVIAL(debug) << "m-modelview";
    //    for(int i = 0; i< 4; ++i)
    //    {
    //        for(int j = 0; j< 4; ++j)
    //            cout<<ModelViewMatrix[i][j]<<" ";
    //        cout<<endl;
    //    }

    // Perspective Matrix
    auto wheight = this->payload->getResourceRoot()["Window"]["height"].asFloat();
    auto wwidth = this->payload->getResourceRoot()["Window"]["width"].asFloat();
    cout << wheight << " " << wwidth << " " << wwidth / wheight << endl;
    glm::mat4 m_pers = glm::perspective(45.0f, wwidth / wheight, 1.0f, 200.0f);
    BOOST_LOG_TRIVIAL(debug) << "m-pers";
    //    for(int i = 0; i< 4; ++i)
    //    {
    //        for(int j = 0; j< 4; ++j)
    //            cout<<m_pers[i][j]<<" ";
    //        cout<<endl;
    //    }

    this->MVP = m_pers * this->ModelViewMatrix;

    BOOST_LOG_TRIVIAL(debug) << "MVP";
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j)
            cout << MVP[i][j] << " ";
        cout << endl;
    }
    // normal matrix
    glm::mat3 norm = glm::mat3(glm::vec3(ModelViewMatrix[0]), glm::vec3(ModelViewMatrix[1]),
                               glm::vec3(ModelViewMatrix[2]));

    this->NormalMatrix = glm::inverse(norm);

    // -----------------------------
    this->LightPosition = glm::vec3(0., 0., 10.);
    this->Iads = glm::vec3(1., 1., 1.);

    this->Ka = glm::vec3(.2, .2, .2); // Ambient reflectivity
    this->Kd = glm::vec3(.5, .5, .5); // Diffuse reflectivity
    this->Ks = glm::vec3(.3, .3, .3); // Specular reflectivity
    this->Shininess = 64.;
}
void Ea3dRenderPipeline::glUniformSender() {
    // Send matrix to shader
    this->glHandler.sendUniform("MVP", this->MVP);
    this->glHandler.sendUniform("ModelViewMatrix", this->ModelViewMatrix);
    this->glHandler.sendUniform("NormalMatrix", this->NormalMatrix);

    this->glHandler.sendUniform("NormalMatrix", this->NormalMatrix);

    this->glHandler.sendUniform("LightPosition", this->LightPosition);
    this->glHandler.sendUniform("Kd", this->Kd);
    this->glHandler.sendUniform("Ka", this->Ka);
    this->glHandler.sendUniform("Ks", this->Ks);
    this->glHandler.sendUniform("Shininess", this->Shininess);
    this->glHandler.sendUniform("Iads", this->Iads);
}

void Ea3dRenderPipeline::draw() {
    if (this->loc_shader >= 0) {
        glUseProgram(this->loc_shader);
    } else {
        cerr << "Location of shader used by VBO cloth is not found. loc shader: "
             << this->loc_shader << endl;
    }

    this->glUniformSender();
    glBindVertexArray(this->vaoHandle);
    glDrawElements(GL_TRIANGLES, this->num_indices, GL_UNSIGNED_INT, 0);
    //    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
    //    glDrawArrays(GL_TRIANGLES, 0, 3);
}
void Ea3dRenderPipeline::execute() {
    // testing triangle
    // ------------------ path
    string vertPath = Ea3d::getShaderPath(payload, "shaderToySample");
    string fragPath = Ea3d::getShaderPath(payload, "shaderToySample");
    // -----create shader
    GLuint loc_shader = Ea3d::CreateShaders(vertPath, fragPath);

    // ------ set vbo

    //    vector<float> bufferData{0.0f, 0.5f, 0.0f, 0.5f, -0.5f, 0.0f, -0.5f, -0.5f, 0.0f};
    vector<float> bufferData{0.0f, 1.0f, 0.0f, 0.5f, -0.5f, 0.5f, -0.5f, -0.5f, 0.5f};
    GLuint vboHandle, vaoHandle;

    glGenBuffers(1, &vboHandle); // vbo
    glBindBuffer(GL_ARRAY_BUFFER, vboHandle);
    glBufferData(GL_ARRAY_BUFFER, bufferData.size() * sizeof(float), &bufferData[0],
                 GL_STATIC_DRAW);

    glGenVertexArrays(1, &vaoHandle); // vao
    glBindVertexArray(vaoHandle);     // vao

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vboHandle);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

    glUseProgram(loc_shader);

    glBindVertexArray(vaoHandle);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}
