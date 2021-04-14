#pragma once
#include "Object.h"
class guideButten :
    public Object
{
private:
    bool sco;
    bool iskeyck;
    Vector2 vGui = { WINSIZEX / 2, -450 };
    Vector2 vUGui = { 320, -WINSIZEY / 2 + 50 };
    Vector2 vCmra = { WINSIZEX / 2, WINSIZEY / 2 };
    Vector2 vtitle;
public:
    // Object을(를) 통해 상속됨
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
    virtual void onCollisionStay(Object* obj) override;
    virtual void onCollisionExit(Object* obj) override;
};