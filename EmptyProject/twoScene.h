#pragma once
#include "Scene.h"
class Scroolmap;
class twoScene :
	public Scene
{
private:
	int i;
	Scroolmap* m_map;
	Scroolmap* m_map1;
	Timer* range;
	Timer* mop2;
	Timer* mop;
	bool ist = false;
	bool isgo = false;
	bool isenemygo = false;
	bool istwoenemy = false;
	Vector2 vStage;

public:
	twoScene();
	virtual ~twoScene();

	virtual void Init()		override;
	virtual void Update()	override;
	virtual void Render()	override;
	virtual void Release()	override;
};