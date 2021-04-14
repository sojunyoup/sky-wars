#include "DXUT.h"
#include "guideButten.h"

void guideButten::Init()
{
	collider = new Collider;
	collider->lpGameObject = this;
	this->collider->SetRange(354, 104);
	OBJECT->AddCollision(collider);

	vPos = Vector2(WINSIZEX / 2, WINSIZEY / 2);
	sco = false;
	iskeyck = false;

}

void guideButten::Update()
{
	this->collider->SetRange(354, 104);

	if (iskeyck == false) {
		CAMERA->SetCamera({ WINSIZEX / 2,WINSIZEY / 2 });
		vCmra = { WINSIZEX / 2, WINSIZEY / 2 };
	}
	else if (iskeyck == true) {
		CAMERA->SetCamera({ WINSIZEX / 2, -450 });
	}
}

void guideButten::Render()
{
	IMAGE->FindImage("HTP-Default")->CenterRender(vPos);
	if (sco == true) {
		if (INPUT->KeyPress(VK_LBUTTON))
			IMAGE->FindImage("HTP-Pressed")->CenterRender(vPos);
		else
			IMAGE->FindImage("HTP-OnMouse")->CenterRender(vPos);
	}
}

void guideButten::Release()
{
	SAFE_DELETE(collider);
}

void guideButten::onCollisionStay(Object* obj)
{
	if (OBJECT->isoff == true && OBJECT->isguideon == false) {
		switch (obj->m_Tag)
		{
		case MOUSE:
			sco = true;
			if (INPUT->KeyUp(VK_LBUTTON)) {
				SCENE->ChangeScene("guidescene");
			}
			break;
		}
	}
}

void guideButten::onCollisionExit(Object* obj)
{
	sco = false;
}
