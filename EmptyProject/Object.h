#pragma once
#include "Collider.h"

enum ObjectTag : char
{
	NONE,
	EBULLET,
	BULLET,
	PLAYER,
	BOSS,
	ENEMY,
	EFFECT,
	ITEM,
	UI,
	MOUSE,
	SKILL,
	END,
}typedef Tag;

class Object
{
	friend class cObjectManager;
public:
	Object();
	virtual ~Object();

	texture*		m_image;
	Vector2			vPos;
	Collider*		collider;
	Tag				m_Tag;
	string			m_Key;

	float			Hp;
	float			Speed;
	float			Damage;
	float			MaxHp;
	bool			isDestroy = false;
	int				playice = 0;

public:

	virtual void Init()										PURE;
	virtual void Update()									PURE;
	virtual void Render()									PURE;
	virtual void Release()									PURE;
	virtual void onCollisionStay(Object* obj)				PURE;
	virtual void onCollisionExit(Object* obj)				PURE;

	bool CheckDestroy() { return isDestroy; }
};

