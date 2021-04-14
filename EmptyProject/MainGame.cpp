#include "DXUT.h"
#include "MainGame.h"
#include "IngameScene.h"
#include "TitleScene.h"
#include "ChoiceScene.h"
#include "oneBossScene.h"
#include "optionScene.h"
#include "credutScene.h"
#include "twoScene.h"
#include "guidescene.h"
#include "twoBossScene.h"
#include "tkaqjsScene.h"
#include "EndScene.h"

MainGame::MainGame()
{
}


MainGame::~MainGame()
{
	Release();
}

void MainGame::Init()
{
	srand(time(NULL));
	CAMERA->Reset();

	SCENE->AddScene("title", new TitleScene);
	SCENE->AddScene("option", new optionScene);
	SCENE->AddScene("ingame", new IngameScene);
	SCENE->AddScene("choice", new ChoiceScene);
	SCENE->AddScene("oneBoss", new oneBossScene); 
	SCENE->AddScene("credut", new credutScene);
	SCENE->AddScene("twoScene", new twoScene); 
	SCENE->AddScene("guidescene", new guidescene); 
	SCENE->AddScene("tkaqjsScene", new tkaqjsScene);
	SCENE->AddScene("twoBossScene", new twoBossScene);
	SCENE->AddScene("EndScene", new EndScene);

	SCENE->ChangeScene("title");
}

void MainGame::Release()
{
	ImageManager::ReleaseInstance();
	SceneManager::ReleaseInstance();
	InputManager::ReleaseInstance();
	CameraManager::ReleaseInstance();
	Math::ReleaseInstance();
	ObjectManager::ReleaseInstance();
	Timer::ReleaseInstance();
}

void MainGame::Update()
{

	CAMERA->Update();
	SCENE->Update();
	OBJECT->Update();
	INPUT->Update();
}

void MainGame::Render()
{
	CAMERA->SetTransform();
	IMAGE->Begin();
	SCENE->Render();
	OBJECT->Render();
	IMAGE->End();
}

void MainGame::LostDevice()
{
	IMAGE->LostDevice();
}

void MainGame::ResetDevice()
{
	IMAGE->ResetDevice();
}
