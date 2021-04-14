#include "DXUT.h"
#include "twoBossScene.h"
#include "ingameUi.h"
#include "Player.h"
#include "Scroolmap.h"
#include "Player2.h"
#include "twoBoss.h"
#include "Playergun.h"
#include "lerpEnemy.h"
#include "BossEffect.h"

twoBossScene::twoBossScene()
{
}

twoBossScene::~twoBossScene()
{
}

void twoBossScene::Init()
{
	isbossS = false;
	isending = new Timer;
	isending->setTimer(3.0f);

	OBJECT->item == 0;
	OBJECT->AddObject("lerpEnemy", new lerpEnemy, { 1000, 200 }, ENEMY);
	OBJECT->AddObject("lerpEnemy", new lerpEnemy, { 200, 200 }, ENEMY);
	isboss = false;
	OBJECT->AddObject("ingameUi", new ingameUi, { WINSIZEX / 2, WINSIZEY / 2 }, UI);
	Boss = Vector2(600, WINSIZEY);


	if (OBJECT->playchoice == 1) {
		OBJECT->AddObject("player", new Player, { 600, WINSIZEY }, PLAYER);
		OBJECT->AddObject("Playergun", new Playergun, { 600, WINSIZEY }, PLAYER);
	}
	if (OBJECT->playchoice == 2) {
		OBJECT->AddObject("Player2", new Player2, { 600, WINSIZEY }, PLAYER);
		OBJECT->AddObject("Playergun", new Playergun, { 600, WINSIZEY }, PLAYER);
	}
	OBJECT->AddObject("twoBoss", new twoBoss, { 600, -300 }, ENEMY);
	m_map = new Scroolmap(IMAGE->AddImage("scrool", "./Resource/scrool.png"));

}

void twoBossScene::Update()
{
	
	if (OBJECT->score <= 3000) {
		OBJECT->score += 10*D_TIME;
	}
	CAMERA->SetCamera({ WINSIZEX / 2,WINSIZEY / 2 });

	if (OBJECT->pHp <= 0)
	{
		SCENE->ChangeScene("EndScene");
	}
	if (OBJECT->FindObject("twoBoss")->Hp <= 0) {
		isbossS = true;
		
	}
	if (isbossS == true) {
		if (isending->Update())
			SCENE->ChangeScene("EndScene");
	}
	m_map->Update(500);

}

void twoBossScene::Render()
{
	m_map->Render();

	IMAGE->FindImage("bossmap")->CenterRender({ WINSIZEX / 2, WINSIZEY / 2 });
	IMAGE->FindImage("Health")->Render({ 1280,385 }, 0, { OBJECT->pHp / 150,2 });

}

void twoBossScene::Release()
{
	
	SAFE_DELETE(m_map);
	SAFE_DELETE(isending);
}
