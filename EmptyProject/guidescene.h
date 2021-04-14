#pragma once
#include "Scene.h"
class guidescene :
	public Scene
{
private:
	int i = 1;

	int guidnum = 0;
public:
	
	guidescene();
	virtual ~guidescene();
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};