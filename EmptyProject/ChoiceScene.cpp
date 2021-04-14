#include "DXUT.h"
#include "ChoiceScene.h"
#include"Mose.h"
#include"Player1ui.h"
#include"Player2ui.h"
#include"playui.h"
ChoiceScene::ChoiceScene()
{
}

ChoiceScene::~ChoiceScene()
{
}

void ChoiceScene::Init()
{
	firespeed = new Timer;
	firespeed->setTimer(0.05f);
	OBJECT->AddObject("Mouse", new Mose, Vector2(100, 100), MOUSE);
	OBJECT->AddObject("Player1ui", new Player1ui, Vector2(WINSIZEX / 2 + 300, WINSIZEY / 2 + 200), UI);
	OBJECT->AddObject("Player2ui", new Player2ui, Vector2(WINSIZEX / 2 - 300, WINSIZEY / 2 + 200), UI);
	OBJECT->AddObject("playui", new playui, Vector2(WINSIZEX / 2 , WINSIZEY / 2  + 350), UI);
}

void ChoiceScene::Update()
{
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

void ChoiceScene::Render()
{
	IMAGE->FindImage("mosaic1")->CenterRender(Vector2(WINSIZEX / 2, WINSIZEY / 2));

	if (OBJECT->playchoice == 1) {
		IMAGE->FindImage("Hwo1player")->CenterRender(Vector2(WINSIZEX/2, WINSIZEY / 2)); 
		IMAGE->FINDVECIMAGE("player2effect", 10)->FINDIMAGE(enem)->CenterRender(Vector2(WINSIZEX / 2 + 8, WINSIZEY / 2 + 185), 0, Vector2(1.4f, 1.4f));
		IMAGE->FINDVECIMAGE("player2effect", 10)->FINDIMAGE(enem1)->CenterRender(Vector2(WINSIZEX / 2 - 7, WINSIZEY / 2 + 185), 0, Vector2(1.4f, 1.4f));
		IMAGE->FindImage("player")->CenterRender(Vector2(WINSIZEX / 2, WINSIZEY / 2 + 100), 0, Vector2(1.4f, 1.4f)); 
	}
	if (OBJECT->playchoice == 2) {
		IMAGE->FindImage("Hwo3player")->CenterRender(Vector2(WINSIZEX / 2, WINSIZEY / 2));
		IMAGE->FINDVECIMAGE("player1effect", 10)->FINDIMAGE(enem)->CenterRender(Vector2(WINSIZEX / 2 + 8, WINSIZEY / 2 + 195), 0, Vector2(1.4f, 1.4f));
		IMAGE->FINDVECIMAGE("player1effect", 10)->FINDIMAGE(enem1)->CenterRender(Vector2(WINSIZEX / 2 - 7, WINSIZEY / 2 + 195), 0, Vector2(1.4f, 1.4f));
		IMAGE->FindImage("player3")->CenterRender(Vector2(WINSIZEX/2, WINSIZEY / 2 + 100),0,Vector2(1.4f,1.4f));
	}
}

void ChoiceScene::Release()
{
	SAFE_DELETE(firespeed);
}
