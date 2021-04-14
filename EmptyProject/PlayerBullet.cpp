#include "DXUT.h"
#include "PlayerBullet.h"

PlayerBullet::PlayerBullet(const Vector2& direction)
	:direction(direction)
{
}

PlayerBullet::~PlayerBullet()
{
}

void PlayerBullet::Init()
{
	rhdthr = new Timer;
	rhdthr->setTimer(10.0f);
	collider = new Collider;
	collider->lpGameObject = this;
	this->collider->SetRange(27, 40);
	OBJECT->AddCollision(collider);
	Damage = 2;
	Speed = 1000;
	dir = 0;
}

void PlayerBullet::Update()
{
	this->collider->SetRange(27, 40);
	dir = atan2f(vPos.y, vPos.x);
	vPos -= direction * Speed * D_TIME;
	if (OBJECT->item == 1) {
		Speed = 2000;
	}
	else if (OBJECT->item == 0) {
		Speed = 1000;
	}
	
}

void PlayerBullet::Render()
{
	IMAGE->FindImage("Bullet_PL")->CenterRender(vPos, D3DXToRadian(dir));
}

void PlayerBullet::Release()
{
	SAFE_DELETE(collider); 
	SAFE_DELETE(rhdthr);
}

void PlayerBullet::onCollisionStay(Object* obj)
{
	switch (obj->m_Tag)
	{
	case ENEMY:
		isDestroy = true;
		break;
	}
}

void PlayerBullet::onCollisionExit(Object* obj)
{
}
