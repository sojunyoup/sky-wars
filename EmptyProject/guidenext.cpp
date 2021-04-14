#include "DXUT.h"
#include "guidenext.h"

void guidenext::Init()
{
	collider = new Collider;
	collider->lpGameObject = this;
	this->collider->SetRange(100, 100);
	OBJECT->AddCollision(collider);
}

void guidenext::Update()
{
	this->collider->SetRange(100, 100);
}

void guidenext::Render()
{
	IMAGE->FindImage("Right-Default")->CenterRender(vPos);
	if (sco == true) {
		if (INPUT->KeyPress(VK_LBUTTON))
			IMAGE->FindImage("Right-Pressed")->CenterRender(vPos, 0, Vector2(1.1f, 1.1f));
		else
			IMAGE->FindImage("Right-Default")->CenterRender(vPos, 0, Vector2(1.1f, 1.1f));
	}
	

	if (OBJECT->isguide == false) {
		IMAGE->FindImage("1of2")->CenterRender(Vector2(WINSIZEX / 2, WINSIZEY / 2 + 300));
	}
	else if (OBJECT->isguide == true) {
		IMAGE->FindImage("2of2")->CenterRender(Vector2(WINSIZEX / 2, WINSIZEY / 2 + 300));
	}
}

void guidenext::Release()
{
	SAFE_DELETE(collider);
}

void guidenext::onCollisionStay(Object* obj)
{
	switch (obj->m_Tag)
	{
	case MOUSE:
		if (INPUT->KeyDown(VK_LBUTTON)) {
			OBJECT->isguide = true;
		}
		sco = true;
		break;
	}
}

void guidenext::onCollisionExit(Object* obj)
{
	sco = false;
}
