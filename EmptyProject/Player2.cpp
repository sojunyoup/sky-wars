#include "DXUT.h"
#include "Player2.h"
#include "PlayerBullet.h"
//#include "GameoverScene.h"
//#include "cEffect.h"
void Player2::Init()
{
	OBJECT->isskill1 = 3;

	Speed = 300;
	bulletSpeed = new Timer;
	bulletSpeed->setTimer(0.1f);

	firespeed = new Timer;
	firespeed->setTimer(0.05f);
	//충돌
	collider = new Collider;
	collider->lpGameObject = this;

	rhdthr = new Timer;
	rhdthr->setTimer(10.0f);

	rhdthr1 = new Timer;
	rhdthr1->setTimer(3.0f);

	skillcool = new Timer;
	skillcool->setTimer(10.0f);

	skillcoo2 = new Timer;
	skillcoo2->setTimer(10.0f);

	skillcoo3 = new Timer;
	skillcoo3->setTimer(5.0f);

	skillcoo4 = new Timer;
	skillcoo4->setTimer(10.0f);

	this->collider->SetRange(30, 30);
	OBJECT->AddCollision(collider);
	srand(time(NULL));
	Isstart = true;
}

void Player2::Update()
{
	if (OBJECT->item == 1) {
		if (rhdthr->Update()) {
			OBJECT->item = 0;
		}
	}
	if (OBJECT->isskill1 == 1) {
		if (rhdthr1->Update()) {
			OBJECT->isskill1 = 0;
		}
	}
	else if (OBJECT->isskill1 == 0) {
		if (rhdthr1->Update()) {
			OBJECT->isskill1 = 3;
		}
	}
	if (INPUT->KeyDown('E') && OBJECT->isskill1 == 3) {
		OBJECT->isskill1 = 1;
	}
	//무적, 보호막 스킬
	if (INPUT->KeyDown('Q') && OBJECT->isskill3 == 1) {
		OBJECT->isskill3 = 0;
	}
	if (OBJECT->isskill3 == 0) {
		if (skillcoo3->Update()) {
			OBJECT->isskill3 = 3;
		}
	}
	else if (OBJECT->isskill3 == 3) {
		if (skillcoo4->Update()) {
			OBJECT->isskill3 = 1;
		}
	}

	if (OBJECT->pHp == 0) {
		SCENE->ChangeScene("ingame");
	}
	this->collider->SetRange(30, 30);

	if (vPos.y >= 700 && Isstart == true) {
		vPos.y -= 300 * DXUTGetElapsedTime();
	}
	if (vPos.y <= 700 && Isstart == true) {
		Isstart = false;
	}

	if (OBJECT->pHp > 100) {
		OBJECT->pHp = 100;
	}

	if (INPUT->KeyPress(VK_SHIFT)) {
		Speed = 200;
	}
	else
		Speed = 300;

	if (OBJECT->option == 1) {
		if (INPUT->KeyPress(VK_UP))
		{
			vPos.y -= Speed * D_TIME;
			if (vPos.y <= 0)
			{
				vPos.y += Speed / 2 * D_TIME;
			}
		}
		if (INPUT->KeyPress(VK_DOWN))
		{
			vPos.y += Speed * D_TIME;
			if (vPos.y >= WINSIZEY)
			{
				vPos.y -= Speed * D_TIME;
			}
		}
		if (INPUT->KeyPress(VK_LEFT))
		{
			vPos.x -= Speed * D_TIME;
			if (vPos.x <= 0)
			{
				vPos.x += Speed * D_TIME;
			}
		}
		if (INPUT->KeyPress(VK_RIGHT))
		{
			vPos.x += Speed * D_TIME;
			if (vPos.x >= WINSIZEX)
			{
				vPos.x -= Speed * D_TIME;
			}
		}
		if (INPUT->KeyPress('Z')) {
			if (bulletSpeed->Update())
			{
				OBJECT->AddObject("PlayerBullet", new PlayerBullet({ 0, 1 }), vPos, BULLET);
			}
		}
	}
	if (OBJECT->option == 2) {
		if (INPUT->KeyPress('W'))
		{
			vPos.y -= Speed * D_TIME;
			if (vPos.y <= 0)
			{
				vPos.y += Speed / 2 * D_TIME;
			}
		}
		if (INPUT->KeyPress('S'))
		{
			vPos.y += Speed * D_TIME;
			if (vPos.y >= WINSIZEY)
			{
				vPos.y -= Speed * D_TIME;
			}
		}
		if (INPUT->KeyPress('A'))
		{
			vPos.x -= Speed * D_TIME;
			if (vPos.x <= 0)
			{
				vPos.x += Speed * D_TIME;
			}
		}
		if (INPUT->KeyPress('D'))
		{
			vPos.x += Speed * D_TIME;
			if (vPos.x >= WINSIZEX)
			{
				vPos.x -= Speed * D_TIME;
			}
		}
		if (INPUT->KeyPress(VK_LBUTTON)) {
			if (bulletSpeed->Update())
			{
				OBJECT->AddObject("PlayerBullet", new PlayerBullet({ 0, 1 }), vPos, BULLET);
			}
		}
	}

	if (vPos.x >= 1200) {
		vPos.x -= Speed * D_TIME;
	}

	if (OBJECT->pHp <= 0)
	{
		isDestroy = true;
	}

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
	if (OBJECT->hilltem == 1) {
		OBJECT->pHp += 5 * D_TIME;
	}
	if (OBJECT->pHp >= 100) {
		OBJECT->pHp = 100;
	}
}

