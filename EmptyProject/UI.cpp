#include "DXUT.h"
#include "UI.h"

void UI::Init()
{
	OBJECT->score = 0;

	color = {
		255,255,255,255
	};

	sprintf(temp, "SCORE:%d", OBJECT->score);
}

void UI::Update()
{
	OBJECT->score += 10 * D_TIME;
	sprintf(temp, "SCORE:%d", (int)OBJECT->score);

	if (OBJECT->score <= 0) {
		OBJECT->score = 0;
	}
}

void UI::Render()
{
	IMAGE->drawText(temp, { 50,150 }, 50, color, false);
}

void UI::Release()
{
}

void UI::onCollisionStay(Object* obj)
{
}

void UI::onCollisionExit(Object* obj)
{
}
