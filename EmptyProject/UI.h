#pragma once
#include "Object.h"
class UI :
    public Object
{
private:
    char temp[10000];
    D3DXCOLOR color;
public:
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
    virtual void onCollisionStay(Object* obj) override;
    virtual void onCollisionExit(Object* obj) override;
};



