#pragma once
#include "Object.h"
class OBullet :
    public Object
{
private:
    int m_speed;
    float dir;
    time_t start = timeGetTime();
    Vector2 direction;

public:
    OBullet(const Vector2& direction);
    ~OBullet();
    // Object을(를) 통해 상속됨
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
    virtual void onCollisionStay(Object* obj) override;
    virtual void onCollisionExit(Object* obj) override;
};

