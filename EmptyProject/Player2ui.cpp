#include "DXUT.h"
#include "Player2ui.h"

void Player2ui::Init()
{
	firespeed = new Timer;
	firespeed->setTimer(0.05);
	collider = new Collider;
	collider->lpGameObject = this;
	this->collider->SetRange(30, 30);
	OBJECT->AddCollision(collider);
	player2 = { WINSIZEX / 2 - 300, WINSIZEY };
}

void Player2ui::Update()
{
	this->collider->SetRange(60, 60);

	MATH->Lerp<Vector2>(&player2, player2, Vector2(WINSIZEX / 2 - 300, WINSIZEY / 2 + 200), 3.0f);

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

void Player2ui::Render()
{
	IMAGE->FINDVECIMAGE("player1effect", 10)->FINDIMAGE(enem)->CenterRender(Vector2(player2.x - 7, player2.y + 65));
	IMAGE->FINDVECIMAGE("player1effect", 10)->FINDIMAGE(enem1)->CenterRender(Vector2(player2.x + 7, player2.y + 65));
	IMAGE->FindImage("player3")->CenterRender(player2);
}

void Player2ui::Release()
{
	SAFE_DELETE(firespeed);
	SAFE_DELETE(collider);
}

void Player2ui::onCollisionStay(Object* obj)
{
	switch (obj->m_Tag)
	{
	case MOUSE:
		if (INPUT->KeyUp(VK_LBUTTON))
			OBJECT->playchoice = 2;

		break;
	}
}

void Player2ui::onCollisionExit(Object* obj)
{
}
