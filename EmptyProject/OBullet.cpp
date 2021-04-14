#include "DXUT.h"
#include "OBullet.h"

OBullet::OBullet(const Vector2& direction)
	:direction(direction)
{
}


OBullet::~OBullet()
{
}

void OBullet::Init()
{
	collider = new Collider;
	collider->lpGameObject = this;
	this->collider->SetRange(28, 28);
	OBJECT->AddCollision(collider);
	Damage = 0.3;
	Speed = 300;
	dir = 0;
}

void OBullet::Update()
{
	this->collider->SetRange(28, 28);
	dir = atan2f(vPos.y, vPos.x);
	vPos -= Speed * direction * D_TIME;
}

void OBullet::Render()
{
	IMAGE->FindImage("Bulleet_Circle")->CenterRender(vPos, D3DXToRadian(dir));
}

void OBullet::Release()
{
	SAFE_DELETE(collider);
}

void OBullet::onCollisionStay(Object* obj)
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

void OBullet::onCollisionExit(Object* obj)
{
}
