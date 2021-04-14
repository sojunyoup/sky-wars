#pragma once
#include "Scene.h"
class Scroolmap;
class oneBossScene :
	public Scene
{
private:
	Scroolmap* m_map;
	Timer* isending;
	Vector2 Boss;
	bool isboss;
	bool isboss1 = false;

public:
	oneBossScene();
	virtual ~oneBossScene();
	// Scene을(를) 통해 상속됨
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};