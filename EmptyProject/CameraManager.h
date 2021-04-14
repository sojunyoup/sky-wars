#pragma once
#include "singleton.h"

class Object;
class CameraManager : public singleton<CameraManager>
{
private:
	D3DXMATRIX m_matProj, m_matView;

	Vector2 m_vCameraPos;
	Vector2 m_vViewSize;

	Vector3 m_vScale;
	Vector3 m_vEndScale;
	Vector3 m_vTarget;

	Object* m_pFollowObj;
	bool m_bFollowActive;

	float m_fAngle;
	float m_ShakeTime;

	bool moveAlarm = false;


	void Init();
	void Release();

public:
	void SetTransform();

	void SetFollowObj(Object* pFollow);
	void MoveCamera(const D3DXVECTOR2& vPlusPos);
	void SetCamera(const D3DXVECTOR2& vSetPos);

	D3DXVECTOR2& GetCameraPos() { return m_vCameraPos; }
	D3DXVECTOR2& GetScroll() {
		return  D3DXVECTOR2(WINSIZEX / 2 - m_vCameraPos.x, WINSIZEY / 2 - m_vCameraPos.y);
	}
	D3DXVECTOR3& GetCameraScale() { return m_vScale; }
	void SetCameraScale(const Vector3& Scale) { m_vScale = Scale; m_vEndScale = Scale; }

	float GetCameraAngle() { return m_fAngle; }
	Vector2 GetCameraView() { return m_vViewSize; }

	void Update();
	void Reset();

	void CameraShake(float _time);
public:
	CameraManager();
	virtual~CameraManager();
};

#define CAMERA CameraManager::GetInstance()

#define CAMERASIZEX   CAMERA->GetCameraWidth()
#define CAMERASIZEY CAMERA->GetCameraHeight()