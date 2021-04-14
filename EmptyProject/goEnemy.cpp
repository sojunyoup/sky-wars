#include "DXUT.h"
#include "goEnemy.h"
#include "EnemyBullet.h"
#include "effect1.h"
#include "OBullet.h"
#include"item.h"
#include"hillitem.h"

void goEnemy::Init()
{
	firetime = new Timer;
	firetime->setTimer(1.5f);
	Hp = 30;
	Damage = 0.3;

	collider = new Collider;
	collider->lpGameObject = this;
	this->collider->SetRange(60, 66);
	OBJECT->AddCollision(collider);
	Speed = 200;
}

void goEnemy::Update()
{
	this->collider->SetRange(60, 66);

	if (firetime->Update()) {
		for (int i = 0; i < 10; i++)
		{
			OBJECT->AddObject("OBullet", new OBullet(MATH->RotateVec(Vector2(0, 1), i * 36)), vPos, EBULLET);
		}
	}
	vPos.y += Speed * D_TIME;
	
	
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

void goEnemy::Render()
{
	IMAGE->FindImage("Health")->CenterRender({ vPos.x,vPos.y - 60 }, 0, { Hp / 250,0.3 });

	IMAGE->FindImage("goenemy")->CenterRender(vPos);
}

void goEnemy::Release()
{
	SAFE_DELETE(collider);
	SAFE_DELETE(firetime);
}

void goEnemy::onCollisionStay(Object* obj)
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

void goEnemy::onCollisionExit(Object* obj)
{
}
