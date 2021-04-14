#include "DXUT.h"
#include "guidescene.h"
#include"backButton.h"
#include"guideback.h"
#include"guidenext.h"
#include"Mose.h"

guidescene::guidescene()
{
}

guidescene::~guidescene()
{
}

void guidescene::Init()
{
	OBJECT->AddObject("Mouse", new Mose, Vector2(100, 100), MOUSE);
	OBJECT->AddObject("backButton", new backButton, Vector2(WINSIZEX / 2 - 550, WINSIZEY / 2), UI);
	OBJECT->AddObject("guideback", new guideback, Vector2(WINSIZEX / 2 - 150, WINSIZEY / 2 + 300), UI);
	OBJECT->AddObject("guidenext", new guidenext, Vector2(WINSIZEX / 2 + 150, WINSIZEY / 2 + 300), UI);
}

void guidescene::Update()
{
	CAMERA->SetCamera({ WINSIZEX / 2,WINSIZEY / 2 });
}

void guidescene::Render()
{
	IMAGE->FindImage("mosaic1")->CenterRender(Vector2(WINSIZEX / 2, WINSIZEY / 2));
	if (OBJECT->isguide == false) {
		IMAGE->FindImage("1GUIDE")->CenterRender(Vector2(WINSIZEX / 2, WINSIZEY / 2));
		IMAGE->FindImage("1of1")->CenterRender(Vector2(WINSIZEX / 2 - 150, WINSIZEY / 2 + 300));
	}
	else if (OBJECT->isguide == true)
	{
		IMAGE->FindImage("2GUIDE")->CenterRender(Vector2(WINSIZEX / 2, WINSIZEY / 2));
	}
}

void guidescene::Release()
{
}
