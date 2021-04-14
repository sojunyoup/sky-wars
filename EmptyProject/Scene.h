#pragma once
class Scene abstract
{
public:
	virtual void Init()		PURE;
	virtual void Update()	PURE;
	virtual void Render()	PURE;
	virtual void Release()	PURE;

	Scene();
	virtual ~Scene();
};

