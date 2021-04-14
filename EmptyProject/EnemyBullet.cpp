#include "DXUT.h"
#include "EnemyBullet.h"
//#include"cEffect.h"


EnemyBullet::EnemyBullet()
{
	m_speed = 500;
	dir1 = m_end - vPos;
	D3DXVec2Normalize(&dir1, &dir1);
}

EnemyBullet::~EnemyBullet()
{
}

void EnemyBullet::Init()
{
	collider = new Collider;
	collider->lpGameObject = this;
	this->collider->SetRange(28, 28);
	OBJECT->AddCollision(collider);
	if(OBJECT->playchoice == 1)
 		m_end = OBJECT->FindObject("player")->vPos;
	if (OBJECT->playchoice == 2)
		m_end = OBJECT->FindObject("Player2")->vPos;
	Damage = 0.3;
	Speed = 100;
	dir = 0;
}

void EnemyBullet::Update()
{
	this->collider->SetRange(28, 28);

	if (i == 0) {
		dir = atan2f(vPos.y, vPos.x);
		if (OBJECT->playchoice == 1)
			m_end = OBJECT->FindObject("player")->vPos;
		if (OBJECT->playchoice == 2)
			m_end = OBJECT->FindObject("Player2")->vPos;
		dir1 = m_end - vPos;
		D3DXVec2Normalize(&dir1, &dir1);
		i = 1;
	}
	else if (i == 1) {
		vPos += m_speed * dir1 * DXUTGetElapsedTime();
	}
}

void EnemyBullet::Render()
{
	IMAGE->FindImage("Bullet_Blue")->CenterRender(vPos, D3DXToRadian(dir));
}

void EnemyBullet::Release()
{
	SAFE_DELETE(collider);
}

void EnemyBullet::onCollisionStay(Object* obj)
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

void EnemyBullet::onCollisionExit(Object* obj)
{
}
