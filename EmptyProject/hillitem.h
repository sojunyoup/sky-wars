#pragma once
#include "Object.h"
class hillitem :
	public Object
{
private:
	Vector2 vPlayer;
public:

	// Object��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	virtual void onCollisionStay(Object* obj) override;
	virtual void onCollisionExit(Object* obj) override;
};


