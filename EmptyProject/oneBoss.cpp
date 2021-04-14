#include "DXUT.h"
#include "oneBoss.h"
#include "cLenemyBullet.h"
#include "effect1.h"
#include "OBullet.h"
#include "BossBullet.h"
#include "BossEffect.h"

void oneBoss::Init()
{
	Hp = 3000;//3000
	firetime = new Timer;
	firetime->setTimer(1.5f);

	bossgo = new Timer;
	bossgo->setTimer(2.0);

	bossmove = new Timer;
	bossmove->setTimer(3.0f);

	bosswarning = new Timer;
	bosswarning->setTimer(0.1f);

	collider = new Collider;
	collider->lpGameObject = this;
	this->collider->SetRange(150, 620);
	OBJECT->AddCollision(collider);

	Speed = 200;
	bosimg = Vector2(600, WINSIZEY + 20);
	isbossgo = false;
	vPos = Vector2(600, -100);
}

void oneBoss::Update()
{
	float x = vPos.x + cosf(D3DXToRadian(rot)) * 50;
	float y = vPos.y + sinf(D3DXToRadian(rot)) * 50;
	dir = D3DXVECTOR2(cosf(D3DXToRadian(rot)), sinf(D3DXToRadian(rot)));
	D3DXVec2Normalize(&dir, &dir);
	rot += 82;//137

	this->collider->SetRange(150, 620);

	if (bosimg.y <= -350) {
		isbossgo = true;
		if (bossmove->Update()) {
			bmove++;
			if (bmove > 1) {
				bmove = 0;
			}
		}
		/*if (bmove == 1)
			MATH->Lerp<Vector2>(&vPos, vPos, Vector2(600 + 200, 110), 2.0f);
		else if (bmove == 0)
			MATH->Lerp<Vector2>(&vPos, vPos, Vector2(600 - 200, 110), 3.0f);*/
	}
	if (firetime->Update() && isbossgo == true && Hp >= 1800) {
		for (int i = 0; i < 36; i++)
		{
			OBJECT->AddObject("EnemyBullet", new cLenemyBullet(MATH->RotateVec(Vector2(0, 1), i * 10)), vPos, EBULLET);
		}
	}
	if (Hp < 1800) {
		OBJECT->AddObject("BossBullet", new BossBullet(Vector2{ x, y }, dir), vPos, EBULLET);
	}

	if (vPos.y <= 60 && isbossgo == true) {
		vPos.y += Speed * D_TIME;
	}
	if (Hp <= 0)
	{
		OBJECT->score += 10;
		OBJECT->AddObject("BossEffect", new BossEffect, vPos, EFFECT);
		isDestroy = true;
	}
	bosimg.y -= 600 * D_TIME;

	if (bosswarning->Update()) {
		enem++;
	}
}
//3621
void oneBoss::Render()
{
	if (bosimg.y > -400) {
		IMAGE->FindImage("1stboss")->CenterRender(bosimg, 135.1, Vector2(1.3f, 1.3f));
	}
	IMAGE->FindImage("1stboss")->CenterRender(vPos, 0, Vector2(0.8f,0.8f));
	if(enem <= 8)
		IMAGE->FINDVECIMAGE("bosswarning", 9)->FINDIMAGE(enem)->CenterRender(Vector2(600, WINSIZEY/2));
	//º¸½º ÇÇ
	IMAGE->FindImage("Health")->Render({ 170, 40 },0 , { Hp / 1200,1 });

}

void oneBoss::Release()
{
	SAFE_DELETE(collider);
	SAFE_DELETE(firetime);
	SAFE_DELETE(bossgo);
	SAFE_DELETE(bossmove);
	
}

void oneBoss::onCollisionStay(Object* obj)
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

void oneBoss::onCollisionExit(Object* obj)
{
}
