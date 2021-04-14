#include "DXUT.h"
#include "twoBoss.h"
#include "cLenemyBullet.h"
#include "effect1.h"
#include "OBullet.h"
#include "BossBullet.h"
#include "BossEffect.h"

void twoBoss::Init()
{
	anim = new Timer;
	anim->setTimer(0.03);
	fire = new Timer;
	fire->setTimer(0.8f);
	collider = new Collider;
	voxjs = new Timer;
	voxjs->setTimer(10.0f);
	twoman = new Timer;
	twoman->setTimer(10.0f);
	collider->lpGameObject = this;
	this->collider->SetRange(150, 620);
	OBJECT->AddCollision(collider);
	Hp = 4500;
	Speed = 200;
}

void twoBoss::Update()
{
	this->collider->SetRange(150, 620);


	D3DXVec2Normalize(&dir, &dir);
	if (voxjs->Update()) {
		i++;
	}
	if (i == 3) {
		if (twoman->Update()) {
			i = 0;
		}
	}
	switch (i)
	{
		case 1:
			one();
			break;
		case 2:
			two();
			break;
		case 3:
			serd();
			break;
	}

	if (anim->Update()) {
		enem++;
	}
	if (enem >= 3) {
		enem = 0;
	} 
	if (Hp <= 1) {
		OBJECT->AddObject("BossEffect", new BossEffect, vPos, EFFECT);
		isDestroy = true;
	}
	
	MATH->Lerp<Vector2>(&vPos, vPos, Vector2(600, 60), 4.0f);
	
}

void twoBoss::Render()
{
	IMAGE->FindImage("Boss_Body")->CenterRender(vPos);

	IMAGE->FINDVECIMAGE("fly", 3)->FINDIMAGE(enem)->CenterRender(Vector2(vPos.x, vPos.y+115));
	IMAGE->FindImage("Health")->Render({ 170, 40 }, 0, { Hp / 1800,1 });//3000 1200     4500 

}

void twoBoss::Release()
{
	SAFE_DELETE(anim);
	SAFE_DELETE(collider);
}

void twoBoss::onCollisionStay(Object* obj) 
{
	switch (obj->m_Tag)
	{
	case BULLET:
		Hp -= obj->Damage;
		break;
	case SKILL:
		Hp -= obj->Damage;
		break;
	}
}

void twoBoss::onCollisionExit(Object* obj)
{
}

void twoBoss::one()
{
	if (fire->Update()) {
		for (int i = -4.0; i <= 4.0f; i += 1.0f)
		{
			OBJECT->AddObject("OBullet", new OBullet(Vector2(i, -1)), vPos, EBULLET);
		}
	}
}

void twoBoss::two()
{
	if (fire->Update()) {
		for (int i = 0; i < 36; i++)
		{
			OBJECT->AddObject("EnemyBullet", new cLenemyBullet(MATH->RotateVec(Vector2(0, 1), i * 10)), vPos, EBULLET);
		}
	}
}

void twoBoss::serd() {
	float x = vPos.x + cosf(D3DXToRadian(rot)) * 50;
	float y = vPos.y + sinf(D3DXToRadian(rot)) * 50;
	dir = D3DXVECTOR2(cosf(D3DXToRadian(rot)), sinf(D3DXToRadian(rot)));
	rot += 137;//137
	float x1 = vPos.x + cosf(D3DXToRadian(rot1)) * 50;
	float y1 = vPos.y + sinf(D3DXToRadian(rot1)) * 50;
	dir1 = D3DXVECTOR2(cosf(D3DXToRadian(rot1)), sinf(D3DXToRadian(rot1)));
	rot1 += 32;//137

	OBJECT->AddObject("BossBullet", new BossBullet(Vector2{ x1, y1 }, dir1), vPos, EBULLET);
	OBJECT->AddObject("BossBullet", new BossBullet(Vector2{ x, y }, dir), vPos, EBULLET);

}