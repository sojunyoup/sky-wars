#pragma once
#include "singleton.h"
class Math :
	public singleton<Math>
{
public:
	Math();
	virtual ~Math();

	template <typename T>

	void Lerp(T* target, T& start, T& finsh, float time)
	{
		*target = start + (finsh - start) * time * DXUTGetElapsedTime();
	}

	Vector2 RotateVec(Vector2 Vec, float Rot);


};
#define MATH Math::GetInstance()