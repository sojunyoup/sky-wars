#include "DXUT.h"
#include "lerpEnemy.h"
#include "EnemyBullet.h"
#include "effect1.h"
#include"BossBullet.h"
#include "OBullet.h"
#include "item.h"
#include"hillitem.h"

void lerpEnemy::Init()
{
	Hp = 200;
	Damage = 0.1;
	fire = new Timer;
	fire->setTimer(1.0f);
	collider = new Collider;
	collider->lpGameObject = this;
	this->collider->SetRange(101, 91);
	OBJECT->AddCollision(collider);
}

void lerpEnemy::Update()
{
	this->collider->SetRange(101, 91);

	if (OBJECT->playchoice == 1)
		vPlayer = OBJECT->FindObject("player")->vPos;
	if (OBJECT->playchoice == 2)
		vPlayer = OBJECT->FindObject("Player2")->vPos;

	if (vPos.x < 600) {
		if (vPos.x < vPlayer.x) {
			vPos.x += 80 * D_TIME;
		}
		else
		{
			vPos.x -= 80 * D_TIME;
		}
		if (vPlayer.x > 600) {
			MATH->Lerp<Vector2>(&vPos, vPos, Vector2(200, 200), 4.0f);

		}
		if (vPos.y < vPlayer.y)
			vPos.y += 200 * D_TIME;
		else if (vPos.y > vPlayer.y)
			vPos.y -= 200 * D_TIME;
	}
	else if (vPos.x > 600) {
		if (vPos.x < vPlayer.x) {
			vPos.x += 80 * D_TIME;
		}
		else
		{
			vPos.x -= 80 * D_TIME;
		}
		if (vPlayer.x < 600) {
			MATH->Lerp<Vector2>(&vPos, vPos, Vector2(1000, 200), 4.0f);
		}
		if (vPos.y < vPlayer.y)
			vPos.y += 200 * D_TIME;
		else if (vPos.y > vPlayer.y)
			vPos.y -= 200 * D_TIME;
	}
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
	if (fire->Update()) {
		for (int i = -1.0; i <= 1.0f; i+= 1.0f)
		{
			OBJECT->AddObject("OBullet", new OBullet(Vector2(i, -1)), vPos, EBULLET);
		}
	}
}

void lerpEnemy::Render()
{
	IMAGE->FindImage("Health")->CenterRender({ vPos.x,vPos.y - 60 }, 0, { Hp / 250,0.3 });

	IMAGE->FindImage("goenemy")->CenterRender(vPos);
}

void lerpEnemy::Release()
{
	SAFE_DELETE(collider); 
	SAFE_DELETE(fire);
}

void lerpEnemy::onCollisionStay(Object* obj)
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

void lerpEnemy::onCollisionExit(Object* obj)
{
}
