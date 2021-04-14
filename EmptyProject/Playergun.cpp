#include "DXUT.h"
#include "Playergun.h"
#include"PlayerBullet.h"
void Playergun::Init()
{
	/*collider = new Collider;
	collider->lpGameObject = this;
	this->collider->SetRange(60, 60);
	OBJECT->AddCollision(collider);*/
	firespeed = new Timer;
	firespeed->setTimer(0.3);
}

void Playergun::Update()
{
	//this->collider->SetRange(60, 60);

	if (OBJECT->playchoice == 1) {
		vEnd = OBJECT->FindObject("player")->vPos;
		MATH->Lerp<Vector2>(&vPos, vPos, Vector2(vEnd.x, vEnd.y), 10.0f);

	}
	if (OBJECT->playchoice == 2) {
		vEnd = OBJECT->FindObject("Player2")->vPos;
		MATH->Lerp<Vector2>(&vPos, vPos, Vector2(vEnd.x, vEnd.y), 10.0f);

	}
	if (OBJECT->isskill1 == 1) {
		if (firespeed->Update()) {
			for (float i = -0.2f; i <= 0.2f; i += 0.4f)
			{
				OBJECT->AddObject("PlayerBullet", new PlayerBullet({ i, 1 }), Vector2(vPos.x + 68, vPos.y), BULLET);
				OBJECT->AddObject("PlayerBullet", new PlayerBullet({ i, 1 }), Vector2(vPos.x - 68, vPos.y), BULLET);
			}
		}
	}
}

void Playergun::Render()
{

	if(OBJECT->playchoice == 1)
		IMAGE->FindImage("player1gun")->CenterRender(vPos);
	if (OBJECT->playchoice == 2)
		IMAGE->FindImage("player3gun")->CenterRender(vPos);

}

void Playergun::Release()
{
	SAFE_DELETE(firespeed);
	//SAFE_DELETE(collider);
}

void Playergun::onCollisionStay(Object* obj)
{

}

void Playergun::onCollisionExit(Object* obj)
{

}
