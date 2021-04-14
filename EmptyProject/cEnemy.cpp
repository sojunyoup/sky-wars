#include "DXUT.h"
#include "cEnemy.h"
#include "EnemyBullet.h"
#include "effect1.h"
#include "BossBullet.h"
#include "item.h"
#include"hillitem.h"

void cEnemy::Init()
{
	Hp = 30;
	Damage = 0.3;
	firet = new Timer;
	firet->setTimer(0.08f);
	collider = new Collider;
	collider->lpGameObject = this;
	this->collider->SetRange(101, 91);
	OBJECT->AddCollision(collider);
}

void cEnemy::Update()
{
	this->collider->SetRange(101, 91);
	float x = vPos.x + cosf(D3DXToRadian(rot)) * 50;
	float y = vPos.y + sinf(D3DXToRadian(rot)) * 50;
	dir = D3DXVECTOR2(cosf(D3DXToRadian(rot)), sinf(D3DXToRadian(rot)));
	D3DXVec2Normalize(&dir, &dir);
	rot += 5;//137
	if(firet->Update())
		OBJECT->AddObject("BossBullet", new BossBullet(Vector2{ x, y }, dir), Vector2(vPos.x, vPos.y - 10), EBULLET);
	vPos.y += 350 * D_TIME;
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

void cEnemy::Render()
{
	IMAGE->FindImage("Health")->CenterRender({ vPos.x,vPos.y - 60 }, 0, { Hp / 250,0.3 });

	IMAGE->FindImage("goenemy")->CenterRender(vPos);
}

void cEnemy::Release()
{
	SAFE_DELETE(firet); 
		SAFE_DELETE(collider);
}

void cEnemy::onCollisionStay(Object* obj)
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

void cEnemy::onCollisionExit(Object* obj)
{
}
