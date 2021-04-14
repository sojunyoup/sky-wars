#include "DXUT.h"
#include "Player.h"
#include "PlayerBullet.h"
#include"oneplayerskill.h"
//#include "GameoverScene.h"
//#include "cEffect.h"

void Player::Init()
{
	OBJECT->isskill1 = 3;

	Speed = 500;
	firespeed = new Timer;
	firespeed->setTimer(0.05f);
	/*shieldtimer = new Timer;
	shieldtimer->setTimer(3.0f); */
	bulletSpeed = new Timer;
	bulletSpeed->setTimer(0.1f);

	skill1 = new Timer;
	skill1->setTimer(10.0f);

	skillcool = new Timer;
	skillcool->setTimer(10.0f);

	skillcoo2 = new Timer;
	skillcoo2->setTimer(10.0f);

	skillcoo3 = new Timer;
	skillcoo3->setTimer(10.0f);


	rhdthr = new Timer;
	rhdthr->setTimer(10.0f);
	rhdthr1 = new Timer;
	rhdthr1->setTimer(3.0f);
	
	//SCENE->AddScene("Gameover", new GameoverScene);
	//충돌
	collider = new Collider;
	collider->lpGameObject = this;
	this->collider->SetRange(17, 17);
	OBJECT->AddCollision(collider);
	srand(time(NULL));
	Isstart = true;
}

void Player::Update()
{
	//스킬을 쓸 수 있는 타임 3
	//스킬을 쓰는 중 1
	//스킬을 안쓰는 중 0

	//아이템 먹기 공속
	if (OBJECT->item == 1) {
		if (rhdthr->Update()) {
			OBJECT->item = 0;
		}
	}
	if (OBJECT->hilltem == 1) {
		if (rhdthr->Update()) {
			OBJECT->hilltem = 0;
		}
	}

	//공용 스킬
	if (OBJECT->isskill1 == 1) {
		if (skillcool->Update()) {
			OBJECT->isskill1 = 0;
		}
	}
	else if (OBJECT->isskill1 == 0) {
		if (skillcoo2->Update()) {
			OBJECT->isskill1 = 3;
		}
	}
	if (INPUT->KeyDown('E') && OBJECT->isskill1 == 3) {
		OBJECT->isskill1 = 1;
	}

	//폭탄 스킬

	if (INPUT->KeyDown('Q') && OBJECT->isskill2 == 1) {
		OBJECT->AddObject("oneplayerskill", new oneplayerskill(), vPos, SKILL);
		OBJECT->isskill2 = 0;
	}
	if (OBJECT->isskill2 == 0) {
		if (skillcoo3->Update()) {
			OBJECT->isskill2 = 1;
		}
	}

	if (OBJECT->pHp == 0) {
		SCENE->ChangeScene("ingame");
	}
	this->collider->SetRange(17, 17);

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
		Speed = 400;
	}
	else
		Speed = 500;

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
	
	//캐릭터 HP 0 처리
	if (OBJECT->pHp <= 0)
	{
		isDestroy = true;
	}
	
	//맵 못나가게 처리
	if (vPos.x >= 1200) {
		vPos.x -= Speed * D_TIME;
	}

	//애니메이션
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
		OBJECT->pHp += 5*D_TIME;
	}
	if (OBJECT->pHp >= 100) {
		OBJECT->pHp = 100;
	}
}

void Player::Render()
{
	if (INPUT->KeyPress('A')||INPUT->KeyPress(VK_LEFT)) {
		IMAGE->FINDVECIMAGE("player2effect", 10)->FINDIMAGE(enem)->CenterRender(Vector2(vPos.x - 8, vPos.y + 62), 0, Vector2(1.1f, 1.1f));
		IMAGE->FINDVECIMAGE("player2effect", 10)->FINDIMAGE(enem1)->CenterRender(Vector2(vPos.x + 6, vPos.y + 62), 0, Vector2(1.1f, 1.1f));
		IMAGE->FindImage("lplayer1")->CenterRender(vPos);
	}
	else if (INPUT->KeyPress('D') || INPUT->KeyPress(VK_RIGHT)) {
		IMAGE->FINDVECIMAGE("player2effect", 10)->FINDIMAGE(enem)->CenterRender(Vector2(vPos.x - 6, vPos.y + 62), 0, Vector2(1.1f, 1.1f));
		IMAGE->FINDVECIMAGE("player2effect", 10)->FINDIMAGE(enem1)->CenterRender(Vector2(vPos.x + 8, vPos.y + 62), 0, Vector2(1.1f, 1.1f));
		IMAGE->FindImage("rplayer1")->CenterRender(vPos);
	}
	else {
		IMAGE->FINDVECIMAGE("player2effect", 10)->FINDIMAGE(enem)->CenterRender(Vector2(vPos.x - 5, vPos.y + 62), 0, Vector2(1.1f, 1.1f));
		IMAGE->FINDVECIMAGE("player2effect", 10)->FINDIMAGE(enem1)->CenterRender(Vector2(vPos.x + 7, vPos.y + 62), 0, Vector2(1.1f, 1.1f));
		IMAGE->FindImage("player")->CenterRender(vPos);
	}
	IMAGE->FindImage("collider")->CenterRender(Vector2(vPos.x, vPos.y+7));
}

void Player::Release()
{
	SAFE_DELETE(skillcool);
	SAFE_DELETE(firespeed); 
	SAFE_DELETE(collider);
	SAFE_DELETE(skill1);
	SAFE_DELETE(bulletSpeed); 
	SAFE_DELETE(rhdthr);
	SAFE_DELETE(rhdthr1);
	
}

void Player::onCollisionStay(Object* obj)
{
	switch (obj->m_Tag)
	{
	case EBULLET:
		OBJECT->score -= 1;
		OBJECT->pHp -= obj->Damage;
		CAMERA->CameraShake(200);
		CAMERA->SetCamera({ WINSIZEX / 2,WINSIZEY / 2 });
		break;
	}
	switch (obj->m_Tag)
	{
	case ENEMY:
			OBJECT->score -= 1;
		OBJECT->pHp -= obj->Damage;
		CAMERA->CameraShake(200);
		CAMERA->SetCamera({ WINSIZEX / 2,WINSIZEY / 2 });
		break;
	}
}

void Player::onCollisionExit(Object* obj)
{
}
