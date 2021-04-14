#pragma once
#include "Scene.h"
class Scroolmap;
class EndScene :
	public Scene
{
private:
	float score2;

	int i;
	int j;
	int x;
	Vector2 one = {WINSIZEX/2 - 100, WINSIZEY/2 - 140};
	Vector2 two = { WINSIZEX / 2 - 100, WINSIZEY / 2  };
	Vector2 three = { WINSIZEX / 2 - 100, WINSIZEY / 2 + 140 };

	char oneT[10000];
	char twoT[10000];
	char threeT[10000];
	int scoreCH = 0;
	D3DXCOLOR color;

public:
	EndScene();
	virtual ~EndScene();
	virtual void Init()		override;
	virtual void Update()	override;
	virtual void Render()	override;
	virtual void Release()	override;
};