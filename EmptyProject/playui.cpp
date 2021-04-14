#include "DXUT.h"
#include "playui.h"

void playui::Init()
{
	collider = new Collider;
	collider->lpGameObject = this;
	this->collider->SetRange(354, 104);
	OBJECT->AddCollision(collider);


	vPos = Vector2(WINSIZEX / 2, WINSIZEY / 2);
	sco = false;
}

void playui::Update()
{

	this->collider->SetRange(354, 104);

}

void playui::Render()
{

	IMAGE->FindImage("Play-Default")->CenterRender(vPos,0, Vector2(0.8f, 0.8f));
	if (sco == true) {
		if (INPUT->KeyPress(VK_LBUTTON))
			IMAGE->FindImage("Play-Pressed")->CenterRender(vPos, 0, Vector2(0.9f, 0.9f));
		else
			IMAGE->FindImage("Play-OnMouse")->CenterRender(vPos, 0, Vector2(0.9f, 0.9f));
	}
}

void playui::Release()
{
	SAFE_DELETE(collider);
}

void playui::onCollisionStay(Object* obj)
{
	switch (obj->m_Tag)
	{
	case MOUSE:
		if (INPUT->KeyUp(VK_LBUTTON)) {
			if (OBJECT->playchoice == 0) {
				OBJECT->playchoice = 1;
			}
			SCENE->ChangeScene("ingame");
		}
		
		sco = true;
		break;
	}
	
}

void playui::onCollisionExit(Object* obj)
{
	sco = false;
}
