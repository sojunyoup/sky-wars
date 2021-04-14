#pragma once
#include "Object.h"

class BossBullet : public Object
{
protected:
	Vector2 m_dir1 = Vector2(0, -1);

public:
	BossBullet(const D3DXVECTOR2& pos, const D3DXVECTOR2 dir1);
	~BossBullet();

	// Object을(를) 통해 상속됨
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	virtual void onCollisionStay(Object* obj) override;
	virtual void onCollisionExit(Object* obj) override;
};

