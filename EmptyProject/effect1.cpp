#include "DXUT.h"
#include "effect1.h"

void effect1::Init()
{
	antimer = new Timer;
	antimer->setTimer(0.03f);
	i = rand() % 1;
}

void effect1::Update()
{
	if (antimer->Update()) {
		enem++;
	}
	if (enem >= 7) {
		isDestroy = true;
	}
}

void effect1::Render()
{
	if(i == 0)
		IMAGE->FINDVECIMAGE("effect1", 8)->FINDIMAGE(enem)->CenterRender(vPos);
	if (i == 1)
		IMAGE->FINDVECIMAGE("effect2", 8)->FINDIMAGE(enem)->CenterRender(vPos);

}

void effect1::Release()
{
	SAFE_DELETE(antimer);
}

void effect1::onCollisionStay(Object* obj)
{
}

void effect1::onCollisionExit(Object* obj)
{
}
