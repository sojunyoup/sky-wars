#pragma once
#include "Object.h"
class EnemyBullet :
    public Object
{
private:
    int m_speed;
    float dir;
    Vector2 dir1;
    Vector2 m_end;
    int i = 0;
    Vector2 direction;

public:
    EnemyBullet();
    ~EnemyBullet();
    // Object을(를) 통해 상속됨
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
    virtual void onCollisionStay(Object* obj) override;
    virtual void onCollisionExit(Object* obj) override;
};

