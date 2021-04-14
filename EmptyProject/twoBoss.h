#pragma once
#include "Object.h"

class twoBoss :
    public Object
{
private:
    int enem = 0;
    Timer* anim;
    Timer* fire;
    Timer* voxjs;
    Timer* twoman;
    int i = 1;
    int rot = 0;
    D3DXVECTOR2 dir;
    int rot1 = 0;
    D3DXVECTOR2 dir1;
public:
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
    virtual void onCollisionStay(Object* obj) override;
    virtual void onCollisionExit(Object* obj) override;

    void one();
    void two();
    void serd();
};

