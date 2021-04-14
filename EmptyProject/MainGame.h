#pragma once
class MainGame
{
public:
	MainGame();
	~MainGame();

	void Init();
	void Release();
	void Update();
	void Render();

	void LostDevice();
	void ResetDevice();
};

