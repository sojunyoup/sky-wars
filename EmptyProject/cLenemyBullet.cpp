#include "DXUT.h"
#include "cLenemyBullet.h"
//#include"cEffect.h"


cLenemyBullet::cLenemyBullet(const Vector2& direction)
	:direction(direction)
{
	m_speed = 800;

	dir1 = m_end - vPos;
	D3DXVec2Normalize(&dir1, &dir1);
}


cLenemyBullet::~cLenemyBullet()
{
}

void cLenemyBullet::Init()
{
	playervec = new Timer;
	playervec->setTimer(0.9f);
	collider = new Collider;
	collider->lpGameObject = this;
	this->collider->SetRange(40, 40);
	OBJECT->AddCollision(collider);
	Damage = 0.3;
	Speed = 300;
	dir = 0;
	start = 6000;
}

void cLenemyBullet::Update()
{
	this->collider->SetRange(40, 40);
	if (i == 0) {
		dir = atan2f(vPos.y, vPos.x);
		vPos -= Speed * direction * D_TIME;
		if (playervec->Update()) {
			if (OBJECT->playchoice == 1)
				m_end = OBJECT->FindObject("player")->vPos;
			if (OBJECT->playchoice == 2)
				m_end = OBJECT->FindObject("Player2")->vPos;
			dir1 = m_end - vPos;
			D3DXVec2Normalize(&dir1, &dir1);
			i = 1;
		}
	}

	else if (i == 1) {
		vPos += m_speed * dir1 * DXUTGetElapsedTime();
	}

}

void cLenemyBullet::Render()
{
	IMAGE->FindImage("Bulleet_Circle")->CenterRender(vPos, D3DXToRadian(dir));
}

void cLenemyBullet::Release()
{
	SAFE_DELETE(collider);
	SAFE_DELETE(playervec);
}

void cLenemyBullet::onCollisionStay(Object* obj)
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

void cLenemyBullet::onCollisionExit(Object* obj)
{
}
