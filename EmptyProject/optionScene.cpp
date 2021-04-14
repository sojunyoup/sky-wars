#include "DXUT.h"
#include "optionScene.h"
#include "backButton.h"
#include "Mose.h"
optionScene::optionScene()
{
}

optionScene::~optionScene()
{
}

void optionScene::Init()
{
	OBJECT->AddObject("Mouse", new Mose, Vector2(100, 100), MOUSE);
	OBJECT->AddObject("backButton", new backButton, Vector2(WINSIZEX / 2 - 550, WINSIZEY / 2), UI);
}

void optionScene::Update()
{
	Mpos = OBJECT->FindObject("Mouse")->vPos;
	if (Mpos.x >= 400 && Mpos.y >= WINSIZEY/2) {
		if (INPUT->KeyDown(VK_LBUTTON)) {
			OBJECT->option = 2;
		}
	}
	if (Mpos.x >= 400 && Mpos.y <= WINSIZEY / 2) {
		if (INPUT->KeyDown(VK_LBUTTON)) {
			OBJECT->option = 1;
		}
	}
	CAMERA->SetCamera({ WINSIZEX / 2,WINSIZEY / 2 });
	
	if (INPUT->KeyDown(VK_RETURN)) {
		SCENE->ChangeScene("title");
	}
}

void optionScene::Render()
{
	IMAGE->FindImage("mosaic1")->CenterRender(Vector2(WINSIZEX / 2, WINSIZEY / 2));

	if (OBJECT->option == 0) {
		IMAGE->FindImage("guide")->CenterRender(Vector2(WINSIZEX / 2, WINSIZEY / 2));
	}
	else if (OBJECT->option == 1) {
		IMAGE->FindImage("guide1")->CenterRender(Vector2(WINSIZEX / 2, WINSIZEY / 2));
	}
	else if (OBJECT->option == 2) {
		IMAGE->FindImage("guide2")->CenterRender(Vector2(WINSIZEX / 2, WINSIZEY / 2));
	}
}

void optionScene::Release()
{
}
