#include "DXUT.h"
#include "LookEnemy.h"
#include "EnemyBullet.h"
#include "effect1.h"
#include "item.h"
#include"hillitem.h"

void LookEnemy::Init()
{
	Damage = 0.3;
	firetime = new Timer;
	firetime->setTimer(1.0f);
	gogo = new Timer;
	gogo->setTimer(3.0f);
	i = (rand() % 1000) + 100;
	j = (rand() % 100) + 70;
	Hp = 20;
	collider = new Collider;
	collider->lpGameObject = this;
	this->collider->SetRange(101, 91);
	OBJECT->AddCollision(collider);
}

void LookEnemy::Update()
{
	this->collider->SetRange(101, 91);
	if (gogo->Update()) {
		isgo = true;
	}
	if(isgo == false){
		MATH->Lerp<Vector2>(&vPos, vPos, Vector2(i, j), 3.0f);
		if (firetime->Update())
			OBJECT->AddObject("ebullet", new EnemyBullet, vPos, EBULLET);
	}
	else if (isgo == true) {
		vPos.y += speed * D_TIME;
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
}

void LookEnemy::Render()
{
	IMAGE->FindImage("Lookenemy")->CenterRender(vPos);
	IMAGE->FindImage("Health")->CenterRender({ vPos.x,vPos.y  - 60}, 0, { Hp / 250,0.3});

}

void LookEnemy::Release()
{
	SAFE_DELETE(firetime);
	SAFE_DELETE(gogo);
	SAFE_DELETE(collider);
}

void LookEnemy::onCollisionStay(Object* obj)
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

void LookEnemy::onCollisionExit(Object* obj)
{
}
