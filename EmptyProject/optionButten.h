#pragma once
#include "Object.h"
class optionButten :
    public Object
{
private:
    bool sco;
    Vector2 VOption;
    Vector2 vtitle;
public:
    // Object��(��) ���� ��ӵ�
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
    virtual void onCollisionStay(Object* obj) override;
    virtual void onCollisionExit(Object* obj) override;
};