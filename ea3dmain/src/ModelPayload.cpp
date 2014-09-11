#include "ModelPayload.hpp"

ModelPayload* ModelPayload::modelPayload = nullptr;

ModelPayload* ModelPayload::getInstance(){
    if (modelPayload == nullptr){
        modelPayload = new ModelPayload();
    }
    return modelPayload;
}