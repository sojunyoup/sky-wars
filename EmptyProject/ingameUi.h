#pragma once
#include "Object.h"
class ingameUi :
    public Object
{
private:
    char temp[10000];
    char hp[10000];

    D3DXCOLOR color;
    // Object을(를) 통해 상속됨
public:
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
    virtual void onCollisionStay(Object* obj) override;
    virtual void onCollisionExit(Object* obj) override;
};

