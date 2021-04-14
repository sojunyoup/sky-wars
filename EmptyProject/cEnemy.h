#pragma once
#include "Object.h"
class cEnemy :
	public Object
{
private:
	int rot = 0;
	D3DXVECTOR2 dir;
	Timer* firet;
public:
	
	// Object��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	virtual void onCollisionStay(Object* obj) override;
	virtual void onCollisionExit(Object* obj) override;
};


