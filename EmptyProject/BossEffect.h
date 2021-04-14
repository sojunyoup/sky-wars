#pragma once
#include"Object.h"
class BossEffect : public Object
{
private:
	int enem = 0;
	Timer* antimer;
	int i;

public:
	// Object��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	virtual void onCollisionStay(Object* obj) override;
	virtual void onCollisionExit(Object* obj) override;
};

