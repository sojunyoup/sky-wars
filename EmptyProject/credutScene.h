#pragma once
#include "Scene.h"
class credutScene :
	public Scene
{
public:
	credutScene();
	virtual ~credutScene();
	//bool j[256] = false;
	// Scene��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};