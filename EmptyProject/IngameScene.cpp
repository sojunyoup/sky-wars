#include "DXUT.h"
#include "IngameScene.h"
#include "Player.h"
#include "Player2.h"
#include "LookEnemy.h"
#include "Scroolmap.h"
#include "ingameUi.h"
#include "Omoveenemy.h"
#include "goEnemy.h"
#include "Playergun.h"

IngameScene::IngameScene()
{
}


IngameScene::~IngameScene()
{
}

void IngameScene::Init()
{

	vStage = { -300, WINSIZEY / 2 };

	range = new Timer;
	range->setTimer(2.0f);
	OBJECT->score = 0;
	OBJECT->pHp = 100;

	Respawn = new Timer;
	Respawn->setTimer(4.0f);
	OBJECT->AddObject("ingameUi", new ingameUi, { WINSIZEX / 2, WINSIZEY / 2 }, UI);
	if (OBJECT->playchoice == 1) {
		OBJECT->AddObject("player", new Player, { 600, WINSIZEY }, PLAYER);
		OBJECT->AddObject("Playergun", new Playergun, { 600, WINSIZEY }, PLAYER);
	}
	if (OBJECT->playchoice == 2) {
		OBJECT->AddObject("Player2", new Player2, { 600, WINSIZEY }, PLAYER);
		OBJECT->AddObject("Playergun", new Playergun, { 600, WINSIZEY }, PLAYER);
	}

	m_map = new Scroolmap(IMAGE->AddImage("BG_Night", "./Resource/BG_Night.png"));
	m_map1 = new Scroolmap(IMAGE->AddImage("scrool1", "./Resource/scrool1.png"));

}

void IngameScene::Update()
{
	if (vStage.x >=580) {
		vStage.x += 800 * D_TIME;
	}
	else
	{
		MATH->Lerp<Vector2>(&vStage, vStage, Vector2(600, WINSIZEY/2), 3.0f);
	}
	m_map->Update(500);
	m_map1->Update(200);
	if (OBJECT->option == 0) {
		OBJECT->option = 2;
	}
	if (range->Update()) {
		isgo = true;
	}
	CAMERA->SetCamera({ WINSIZEX / 2,WINSIZEY / 2 });
	if (isgo == true) {
		while (mop < 6) {
			OBJECT->AddObject("LookEnemy", new LookEnemy, { 600, 0 }, ENEMY);
			if (mop == 5) {
				OBJECT->AddObject("goEnemy", new goEnemy, { 1000, -10 }, ENEMY);
				OBJECT->AddObject("goEnemy", new goEnemy, { 200, -10 }, ENEMY);
				if (OBJECT->score > 600) {
					OBJECT->AddObject("Omoveenemy", new Omoveenemy, { 1180,30 }, ENEMY);
					OBJECT->AddObject("Omoveenemy", new Omoveenemy, { 0,30 }, ENEMY);
				}
				mop++;
			}
			mop++;
		}
		if (Respawn->Update()) {
			mop = 0;
		}
	}
	if (OBJECT->score >= 1000){
		SCENE->ChangeScene("oneBoss");
	}
	if (OBJECT->pHp <= 0)
	{
		SCENE->ChangeScene("EndScene");
	}
}

void IngameScene::Render()
{
	m_map->Render();
	m_map1->Render();
	IMAGE->FindImage("1stage")->CenterRender(vStage);
}

void IngameScene::Release()
{
	SAFE_DELETE(range);
	SAFE_DELETE(m_map);
	SAFE_DELETE(m_map1);
	SAFE_DELETE(Respawn);
}
