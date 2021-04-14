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
#include "twoEnemy.h"
#include "tkaqjsScene.h"
#include "rkfhBullet.h"
#include "tpfhBullet.h"

tkaqjsScene::tkaqjsScene()
{
}


tkaqjsScene::~tkaqjsScene()
{
}

void tkaqjsScene::Init()
{
	srand(time(NULL));

	OBJECT->item == 0;
	vStage = { -300, WINSIZEY / 2 };
	mop = new Timer;
	mop->setTimer(0.1f);
	range1 = new Timer;
	range1->setTimer(3.0f);
	OBJECT->pHp = 100;
	range = new Timer;
	range->setTimer(3.0f);
	mop2 = new Timer;
	mop2->setTimer(0.2f);
	mop3 = new Timer;
	mop3->setTimer(0.08f);
	range2 = new Timer;
	range2->setTimer(3.0f);

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
}

void tkaqjsScene::Update()
{
	if (OBJECT->pHp <= 0)
	{
		SCENE->ChangeScene("EndScene");
	}
	OBJECT->score += 15 * D_TIME;

	if (range->Update()) {
		y = (rand() % 880) + 10; 
		x = (rand() % 1180) + 10;
	}

	rkfhpos = { 1400, y };
	tpfhpos = { x, 0 };

	if (range1->Update()) {
		y1 = (rand() % 880) + 10;
		x1 = (rand() % 1180) + 10;
	}

	rkfhpos2 = { 1400, y1 };
	tpfhpos1 = { x1, 0 };

	if (range2->Update()) {
		y2 = (rand() % 880) + 10;
		x2 = (rand() % 1180) + 10;
	}

	rkfhpos3 = { 1400, y2 };
	tpfhpos2 = { x2, 0 };

	CAMERA->SetCamera({ WINSIZEX / 2,WINSIZEY / 2 });

	if (OBJECT->score <= 1000) {
		OBJECT->score == 1000;
	}
	m_map->Update(500);
	m_map1->Update(200);
	if (OBJECT->option == 0) {
		OBJECT->option = 2;
	}
	if (mop->Update()) {
		OBJECT->AddObject("rkfhBullet", new rkfhBullet(), rkfhpos, EBULLET); 
		OBJECT->AddObject("tpfhBullet", new tpfhBullet(), tpfhpos, EBULLET);
	}
	if (mop2->Update()) {
		OBJECT->AddObject("rkfhBullet1", new rkfhBullet(), rkfhpos2, EBULLET);
		OBJECT->AddObject("tpfhBullet", new tpfhBullet(), tpfhpos1, EBULLET);
	}
	if (OBJECT->score >= 2300) {
		if (mop3->Update()) {
			OBJECT->AddObject("rkfhBullet1", new rkfhBullet(), rkfhpos3, EBULLET);
			OBJECT->AddObject("tpfhBullet", new tpfhBullet(), tpfhpos2, EBULLET);
		}
	}
	if (OBJECT->score >= 2800) {
		SCENE->ChangeScene("twoBossScene");
	}
}

void tkaqjsScene::Render()
{
	m_map->Render();
	m_map1->Render();
}

void tkaqjsScene::Release()
{
	SAFE_DELETE(mop3);
	SAFE_DELETE(mop2);
	SAFE_DELETE(mop);
	SAFE_DELETE(m_map);
	SAFE_DELETE(range);
	SAFE_DELETE(m_map1); 
	SAFE_DELETE(range2);
}