#include "DXUT.h"
#include "CameraManager.h"
#include "Object.h"

CameraManager::CameraManager()
{
	Init();
}


CameraManager::~CameraManager()
{
	Release();
}

void CameraManager::Init()
{
	m_vCameraPos = D3DXVECTOR2(0, 0);
	m_vViewSize = D3DXVECTOR2((float)WINSIZEX, (float)WINSIZEY);
	m_vScale = m_vEndScale = D3DXVECTOR3(1, 1, 1);

	m_fAngle = 0.0f;
	m_ShakeTime = 0;

	D3DXMatrixOrthoLH(&m_matProj, m_vViewSize.x, -m_vViewSize.y, 0, 1);

	m_pFollowObj = nullptr;
	m_bFollowActive = false;
}

void CameraManager::Release()
{

}

void CameraManager::SetTransform()
{
	DXUTGetD3D9Device()->SetTransform(D3DTS_VIEW, &m_matView);
	DXUTGetD3D9Device()->SetTransform(D3DTS_PROJECTION, &m_matProj);
}

void CameraManager::SetFollowObj(Object * pFollow)
{
	m_pFollowObj = pFollow;

	if (m_pFollowObj)
		m_bFollowActive = true;
	else
		m_bFollowActive = false;
}

void CameraManager::MoveCamera(const D3DXVECTOR2 & vPlusPos)
{
	m_vCameraPos += vPlusPos;
}

void CameraManager::SetCamera(const D3DXVECTOR2 & vSetPos)
{
	m_vCameraPos = vSetPos;
}

void CameraManager::Update()
{
	if (m_ShakeTime >= timeGetTime())
	{
		m_vCameraPos += D3DXVECTOR2(rand() % 20 - 10, rand() % 20 - 10);
	}

	if (m_bFollowActive)
	{
		if ((m_pFollowObj->vPos.x > m_vCameraPos.x + 50 ||
			m_pFollowObj->vPos.x < m_vCameraPos.x - 50)
			|| (m_pFollowObj->vPos.y > m_vCameraPos.y + 50 ||
				m_pFollowObj->vPos.y < m_vCameraPos.y - 50)
			)
			moveAlarm = true;

		if (moveAlarm)
		{
			// 선형 이동
			MATH->Lerp<Vector2>(&m_vCameraPos, m_vCameraPos, m_pFollowObj->vPos, (float)(100 * DXUTGetElapsedTime()));
			MATH->Lerp<Vector3>(&m_vScale, m_vScale, m_vEndScale, (float)(7 * DXUTGetElapsedTime()));
		}

		Vector2 length = m_pFollowObj->vPos - m_vCameraPos;

		if (D3DXVec2Length(&length) < 20)
		{
			moveAlarm = false;
		}
		// 시점 고정
		//m_vCameraPos = D3DXVECTOR2(m_pFollowObj->GetInfo().vPos);
		//m_vScale = m_vEndScale;

	}

	this->m_matView = D3DXMATRIX(
		m_vScale.x, 0, 0, 0,
		0, m_vScale.y, 0, 0,
		0, 0, m_vScale.z, 0,
		-m_vCameraPos.x, -m_vCameraPos.y, 0, 1);
}

void CameraManager::Reset()
{
	m_vCameraPos = Vector2(WINSIZEX / 2, WINSIZEY / 2);
	m_vScale = m_vEndScale = D3DXVECTOR3(1, 1, 1);

	m_fAngle = 0.0f;

	m_pFollowObj = nullptr;
	m_bFollowActive = false;
}

void CameraManager::CameraShake(float _time)
{
	if (m_ShakeTime <= _time + timeGetTime())
		m_ShakeTime = _time + timeGetTime();
}




