#pragma once
#include "Object.h"
class oneplayerskill :
    public Object
{
private:
    Timer* gogo;
    Timer* stop;
public:
    oneplayerskill();
    ~oneplayerskill();

    // Object��(��) ���� ��ӵ�
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
    virtual void onCollisionStay(Object* obj) override;
    virtual void onCollisionExit(Object* obj) override;
};

