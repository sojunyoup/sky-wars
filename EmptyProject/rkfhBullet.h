#pragma once
#include "Object.h"
class rkfhBullet :
    public Object
{
private:
    float dir;
    Timer* rhdthr;
    Vector2 direction;
public:
    rkfhBullet();
    ~rkfhBullet();

    // Object을(를) 통해 상속됨
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
    virtual void onCollisionStay(Object* obj) override;
    virtual void onCollisionExit(Object* obj) override;
};

