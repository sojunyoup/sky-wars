#pragma once
#include "Object.h"
class tpfhBullet :
    public Object
{
private:
    float dir;
    Timer* rhdthr;
    Vector2 direction;
public:
    tpfhBullet();
    ~tpfhBullet();

    // Object��(��) ���� ��ӵ�
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
    virtual void onCollisionStay(Object* obj) override;
    virtual void onCollisionExit(Object* obj) override;
};

