#include "DXUT.h"
#include "tpfhBullet.h"

tpfhBullet::tpfhBullet()
{
}

tpfhBullet::~tpfhBullet()
{
}

void tpfhBullet::Init()
{
	rhdthr = new Timer;
	rhdthr->setTimer(10.0f);
	collider = new Collider;
	collider->lpGameObject = this;
	this->collider->SetRange(27, 44);
	OBJECT->AddCollision(collider);
	Damage = 0.2;
	Speed = 1000;
}

void tpfhBullet::Update()
{
	this->collider->SetRange(27, 44);
	vPos.y += Speed * D_TIME;
}

void tpfhBullet::Render()
{
	IMAGE->FindImage("Bullet_EN")->CenterRender(vPos);
}

void tpfhBullet::Release()
{
	SAFE_DELETE(collider);
	SAFE_DELETE(rhdthr);
}

void tpfhBullet::onCollisionStay(Object* obj)
{
	switch (obj->m_Tag)
	{
	case PLAYER:
		isDestroy = true;
		break;
	case SKILL:
		isDestroy = true;
		break;
	}
}

void tpfhBullet::onCollisionExit(Object* obj)
{
}
