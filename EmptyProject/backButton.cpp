#include "DXUT.h"
#include "backButton.h"

void backButton::Init()
{
	collider = new Collider;
	collider->lpGameObject = this;
	this->collider->SetRange(358, 109);
	OBJECT->AddCollision(collider);
}

void backButton::Update()
{
	this->collider->SetRange(358, 109);
}

void backButton::Render()
{
	IMAGE->FindImage("Back-Default")->CenterRender(vPos);

	if (sco == true) {
		if (INPUT->KeyPress(VK_LBUTTON))
			IMAGE->FindImage("Back-Pressed")->CenterRender(vPos, 0, Vector2(1.1f, 1.1f));
		else
			IMAGE->FindImage("Back-OnMouse")->CenterRender(vPos, 0, Vector2(1.1f, 1.1f));
	}

}

void backButton::Release()
{
	SAFE_DELETE(collider);
}

void backButton::onCollisionStay(Object* obj)
{
	switch (obj->m_Tag)
	{
	case MOUSE:
		if (INPUT->KeyUp(VK_LBUTTON)) {
			SCENE->ChangeScene("title");
		}
		sco = true;
		break;
	}
}

void backButton::onCollisionExit(Object* obj)
{
	sco = false;
}