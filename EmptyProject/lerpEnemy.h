#pragma once
#include "Object.h"
class lerpEnemy :
	public Object
{
public:
	Vector2 vPlayer;
	Timer* fire;
public:
	// Object을(를) 통해 상속됨
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	virtual void onCollisionStay(Object* obj) override;
	virtual void onCollisionExit(Object* obj) override;
};


