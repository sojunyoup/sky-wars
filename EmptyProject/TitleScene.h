#pragma once
#include "Scene.h"
class TitleScene :
	public Scene
{
private:
	Timer* isTitle;
	Vector2 vtitle;
public:
	TitleScene();
	virtual ~TitleScene();
	// Scene��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};