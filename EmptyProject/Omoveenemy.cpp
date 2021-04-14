#include "DXUT.h"
#include "Omoveenemy.h"
#include "EnemyBullet.h"
#include "effect1.h"
#include"item.h"
#include"hillitem.h"

void Omoveenemy::Init()
{
	/*dir1 = m_end - vPos;
	D3DXVec2Normalize(&dir1, &dir1);*/
	firetime = new Timer;
	firetime->setTimer(0.5f);
	Hp = 30;
	Damage = 0.3;
	collider = new Collider;
	collider->lpGameObject = this;
	this->collider->SetRange(101, 91);
	OBJECT->AddCollision(collider);
}

void Omoveenemy::Update()
{
	this->collider->SetRange(101, 91);

	if (OBJECT->playchoice == 1)
		m_end = OBJECT->FindObject("player")->vPos;
	if (OBJECT->playchoice == 2)
		m_end = OBJECT->FindObject("Player2")->vPos;
	dir1 = m_end - vPos;

	m_fRot = atan2f(dir1.y, dir1.x);

	if (vPos.x < 600) {
		dir = cosf(D3DXToRadian(rot));
		rot -= 2;
		vPos.x += 800 * dir * DXUTGetElapsedTime();
		vPos.y += 200 * D_TIME;
	}
	else{
		dir = cosf(D3DXToRadian(rot));
		rot -= 2;
		vPos.x -= 800 * dir * DXUTGetElapsedTime();
		vPos.y += 200 * D_TIME;
	}
	if (firetime->Update())
		OBJECT->AddObject("ebullet", new EnemyBullet, vPos, EBULLET);
	if (Hp <= 0)
	{
		OBJECT->score += 30;
		OBJECT->AddObject("cEffect", new effect1, vPos, EFFECT);
		int a = rand() % 5;
		if (a == 0)
			OBJECT->AddObject("item", new item, vPos, ITEM);
		else if (a == 1) {
			OBJECT->AddObject("hillitem", new hillitem, vPos, ITEM);
		}
		isDestroy = true;
	}
}

void Omoveenemy::Render()
{
	IMAGE->FindImage("Lookenemy")->CenterRender(vPos, m_fRot - 90);
}

void Omoveenemy::Release()
{
	SAFE_DELETE(firetime);
	SAFE_DELETE(collider);
}

void Omoveenemy::onCollisionStay(Object* obj)
{
	switch (obj->m_Tag)
	{
	case BULLET:
		Hp -= obj->Damage;
		break;
	case SKILL:
		Hp = 0;
		//isDestroy = true;
		break;
	}
}

void Omoveenemy::onCollisionExit(Object* obj)
{
}
