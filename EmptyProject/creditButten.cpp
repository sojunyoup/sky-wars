#include "DXUT.h"
#include "creditButten.h"

void creditButten::Init()
{
	collider = new Collider;
	collider->lpGameObject = this;
	this->collider->SetRange(354, 104);
	OBJECT->AddCollision(collider);
	vtitle = Vector2(WINSIZEX, WINSIZEY / 2);

	vPos = Vector2(WINSIZEX / 2, WINSIZEY / 2);
	sco = false;
}

void creditButten::Update()
{
	if (OBJECT->isoff == false)
		MATH->Lerp<Vector2>(&vtitle, vtitle, Vector2(WINSIZEX / 2, WINSIZEY / 2), 5.0f);
	this->collider->SetRange(354, 104);
}

void creditButten::Render()
{
	IMAGE->FindImage("Credit-Default")->CenterRender(vPos);
	if (sco == true) {
		if (INPUT->KeyPress(VK_LBUTTON))
			IMAGE->FindImage("Credit-Pressed")->CenterRender(vPos);
		else
			IMAGE->FindImage("Credit-OnMouse")->CenterRender(vPos);
	}
}

void creditButten::Release()
{
	SAFE_DELETE(collider);
}

void creditButten::onCollisionStay(Object* obj)
{
	if (OBJECT->isoff == true && OBJECT->isguideon == false) {
		switch (obj->m_Tag)
		{
		case MOUSE:
			sco = true;
			if (INPUT->KeyUp(VK_LBUTTON))
				SCENE->ChangeScene("credut");
			break;
		}
	}
}

void creditButten::onCollisionExit(Object* obj)
{
	sco = false;
}
