#pragma once
#include "Object.h"
class Player2ui :
	public Object
{
private:
	Vector2 player2;//{ WINSIZEX / 2 + 300, WINSIZEY / 2 + 400}
	Timer* firespeed;
	int enem = 0;
	int enem1 = 5;
public:
	// Object을(를) 통해 상속됨
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	virtual void onCollisionStay(Object* obj) override;
	virtual void onCollisionExit(Object* obj) override;
};

