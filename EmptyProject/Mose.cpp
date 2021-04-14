#include "DXUT.h"
#include "Mose.h"

void Mose::Init()
{
    collider = new Collider;
    collider->lpGameObject = this;
    this->collider->SetRange(10, 10);
    OBJECT->AddCollision(collider);

    GetCursorPos(&pt);

    ScreenToClient(DXUTGetHWND(), &pt);

    isCo = false;
}

void Mose::Update()
{
    GetCursorPos(&pt);
    ScreenToClient(DXUTGetHWND(), &pt);

    this->collider->SetRange(10, 10);

    vPos = Vector2(pt.x, pt.y);
}

void Mose::Render()
{
}

void Mose::Release()
{
    SAFE_DELETE(collider);
}

void Mose::onCollisionStay(Object* obj)
{
}

void Mose::onCollisionExit(Object* obj)
{
}