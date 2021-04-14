#pragma once

#include "singleton.h"
//C++에서는 구조체와 클래스의 차이가 거의 없다
//struct는 기본이 public
//class는 기본이 private로 되어있을뿐
//내부 구조도 거의 같고 안에 함수도 넣을수 있다.
struct texture
{
	LPDIRECT3DTEXTURE9 texturePtr;
	D3DXIMAGE_INFO info;

	texture(LPDIRECT3DTEXTURE9 texturePtr, D3DXIMAGE_INFO info)
		:texturePtr(texturePtr), info(info)
	{
	}

	void CenterRender(Vector2 pos, float rot = 0, Vector2 size = Vector2(1, 1), D3DCOLOR color = D3DCOLOR_XRGB(255, 255, 255));
	void Render(Vector2 pos, float rot = 0, Vector2 size = Vector2(1, 1));

	void Release();
};

struct VECtexture {
	vector<texture*> m_VecTex;
public:
	VECtexture();
	~VECtexture();

	void ADDIMAGE(texture* tempImage);
	texture* FINDIMAGE(int count = -1);
};

//singleton을 상속받았다. 어디서든 접근이 가능해짐
class ImageManager : public singleton <ImageManager>
{
private:
	LPD3DXSPRITE m_sprite;
	map<string, texture*> m_images;
	map<string, VECtexture*> vecImages;
	//stl에는 map이라는 자료형이 있는데
	//이름으로 값을 찾을때, 가장 높은 효율을 보여준다
	LPD3DXFONT lpFont;
private:
	void Init();
	void Release();
public:
	ImageManager();
	~ImageManager();


	texture* AddImage(const string& key, const string& path, const int& number = 0);
	texture* FindImage(const string& key);

	VECtexture* ADDVECIMAGE(const string& key, const string& path, int max);
	VECtexture* FINDVECIMAGE(const string& key, int max);

	float LoadCount = 0;

	void Begin();
	void End();

	void CenterRender(texture* texturePtr, Vector2 pos, float rot = 0, Vector2 size = Vector2(1, 1), D3DCOLOR color = D3DCOLOR_XRGB(255, 255, 255));
	//가운데를 기준으로 이미지 랜더링
	void Render(texture* texturePtr, Vector2 pos, float rot = 0, Vector2 size = Vector2(1, 1));
	//좌상단을 기준으로 이미지 랜더링

	void drawText(const string& str, Vector2 pos, float size, D3DCOLOR color, bool Center);

	void LostDevice();
	void ResetDevice();
	//함수의 인자는 기본적으로 4개까지 사용하는것이 좋다.(4개를 넘어가면 급격히 느려진다)
	//자세한 이유는 나중에 레지스터와 시스템 캐시를 공부할때 알아보면 좋음
};

#define IMAGE ImageManager::GetInstance()