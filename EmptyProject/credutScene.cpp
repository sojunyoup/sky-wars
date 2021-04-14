#include "DXUT.h"
#include "credutScene.h"

credutScene::credutScene()
{
}

credutScene::~credutScene()
{
}

void credutScene::Init()
{

}

void credutScene::Update()
{
	for (int i = 0; i < 256; ++i)
	{
		if (INPUT->KeyDown(i))
			SCENE->ChangeScene("title");
	}
	CAMERA->SetCamera({ WINSIZEX / 2,WINSIZEY / 2 });
}

void credutScene::Render()
{
	IMAGE->FindImage("Credit")->CenterRender(Vector2(WINSIZEX / 2, WINSIZEY / 2));
}

void credutScene::Release()
{
}