void Player2::Render()
{
	if (INPUT->KeyPress('A') || INPUT->KeyPress(VK_LEFT)) {
		IMAGE->FINDVECIMAGE("player1effect", 10)->FINDIMAGE(enem)->CenterRender(Vector2(vPos.x - 8, vPos.y + 65));
		IMAGE->FINDVECIMAGE("player1effect", 10)->FINDIMAGE(enem1)->CenterRender(Vector2(vPos.x + 6, vPos.y + 65));
		IMAGE->FindImage("lplayer3")->CenterRender(vPos);
		
	}
	else if (INPUT->KeyPress('D') || INPUT->KeyPress(VK_LEFT)) {
		IMAGE->FINDVECIMAGE("player1effect", 10)->FINDIMAGE(enem)->CenterRender(Vector2(vPos.x - 6, vPos.y + 65));
		IMAGE->FINDVECIMAGE("player1effect", 10)->FINDIMAGE(enem1)->CenterRender(Vector2(vPos.x + 8, vPos.y + 65));
		IMAGE->FindImage("rplayer3")->CenterRender(vPos);
		
	}
	else {
		IMAGE->FINDVECIMAGE("player1effect", 10)->FINDIMAGE(enem)->CenterRender(Vector2(vPos.x - 7, vPos.y + 65));
		IMAGE->FINDVECIMAGE("player1effect", 10)->FINDIMAGE(enem1)->CenterRender(Vector2(vPos.x + 7, vPos.y + 65));
		IMAGE->FindImage("player3")->CenterRender(vPos);
	}
	if (OBJECT->isskill3 == 0) {
		IMAGE->FindImage("Barrier")->CenterRender(vPos);
	}

}

void Player2::Release()
{
	SAFE_DELETE(skillcool);
	SAFE_DELETE(skillcoo2);
	SAFE_DELETE(collider);
	SAFE_DELETE(bulletSpeed);
	SAFE_DELETE(firespeed); 
	SAFE_DELETE(rhdthr);
	SAFE_DELETE(skillcoo3);
	SAFE_DELETE(skillcoo4); 
	SAFE_DELETE(rhdthr1);
}

void Player2::onCollisionStay(Object* obj)
{
	if (OBJECT->isskill3 == 1 || OBJECT->isskill3 == 3) {
		switch (obj->m_Tag)
		{
		case EBULLET:
			OBJECT->pHp -= obj->Damage;
			OBJECT->score -= 1;
			CAMERA->CameraShake(100);
			CAMERA->SetCamera({ WINSIZEX / 2,WINSIZEY / 2 });
			break;
		}
		switch (obj->m_Tag)
		{
		case ENEMY:
			OBJECT->pHp -= obj->Damage;
			OBJECT->score -= 1;
			CAMERA->CameraShake(100);
			CAMERA->SetCamera({ WINSIZEX / 2,WINSIZEY / 2 });
			break;
		}
	}
}

void Player2::onCollisionExit(Object* obj)
{
}
