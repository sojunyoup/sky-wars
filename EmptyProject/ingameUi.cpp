#include "DXUT.h"
#include "ingameUi.h"

void ingameUi::Init()
{
	color = {
		255,255,255,255
	};
	sprintf(temp, "SCORE:%d", OBJECT->score);
	sprintf(hp, "100 / %d", OBJECT->pHp);
	
}

void ingameUi::Update()
{
	OBJECT->score += 10 * D_TIME;
	sprintf(temp, "%d", (int)OBJECT->score);
	sprintf(hp, "100 / %d", (int)OBJECT->pHp);

	if (OBJECT->score <= 0) {
		OBJECT->score = 0;
	}
}

void ingameUi::Render()
{
	IMAGE->FindImage("BG")->CenterRender(Vector2(1400, WINSIZEY / 2)); 
 	IMAGE->drawText(temp, { 1326, 242 }, 50, color, false);
	IMAGE->FindImage("Health")->Render({ 1280,385 }, 0, { OBJECT->pHp / 150,2 });
	IMAGE->drawText(hp, { 1369, 425 }, 20, color, false);

	if (OBJECT->item == 1) {
		IMAGE->FindImage("Inc_Atk")->CenterRender(Vector2(1400 - 65, 790)); 
	}
	else {
		IMAGE->FindImage("Inc_Atknone")->CenterRender(Vector2(1400 - 65, 790));
	}
	if (OBJECT->hilltem == 1) {
		IMAGE->FindImage("Healon")->CenterRender(Vector2(1400 + 65, 790)); 
	}
	else {
		IMAGE->FindImage("Healnone")->CenterRender(Vector2(1400 + 65, 790));
	}
	
	if (OBJECT->isskill1 == 3) {
		IMAGE->FindImage("Skill_2on")->CenterRender(Vector2(1400 + 65, 593));
	}
	else{ 
		IMAGE->FindImage("Skill_2off")->CenterRender(Vector2(1400 + 65, 593));
	}
	if (OBJECT->playchoice == 1) {
		if (OBJECT->isskill2 == 1) {
			IMAGE->FindImage("Skill_1on")->CenterRender(Vector2(1400 - 65, 593));
		}
		else if (OBJECT->isskill2 == 0) {
			IMAGE->FindImage("Skill_1off")->CenterRender(Vector2(1400 - 65, 593));
		}
	}
	if (OBJECT->playchoice == 1) {
		if (OBJECT->isskill2 == 1) {
			IMAGE->FindImage("Skill_1on")->CenterRender(Vector2(1400 - 65, 593));
		}
		else if (OBJECT->isskill2 == 0) {
			IMAGE->FindImage("Skill_1off")->CenterRender(Vector2(1400 - 65, 593));
		}
	}
	else if (OBJECT->playchoice == 2) {
		if (OBJECT->isskill3 == 1) {
			IMAGE->FindImage("Sheildon")->CenterRender(Vector2(1400 - 65, 593));
		}
		if (OBJECT->isskill3 == 0 || OBJECT->isskill3 == 3) {
			IMAGE->FindImage("Sheildoff")->CenterRender(Vector2(1400 - 65, 593));
		}
	}

}

void ingameUi::Release()
{
}

void ingameUi::onCollisionStay(Object* obj)
{
}

void ingameUi::onCollisionExit(Object* obj)
{
}
