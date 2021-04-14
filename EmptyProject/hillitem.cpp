#include "DXUT.h"
#include "hillitem.h"
#include "EnemyBullet.h"
#include "effect1.h"
#include"BossBullet.h"

void hillitem::Init()
{
	collider = new Collider;
	collider->lpGameObject = this;
	this->collider->SetRange(54, 64);
	OBJECT->AddCollision(collider);
}

void hillitem::Update()
{
	this->collider->SetRange(54, 64);
	vPos.y += 100 * D_TIME;
}

void hillitem::Render()
{
	IMAGE->FindImage("Healon")->CenterRender(vPos);
}

void hillitem::Release()
{
	SAFE_DELETE(collider);
}

void hillitem::onCollisionStay(Object* obj)
{
	switch (obj->m_Tag)
	{
	case PLAYER:
		OBJECT->hilltem = 1;
		isDestroy = true;
		break;
	}
}

void hillitem::onCollisionExit(Object* obj)
{
}
