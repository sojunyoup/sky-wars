#pragma once
#include "Object.h"
class Mose :
    public Object
{
private:
    POINT pt;

    bool isCo;
public:
    // Object��(��) ���� ��ӵ�
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
    virtual void onCollisionStay(Object* obj) override;
    virtual void onCollisionExit(Object* obj) override;
};