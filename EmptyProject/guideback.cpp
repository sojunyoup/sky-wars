#include "DXUT.h"
#include "guideback.h"

void guideback::Init()
{
	collider = new Collider;
	collider->lpGameObject = this;
	this->collider->SetRange(100, 100);
	OBJECT->AddCollision(collider);
}

void guideback::Update()
{
	this->collider->SetRange(100, 100);
}

void guideback::Render()
{

	IMAGE->FindImage("Left-Default")->CenterRender(vPos);
	if (sco == true) {
		if (INPUT->KeyPress(VK_LBUTTON))
			IMAGE->FindImage("Left-Pressed")->CenterRender(vPos, 0, Vector2(1.1f, 1.1f));
		else
			IMAGE->FindImage("Left-Default")->CenterRender(vPos, 0, Vector2(1.1f, 1.1f));
	}
}

void guideback::Release()
{
	SAFE_DELETE(collider);
}
 
void guideback::onCollisionStay(Object* obj)
{
	switch (obj->m_Tag)
	{
	case MOUSE:
		if (INPUT->KeyUp(VK_LBUTTON)) {
			OBJECT->isguide = false;
		}
		sco = true;
		break;
	}
}

void guideback::onCollisionExit(Object* obj)
{
	sco = false;
}
