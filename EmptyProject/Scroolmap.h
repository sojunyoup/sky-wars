#pragma once
class Scroolmap
{
private:
	float m_scrool;
	texture* m_backGround;
public:
	Scroolmap(texture* texture);
	~Scroolmap();

	void Update(float speed);
	void Render();

	float GetScrool() { return m_scrool; }
};