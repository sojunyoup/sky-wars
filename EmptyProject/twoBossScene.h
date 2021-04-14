#pragma once
#include "Scene.h"
class Scroolmap;
class twoBossScene :
	public Scene
{
private:
	Scroolmap* m_map;
	Vector2 Boss;
	Timer* isending;
	bool isboss;
	bool isbossS = false;

public:
	twoBossScene();
	virtual ~twoBossScene();
	// Scene��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};