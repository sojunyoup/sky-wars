#include "DXUT.h"
#include "BossEffect.h"

void BossEffect::Init()
{
	antimer = new Timer;
	antimer->setTimer(0.15f);
	i = rand() % 1;
}

void BossEffect::Update()
{
	if (antimer->Update()) {
		enem++;
	}
	if (enem >= 3) {
		isDestroy = true;
	}
}

void BossEffect::Render()
{
	IMAGE->FINDVECIMAGE("effect3", 4)->FINDIMAGE(enem)->CenterRender(vPos);
}

void BossEffect::Release()
{
	SAFE_DELETE(antimer);
}

void BossEffect::onCollisionStay(Object* obj)
{
}

void BossEffect::onCollisionExit(Object* obj)
{
}
