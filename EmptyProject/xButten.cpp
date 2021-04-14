#include "DXUT.h"
#include "xButten.h"

void xButten::Init()
{
	collider = new Collider;
	collider->lpGameObject = this;
	this->collider->SetRange(354, 104);
	OBJECT->AddCollision(collider);
	vtitle = Vector2(WINSIZEX, WINSIZEY / 2);

	vPos = Vector2(WINSIZEX / 2, WINSIZEY / 2);
	sco = false;
}

void xButten::Update()
{
	if (OBJECT->isoff == false)
		MATH->Lerp<Vector2>(&vtitle, vtitle, Vector2(WINSIZEX / 2, WINSIZEY / 2), 5.0f);
	this->collider->SetRange(354, 104);
}

void xButten::Render()
{
	IMAGE->FindImage("Option-Default")->CenterRender(vPos);
	if (sco == true) {
		if (INPUT->KeyPress(VK_LBUTTON))
			IMAGE->FindImage("Option-Pressed")->CenterRender(vPos);
		else
			IMAGE->FindImage("Option-OnMouse")->CenterRender(vPos);
	}
	if (OBJECT->isoff == false) {
		IMAGE->FindImage("mosaic")->CenterRender(Vector2(WINSIZEX / 2, WINSIZEY / 2));
		IMAGE->FindImage("Title")->CenterRender(vtitle, 0, Vector2(1.2f, 1.2f));
	}
}

void xButten::Release()
{
	SAFE_DELETE(collider);
}

void xButten::onCollisionStay(Object* obj)
{
	if (OBJECT->isoff == true && OBJECT->isguideon == false) {
		switch (obj->m_Tag)
		{
		case MOUSE:
			sco = true;
			if (INPUT->KeyUp(VK_LBUTTON))
				SCENE->ChangeScene("option");
			break;
		}
	}
}

void xButten::onCollisionExit(Object* obj)
{
	sco = false;
}
