#include "DXUT.h"
#include "rhrenemy.h"

void rhrenemy::Init()
{
	int Speed = 300;
}

void rhrenemy::Update()
{

	vPos += Speed * Direction * D_TIME;
	if(m_Points.size() != 0) {
		D3DXVec2Normalize(&Direction, &(m_Points[m_Next] - vPos));
		if (D3DXVec2Length(&(vPos - m_Points[m_Next])) <= Speed * D_TIME + 1) {
			vPos = m_Points[m_Next];
			m_Next++;
			if (m_Next == m_Points.size())
			{
				m_Next = 0;
				m_Points.clear();
				Speed = 0;
			}
		}
	}
	AddPath(Vector2(WINSIZEX / 2, WINSIZEY / 2), Vector2(WINSIZEX/2, WINSIZEY/2));
}

void rhrenemy::Render()
{
	IMAGE->FindImage("Lookenemy")->CenterRender(vPos);
}

void rhrenemy::Release()
{
	//SAFE_DELETE(collider);
}

void rhrenemy::onCollisionStay(Object* obj)
{
	switch (obj->m_Tag)
	{
	case BULLET:
		Hp -= obj->Damage;
		break;
	case SKILL:
		isDestroy = true;
		break;
	}
}

void rhrenemy::onCollisionExit(Object* obj)
{
}

void rhrenemy::AddPath(Vector2 End, Vector2 Control)
{
	m_Next = 0;
	m_Points.clear();
	Vector2 v1;
	Vector2 v2;
	Vector2 v3;
	for (int i = 1; i <= 20; i++) {
		MATH->Lerp(&v1, vPos, Control, 0.05 * i);
		MATH->Lerp(&v2, Control, End, 0.05 * i);
		MATH->Lerp(&v3, v1, v2, 0.05 * i);
		m_Points.push_back(v3);
	}
	
}
