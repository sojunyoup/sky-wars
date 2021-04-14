#pragma once
#include "Scene.h"
class Scroolmap;
class tkaqjsScene :
	public Scene
{
private:
	int i;
	Scroolmap* m_map;
	Scroolmap* m_map1;
	Timer* range;
	Timer* range1;
	Timer* range2;
	Timer* mop3;
	Timer* mop2;
	Timer* mop;
	bool ist = false;
	bool isgo = false;
	bool isenemygo = false;
	bool istwoenemy = false;
	float y = 0;
	float y1 = 0;
	float y2 = 0;
	float x = 0;
	float x1 = 0;
	float x2 = 0;
	Vector2 vStage;
	Vector2 rkfhpos;
	Vector2 rkfhpos2;
	Vector2 rkfhpos3;
	Vector2 tpfhpos;
	Vector2 tpfhpos1;
	Vector2 tpfhpos2;

public:
	tkaqjsScene();
	virtual ~tkaqjsScene();

	virtual void Init()		override;
	virtual void Update()	override;
	virtual void Render()	override;
	virtual void Release()	override;
};