#include "DXUT.h"
#include "Player1ui.h"

void Player1ui::Init()
{
	firespeed = new Timer;
	firespeed->setTimer(0.05);
	collider = new Collider;
	collider->lpGameObject = this;
	this->collider->SetRange(60, 60);
	OBJECT->AddCollision(collider);
	player1 = { WINSIZEX / 2 + 300, WINSIZEY };
}

void Player1ui::Update()
{
	this->collider->SetRange(60, 60);

	MATH->Lerp<Vector2>(&player1, player1, Vector2(WINSIZEX / 2 + 300, WINSIZEY / 2 + 200), 3.0f);

	if (firespeed->Update()) {
		enem++;
		enem1++;
	}
	if (enem >= 9) {
		enem = 0;
	}
	if (enem1 >= 9) {
		enem1 = 0;
	}
}

void Player1ui::Render()
{
	IMAGE->FINDVECIMAGE("player2effect", 10)->FINDIMAGE(enem)->CenterRender(Vector2(player1.x - 7, player1.y + 60));
	IMAGE->FINDVECIMAGE("player2effect", 10)->FINDIMAGE(enem1)->CenterRender(Vector2(player1.x + 7, player1.y + 60));
	IMAGE->FindImage("player")->CenterRender(player1);
}

void Player1ui::Release()
{
	SAFE_DELETE(firespeed);
	SAFE_DELETE(collider);
}

void Player1ui::onCollisionStay(Object* obj)
{
	switch (obj->m_Tag)
	{
	case MOUSE:
		if (INPUT->KeyUp(VK_LBUTTON))
			OBJECT->playchoice = 1;
		break;
	}
}

void Player1ui::onCollisionExit(Object* obj)
{
}
