#include "DXUT.h"
#include "TitleScene.h"
#include "Mose.h"
#include "Butten.h"
#include "guideButten.h"
#include"optionButten.h"
#include"creditButten.h"
TitleScene::TitleScene()
{
}

TitleScene::~TitleScene()
{
}

void TitleScene::Init()
{
	isTitle = new Timer;
	isTitle->setTimer(2.0f);
	vtitle = Vector2(WINSIZEX/2 + 20, WINSIZEY/2);
	OBJECT->AddObject("BUT", new Butten, Vector2(250, WINSIZEY / 2 - 50), UI);
	OBJECT->AddObject("guideButten", new guideButten, Vector2(290, WINSIZEY / 2 + 80), UI);
	OBJECT->AddObject("creditButten", new creditButten, Vector2(360, WINSIZEY / 2 + 180 + 160 ), UI);
	OBJECT->AddObject("optionButten", new optionButten, Vector2(320, WINSIZEY / 2 + 210), UI);
	OBJECT->AddObject("Mouse", new Mose, Vector2(100, 100), MOUSE);
}

void TitleScene::Update()
{
	if (isTitle->Update()) {
		OBJECT->isoff = true;
	}
	if (OBJECT->isoff == true)
		MATH->Lerp<Vector2>(&vtitle, vtitle, Vector2(WINSIZEX / 2, 200), 5.0f);
	CAMERA->SetCamera({ WINSIZEX / 2,WINSIZEY / 2 });
}

void TitleScene::Render()
{
	IMAGE->FindImage("Main_BG")->CenterRender(Vector2(WINSIZEX / 2, WINSIZEY / 2));
	IMAGE->FindImage("mosaic1")->CenterRender(Vector2(WINSIZEX / 2, WINSIZEY/2 - WINSIZEY));
	if (OBJECT->isoff == true) {
		IMAGE->FindImage("Title")->CenterRender(vtitle, 0, Vector2(1.0f, 1.0f));
	}
}

void TitleScene::Release()
{
	SAFE_DELETE(isTitle);
}
