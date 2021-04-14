#pragma once
#include "Object.h"

class oneBoss :
    public Object
{
private:
    int enem = 0;
    Timer* firetime;
    Timer* bossgo;
    Timer* bossmove;
    Timer* bosswarning;
    int bmove = 0;
    Vector2 bosimg;
    int rot = 0;
    D3DXVECTOR2 dir;

    bool isbossgo;
public:
    
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
    virtual void onCollisionStay(Object* obj) override;
    virtual void onCollisionExit(Object* obj) override;
};

