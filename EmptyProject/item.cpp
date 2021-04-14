#include "DXUT.h"
#include "item.h"
#include "EnemyBullet.h"
#include "effect1.h"
#include"BossBullet.h"

void item::Init()
{
	collider = new Collider;
	collider->lpGameObject = this;
	this->collider->SetRange(54, 64);
	OBJECT->AddCollision(collider);
}

void item::Update()
{
	this->collider->SetRange(54, 64);
	vPos.y += 100 * D_TIME;
}

void item::Render()
{
	IMAGE->FindImage("Inc_Atk")->CenterRender(vPos);
}

void item::Release()
{
	SAFE_DELETE(collider);
}

void item::onCollisionStay(Object* obj)
{
	switch (obj->m_Tag)
	{
	case PLAYER:
		OBJECT->item = 1;
		isDestroy = true;
		break;
	}
}

void item::onCollisionExit(Object* obj)
{
}
