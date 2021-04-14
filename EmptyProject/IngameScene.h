#pragma once
#include "Scene.h"
class Scroolmap;
class IngameScene :
	public Scene
{
private:
	int i;
	Scroolmap* m_map;
	Scroolmap* m_map1;
	Timer* Respawn;
	Timer* range;
	Vector2 vStage;
	bool isgo = false;
	int yrkqt = (rand() % 170) + 100;
	int mop = 0;
public:
	IngameScene();
	virtual ~IngameScene();
	virtual void Init()		override;
	virtual void Update()	override;
	virtual void Render()	override;
	virtual void Release()	override;
};