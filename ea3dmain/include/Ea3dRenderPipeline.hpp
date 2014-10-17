
#ifndef EA3D_Ea3dRenderPipeline_hpp
#define EA3D_Ea3dRenderPipeline_hpp

// all resource get from this paload
#include "Ea3dGLHandler.hpp"
#include "Ea3dPayload.hpp"
class Ea3dRenderPipeline {

  public:
    Ea3dRenderPipeline(Ea3dPayload *_payload) : payload(_payload) {}

    void iniPipeline();
    void execute();
    void setModel();
    void loadModel();
    bool setShader();
    virtual ~Ea3dRenderPipeline() {}

  private:
    Ea3dGLHandler *glHandler;
    Ea3dPayload *payload;
};

#endif
