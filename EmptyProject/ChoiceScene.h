#pragma once
#include "Scene.h"
class ChoiceScene :
	public Scene
{
private:
	Timer* firespeed;
	int enem = 0;
	int enem1 = 5;
public:
	ChoiceScene();
	virtual ~ChoiceScene();
	// Scene을(를) 통해 상속됨
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};