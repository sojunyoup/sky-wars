#pragma once
#include "Object.h"
class Player2 :
    public Object
{
private:
    Timer* rhdthr;
    Timer* rhdthr1;
    Timer* bulletSpeed;
    Timer* firespeed;
    Timer* skillcool;
    Timer* skillcoo2;

    Timer* skillcoo3;
    Timer* skillcoo4;

    int enem = 0;
    int enem1 = 5;
    char stage[10000];
    bool Isstart;

    // Object을(를) 통해 상속됨
public:
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
    virtual void onCollisionStay(Object* obj) override;
    virtual void onCollisionExit(Object* obj) override;
};

