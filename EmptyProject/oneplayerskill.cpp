#include "DXUT.h"
#include "oneplayerskill.h"
#include "BossEffect.h"

oneplayerskill::oneplayerskill()
{
}

oneplayerskill::~oneplayerskill()
{
}

void oneplayerskill::Init()
{
	gogo = new Timer;
	gogo->setTimer(1.0f);

	stop = new Timer;
	stop->setTimer(1.1f);

	collider = new Collider;
	collider->lpGameObject = this;
	OBJECT->AddCollision(collider);
	Damage = 10;
	Speed = 300;
}

void oneplayerskill::Update()
{

	vPos.y -= Speed * D_TIME;
	if (gogo->Update()) {
		Speed = 0;
		this->collider->SetRange(1600, 900);
		OBJECT->AddObject("BossEffect", new BossEffect, vPos, EFFECT);
	}
	if (stop->Update()) {
		isDestroy = true;
	}
}

void oneplayerskill::Render()
{
	IMAGE->FindImage("boom")->CenterRender(vPos);
}

void oneplayerskill::Release()
{
	SAFE_DELETE(collider);
	SAFE_DELETE(gogo);
	SAFE_DELETE(stop);
}

void oneplayerskill::onCollisionStay(Object* obj)
{
}

void oneplayerskill::onCollisionExit(Object* obj)
{
}
