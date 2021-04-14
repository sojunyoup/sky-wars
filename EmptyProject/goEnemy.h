#pragma once
#include "Object.h"

class goEnemy :
    public Object
{
private:
    Timer* firetime;
public:
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
    virtual void onCollisionStay(Object* obj) override;
    virtual void onCollisionExit(Object* obj) override;
};

