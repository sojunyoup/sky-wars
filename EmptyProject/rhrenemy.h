#pragma once
#include "Object.h"
class rhrenemy :
	public Object
{
public:
	vector<Vector2> m_Points;
	
	Vector2 Direction;
	int m_Next;


	// Object��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	virtual void onCollisionStay(Object* obj) override;
	virtual void onCollisionExit(Object* obj) override;

	void AddPath(Vector2 End, Vector2 Control);
};

