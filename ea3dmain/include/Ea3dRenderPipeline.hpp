
#ifndef EA3D_Ea3dRenderPipeline_hpp
#define EA3D_Ea3dRenderPipeline_hpp

// all resource get from this paload
#include <assimp/Importer.hpp> // C++ importer interface
#include "Ea3dGLHandler.hpp"
#include "Ea3dPayload.hpp"
#include <vector>
class Ea3dRenderPipeline {

  public:
    Ea3dRenderPipeline(Ea3dPayload *_payload) : payload(_payload), num_indices(0){}

    void iniPipeline();
    void execute();
    void draw();
    void glUniformSender();
    void setModel();
    void loadModel();
    void setShader();
    
    virtual ~Ea3dRenderPipeline() {}

  private:
    Ea3dGLHandler glHandler;
    Ea3dPayload *payload;
    Assimp::Importer importer;
    GLint loc_shader;
    
    GLuint vaoHandle;
    GLuint vboHandles[3];
    
    /*uniform variable*/
    mat4 ModelViewMatrix;
    mat3 NormalMatrix;
    mat4 MVP, iMVP;
    mat4 m_screen;
    
    /*light*/
    vec4 LightPosition;
    vec3 Ka;
    vec3 Kd;
    vec3 Ks;
    vec3 Iads;
    float Shininess;
    
    /*Geometry data*/
    GLsizei num_indices;
    std::vector<float> mesh_vertex;
    std::vector<float> mesh_normal;
    std::vector<GLuint> mesh_index;
    
};

#endif
