#include "DXUT.h"
#include "rkfhBullet.h"

rkfhBullet::rkfhBullet()
{
}

rkfhBullet::~rkfhBullet()
{
}

void rkfhBullet::Init()
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

void rkfhBullet::Update()
{
	this->collider->SetRange(27, 44);
	vPos.x -= Speed * D_TIME;
}

void rkfhBullet::Render()
{
	IMAGE->FindImage("rkfh")->CenterRender(vPos);
}

void rkfhBullet::Release()
{
	SAFE_DELETE(collider);
	SAFE_DELETE(rhdthr);
}

void rkfhBullet::onCollisionStay(Object* obj)
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

void rkfhBullet::onCollisionExit(Object* obj)
{
}
