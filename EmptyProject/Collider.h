#pragma once
#include "Object.h"
class Object;

class Collider :
	public RECT
{
public:
	Object*	lpGameObject = nullptr;

public:
	Collider();
	virtual ~Collider();

	void	Init();
	void	SetRange(float width, float height);

	RECT GetRect()
	{
		RECT rt;

		rt.left = left;
		rt.right = right;
		rt.top = top;
		rt.bottom = bottom;

		return rt;
	}
};