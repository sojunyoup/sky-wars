#include "DXUT.h"
#include "twoScene.h"
#include "Player.h"
#include "Player2.h"
#include "LookEnemy.h"
#include "Scroolmap.h"
#include "ingameUi.h"
#include "Omoveenemy.h"
#include "goEnemy.h"
#include "Playergun.h"
#include "cEnemy.h"
#include "lerpEnemy.h"
#include "twoBoss.h"
#include"twoEnemy.h"

twoScene::twoScene()
{
}


twoScene::~twoScene()
{
}

void twoScene::Init()
{
	
	
	OBJECT->item == 0;
	vStage = { -300, WINSIZEY / 2 };
	mop = new Timer;
	mop->setTimer(3.0f);
	OBJECT->pHp = 100;
	range = new Timer;
	range->setTimer(2.0f);
	mop2 = new Timer;
	mop2->setTimer(3.0f);
	//OBJECT->AddObject("twoBoss", new twoBoss, { 600, -10 }, ENEMY);

	OBJECT->AddObject("ingameUi", new ingameUi, { WINSIZEX / 2, WINSIZEY / 2 }, UI);
	if (OBJECT->playchoice == 1) {
		OBJECT->AddObject("player", new Player, { 600, WINSIZEY }, PLAYER);
		OBJECT->AddObject("Playergun", new Playergun, { 600, WINSIZEY }, PLAYER);
	}
	if (OBJECT->playchoice == 2) {
		OBJECT->AddObject("Player2", new Player2, { 600, WINSIZEY }, PLAYER);
		OBJECT->AddObject("Playergun", new Playergun, { 600, WINSIZEY }, PLAYER);
	}

	m_map = new Scroolmap(IMAGE->AddImage("BG_Noon", "./Resource/BG_Noon.png"));
	m_map1 = new Scroolmap(IMAGE->AddImage("scrool2", "./Resource/scrool2.png"));
	if (1) {
		OBJECT->AddObject("cEnemy", new cEnemy, { 1000, -10 }, ENEMY);
		OBJECT->AddObject("cEnemy", new cEnemy, { 200, -10 }, ENEMY);
		isenemygo = true;
	}
}

void twoScene::Update()
{

	CAMERA->SetCamera({ WINSIZEX / 2,WINSIZEY / 2 });
	if (OBJECT->score <= 1000) {
		OBJECT->score == 1000;
	}
	if (OBJECT->score >= 2000) {
		SCENE->ChangeScene("tkaqjsScene");
	}
	if (isenemygo == true) {
		if (mop2->Update())
			istwoenemy = true;
	}
	if (INPUT->KeyDown(VK_RETURN)) {
		OBJECT->score += 500;
	}
	if (istwoenemy == true) {
		OBJECT->AddObject("twoEnemy", new twoEnemy, { 10, 200 }, ENEMY);
		OBJECT->AddObject("twoEnemy", new twoEnemy, { 10, 200 }, ENEMY);
		OBJECT->AddObject("twoEnemy", new twoEnemy, { 10, 200 }, ENEMY);
		OBJECT->AddObject("twoEnemy", new twoEnemy, { 10, 200 }, ENEMY);
		OBJECT->AddObject("twoEnemy", new twoEnemy, { 10, 200 }, ENEMY);
		istwoenemy = false;
	}
	if (vStage.x >= 580) {
		vStage.x += 800 * D_TIME;
	}
	else
	{
		MATH->Lerp<Vector2>(&vStage, vStage, Vector2(600, WINSIZEY / 2), 3.0f);
	}
	m_map->Update(500);
	m_map1->Update(200);

	if (OBJECT->option == 0) {
		OBJECT->option = 2;
	}

	if (OBJECT->pHp <= 0)
	{
		SCENE->ChangeScene("EndScene");
	}
	if (range->Update()) {
		isgo = true;
	}
	if (isgo == true) {
		//요기 진행
	}
	if (mop->Update() && ist == false) {
		OBJECT->AddObject("lerpEnemy", new lerpEnemy, { 1000, 200 }, ENEMY);
		OBJECT->AddObject("lerpEnemy", new lerpEnemy, { 200, 200 }, ENEMY);
		ist = true;
	}
}

void twoScene::Render()
{
	m_map->Render();
	m_map1->Render();
	
	IMAGE->FindImage("2stage")->CenterRender(vStage);

}

void twoScene::Release()
{
	SAFE_DELETE(mop2);
	SAFE_DELETE(mop);
	SAFE_DELETE(m_map);
	SAFE_DELETE(range);
	SAFE_DELETE(m_map1);
}
//120557