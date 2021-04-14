#include "DXUT.h"
#include "Scroolmap.h"



Scroolmap::Scroolmap(texture* texture)
	:m_scrool(0)
{
	m_backGround = texture;
}

Scroolmap::~Scroolmap()
{
}

void Scroolmap::Update(float speed)
{
	m_scrool += speed * D_TIME;
}

void Scroolmap::Render()
{
	float renderPos = (int)m_scrool % m_backGround->info.Height;
	m_backGround->Render({ 0, renderPos - m_backGround->info.Height });
	m_backGround->Render({ 0, renderPos });
}