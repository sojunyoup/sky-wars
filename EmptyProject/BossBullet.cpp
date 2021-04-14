#include "DXUT.h"
#include "BossBullet.h"



BossBullet::BossBullet(const D3DXVECTOR2& pos, const D3DXVECTOR2 dir1)
{
	m_dir1 = dir1;
}

BossBullet::~BossBullet()
{
}

void BossBullet::Init()
{
	collider = new Collider;
	collider->lpGameObject = this;
	this->collider->SetRange(28, 28);
	OBJECT->AddCollision(collider);

	Damage = 0.3;

}

void BossBullet::Update()
{
	this->collider->SetRange(28, 28);
	
	vPos += 250 * m_dir1 * DXUTGetElapsedTime();
}

void BossBullet::Render()
{
	IMAGE->FindImage("Bullet_Blue")->CenterRender(vPos, D3DXToRadian(180));
}

void BossBullet::Release()
{
	SAFE_DELETE(collider);
}

void BossBullet::onCollisionStay(Object* obj)
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

void BossBullet::onCollisionExit(Object* obj)
{
}
