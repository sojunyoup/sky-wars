#pragma once
#include "Object.h"
class Player :
    public Object
{
private:
    Timer* bulletSpeed;
    Timer* shieldtimer;
    Timer* firespeed;
    Timer* skill1;
    Timer* skillcool;
    Timer* skillcoo2;
    Timer* skillcoo3;
    Timer* rhdthr;
    Timer* rhdthr1;

    bool skill = true;
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

