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
	// Scene을(를) 통해 상속됨
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};