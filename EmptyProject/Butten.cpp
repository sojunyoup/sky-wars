#include "DXUT.h"
#include "Butten.h"

void Butten::Init()
{
	collider = new Collider;
	collider->lpGameObject = this;
	this->collider->SetRange(354, 104);
	OBJECT->AddCollision(collider);


	vPos = Vector2(WINSIZEX / 2, WINSIZEY / 2);
	sco = false;
}

void Butten::Update()
{
	
	this->collider->SetRange(354, 104);
	
}

void Butten::Render()
{
	
	IMAGE->FindImage("Play-Default")->CenterRender(vPos);
	if (sco == true) {
		if (INPUT->KeyPress(VK_LBUTTON))
			IMAGE->FindImage("Play-Pressed")->CenterRender(vPos, 0, Vector2(1.1f, 1.1f));
		else
			IMAGE->FindImage("Play-OnMouse")->CenterRender(vPos, 0, Vector2(1.1f, 1.1f));
	}
}

void Butten::Release()
{
	SAFE_DELETE(collider);
}

void Butten::onCollisionStay(Object* obj)
{
	if (OBJECT->isoff == true && OBJECT->isguideon == false) {
		switch (obj->m_Tag)
		{
		case MOUSE:
			if (INPUT->KeyUp(VK_LBUTTON)) {
				SCENE->ChangeScene("choice");
			}
			sco = true;
			break;
		}
	}
}

void Butten::onCollisionExit(Object* obj)
{
	sco = false;
}
