#pragma once
#include "Scene.h"
class optionScene :
	public Scene
{
private:
	Vector2 Mpos;
public:
	optionScene();
	virtual ~optionScene();
	// Scene��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};