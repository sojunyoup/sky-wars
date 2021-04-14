#include "DXUT.h"
#include "ImageManager.h"

void texture::CenterRender(Vector2 pos, float rot, Vector2 size, D3DCOLOR color)
{
	IMAGE->CenterRender(this, pos, rot, size, color);
}

void texture::Render(Vector2 pos, float rot, Vector2 size)
{
	IMAGE->Render(this, pos, rot, size);
}

void texture::Release()
{
	SAFE_RELEASE(texturePtr);
}


ImageManager::ImageManager()
	:m_sprite(nullptr)
{
	Init();
}


ImageManager::~ImageManager()
{
	Release();
}

//불러올 이미지를 부를 이름과 경로
texture* ImageManager::AddImage(const string& key, const string& path, const int& number)
{
	auto find = m_images.find(key);//이미 있는 이름을 다시 쓰려고 하는게 아닌지 확인해본다
	if (find == m_images.end())
	{
		LPDIRECT3DTEXTURE9 texturePtr;
		D3DXIMAGE_INFO info;

		if (D3DXCreateTextureFromFileExA(g_device, path.c_str(), D3DX_DEFAULT_NONPOW2, D3DX_DEFAULT_NONPOW2, 0, 0,
			D3DFMT_UNKNOWN, D3DPOOL_MANAGED, D3DX_DEFAULT, D3DX_DEFAULT, 0, &info, nullptr, &texturePtr) == S_OK)
		{
			LoadCount++;
			texture* text = new texture(texturePtr, info);
			m_images.insert(make_pair(key, text));
			return text;
		}
		//#pragma region 로딩실패
		//		DEBUG_LOG("ERROR! 이미지 로딩에 실패했습니다. 파일경로를 다시 확인해주세요");
		//		DEBUG_LOG("\tkey : %s\t path : %s", key.c_str(), path.c_str());
		//#pragma endregion
				//이미지 로딩이 실패했을경우(없는 파일, cpu메모리 부족등등) 이곳으로 오게 된다
		return nullptr;
	}
	//이미 불러온 이미지를 다시 불러오려 했거나
	//다른 이미지를 같은 이름으로 쓰고 있을경우 이곳으로 오게 된다
	return find->second;
}

texture* ImageManager::FindImage(const string& key)
{
	auto find = m_images.find(key);//이름으로 이미지를 찾아본다
	if (find == m_images.end()) return nullptr;//없으면 nullptr을 뱉는다
	return find->second;//있으면 그걸 뱉는다
}

VECtexture* ImageManager::ADDVECIMAGE(const string& key, const string& path, int max)
{
	auto find = vecImages.find(key);
	if (find != vecImages.end())
		return find->second;

	VECtexture* vec = new VECtexture();

	for (int i = 1; i <= max; i++)
	{
		LPDIRECT3DTEXTURE9 lpTexture;
		D3DXIMAGE_INFO info;

		char ch[256];
		sprintf(ch, "%s/(%d).png", path.c_str(), i);

		if (D3DXCreateTextureFromFileExA(g_device, ch, D3DX_DEFAULT_NONPOW2, D3DX_DEFAULT_NONPOW2, 0, 0,
			D3DFMT_A8R8G8B8, D3DPOOL_MANAGED, D3DX_DEFAULT, D3DX_DEFAULT, NULL, &info, nullptr, &lpTexture) == S_OK)
		{
			LoadCount++;
			texture* text = new texture(lpTexture, info);
			vec->ADDIMAGE(text);
		}

	}

	vecImages.insert(make_pair(key, vec));
	return vec;
}


VECtexture* ImageManager::FINDVECIMAGE(const string& key, int max)
{
	return vecImages[key];
}

void ImageManager::Init()
{
#pragma region Load
	//이미지를 추가 해준다.

	//1player
	AddImage("player", "./Resource/player/player1.png");
	AddImage("lplayer1", "./Resource/player/lplayer1.png");
	AddImage("rplayer1", "./Resource/player/rplayer1.png");
	AddImage("Hwo1player", "./Resource/Hwo1player.png");
	AddImage("player1gun", "./Resource/player/player1gun.png");

	//2player
	AddImage("player3", "./Resource/player/player3.png");
	AddImage("lplayer3", "./Resource/player/lplayer3.png");
	AddImage("rplayer3", "./Resource/player/rplayer3.png");
	AddImage("player3gun", "./Resource/player/player3gun.png");

	//플레이어 충돌 처리
	AddImage("collider", "./Resource/player/collider.png");

	AddImage("Hwo3player", "./Resource/Hwo3player.png");

	//버프
	AddImage("Inc_Atk", "./Resource/ingameui/Inc_Atk.png");
	AddImage("Inc_Atknone", "./Resource/ingameui/Inc_Atknone.png");
	AddImage("Inc_Mov-Sp", "./Resource/ingameui/Inc_Mov-Sp.png");
	AddImage("none", "./Resource/ingameui/none.png");
	AddImage("Healon", "./Resource/ingameui/Healon.png");
	AddImage("Healnone", "./Resource/ingameui/Healnone.png");


	//플레이어 이팩트
	ADDVECIMAGE("player1effect", "./Resource/player/player1effect", 10);
	ADDVECIMAGE("player2effect", "./Resource/player/player2effect", 10);

	//총알
	AddImage("rkfh.png", "./Resource/bullet/rkfh.png.png");
	AddImage("Bullet", "./Resource/bullet/pbullet2.png");
	AddImage("Bullet", "./Resource/bullet/pbullet2.png");
	AddImage("Bullet_PL", "./Resource/bullet/Bullet_PL.png");
	AddImage("Bullet_EN", "./Resource/bullet/Bullet_EN.png");
	AddImage("Bullet_Blue", "./Resource/bullet/Bullet_Blue.png");
	AddImage("Bulleet_Circle", "./Resource/bullet/Bulleet_Circle.png"); 
	AddImage("rkfh", "./Resource/bullet/rkfh.png"); 
	AddImage("boom", "./Resource/bullet/boom.png"); 

	//스킬
	AddImage("Skill_2on", "./Resource/ingameui/Skill_2on.png");
	AddImage("Skill_2off", "./Resource/ingameui/Skill_2off.png");
	AddImage("Skill_1on", "./Resource/ingameui/Skill_1on.png");
	AddImage("Skill_1off", "./Resource/ingameui/Skill_1off.png");
	AddImage("Sheildon", "./Resource/ingameui/Sheildon.png");
	AddImage("Sheildoff", "./Resource/ingameui/Sheildoff.png");
	AddImage("Barrier", "./Resource/ingameui/Barrier.png");

	//적, 보스, 보스 등장 이팩트
	ADDVECIMAGE("bosswarning", "./Resource/BOSS WARNING", 9);

	AddImage("Lookenemy", "./Resource/enemy/enemy1.png");
	AddImage("Enemy_2", "./Resource/enemy/Enemy_2.png");
	AddImage("goenemy", "./Resource/enemy/enemy2.png");

	AddImage("1stboss", "./Resource/1stBoss/Boss.png");

	AddImage("Health", "./Resource/ingameui/Health.png");
	AddImage("BG", "./Resource/ingameui/BG.png");
	AddImage("Ranking", "./Resource/Ranking.png");

	//2st boss
	ADDVECIMAGE("fly", "./Resource/2st Boss/fly", 3);
	AddImage("Boss_Body", "./Resource/2st Boss/Boss_Body.png");

	//이팩트
	ADDVECIMAGE("effect1", "./Resource/effect/1", 8);
	ADDVECIMAGE("effect2", "./Resource/effect/2", 8);
	ADDVECIMAGE("effect3", "./Resource/effect/3", 4);
	AddImage("playereffect", "./Resource/effect/playereffect.png");

	//가이드
	AddImage("guide1", "./Resource/guide1click.png");
	AddImage("guide2", "./Resource/guide2click.png");
	AddImage("guide", "./Resource/guide.png");
	AddImage("next", "./Resource/TITLEBUTTON/next.png");
	AddImage("back", "./Resource/TITLEBUTTON/back.png");

	//가이드 포함 모함
	AddImage("Back-Default", "./Resource/TITLEBUTTON/Back-Default.png");
	AddImage("Back-OnMouse", "./Resource/TITLEBUTTON/Back-OnMouse.png");
	AddImage("Back-Pressed", "./Resource/TITLEBUTTON/Back-Pressed.png");

	AddImage("Left-Default", "./Resource/TITLEBUTTON/Left-Default.png");
	AddImage("Left-Pressed", "./Resource/TITLEBUTTON/Left-Pressed.png");

	AddImage("Right-Default", "./Resource/TITLEBUTTON/Right-Default.png");
	AddImage("Right-Pressed", "./Resource/TITLEBUTTON/Right-Pressed.png");


	AddImage("1GUIDE", "./Resource/1GUIDE.png");
	AddImage("2GUIDE", "./Resource/2GUIDE.png");
	AddImage("3GUIDE", "./Resource/3GUIDE.png");

	AddImage("1of2", "./Resource/1of2.png");
	AddImage("2of2", "./Resource/2of2.png");

	//타이틀
	AddImage("Title", "./Resource/Button/Title.png");
	AddImage("Main_BG", "./Resource/Main_BG.png");
	AddImage("mosaic", "./Resource/TITLEBUTTON/mosaic.png");
	AddImage("mosaic1", "./Resource/TITLEBUTTON/mosaic1.png");
	AddImage("Credit", "./Resource/Credit.png");

	//스테이지
	AddImage("1stage", "./Resource/stage/1stage.png");
	AddImage("2stage", "./Resource/stage/2stage.png");
	  
	//플레이 버튼
	AddImage("Play-Default", "./Resource/TITLEBUTTON/Play-Default.png");
	AddImage("Play-OnMouse", "./Resource/TITLEBUTTON/Play-OnMouse.png");
	AddImage("Play-Pressed", "./Resource/TITLEBUTTON/Play-Pressed.png");

	AddImage("HTP-Default", "./Resource/TITLEBUTTON/HTP-Default.png");
	AddImage("HTP-OnMouse", "./Resource/TITLEBUTTON/HTP-OnMouse.png");
	AddImage("HTP-Pressed", "./Resource/TITLEBUTTON/HTP-Pressed.png");

	AddImage("Option-Default", "./Resource/TITLEBUTTON/Option-Default.png");
	AddImage("Option-OnMouse", "./Resource/TITLEBUTTON/Option-OnMouse.png");
	AddImage("Option-Pressed", "./Resource/TITLEBUTTON/Option-Pressed.png");

	AddImage("Credit-Default", "./Resource/TITLEBUTTON/Credit-Default.png");
	AddImage("Credit-OnMouse", "./Resource/TITLEBUTTON/Credit-OnMouse.png");
	AddImage("Credit-Pressed", "./Resource/TITLEBUTTON/Credit-Pressed.png");

	//맵
	AddImage("bossmap", "./Resource/bossmap.png");

	//엔딩
	AddImage("Ranking", "./Resource/Rankingpng");

#pragma endregion

	D3DXCreateSprite(g_device, &m_sprite);
}

void ImageManager::Release()
{
	for (auto iter : m_images)
	{
		iter.second->Release();
		SAFE_DELETE(iter.second);
	}
	m_images.clear();

	for (auto iter : vecImages)
	{
		SAFE_DELETE(iter.second);
	}
	vecImages.clear();

	m_sprite->Release();
}

void ImageManager::Begin()
{
	m_sprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_OBJECTSPACE);
}

void ImageManager::End()
{
	m_sprite->End();
}

void ImageManager::CenterRender(texture* texturePtr, Vector2 pos, float rot, Vector2 size, D3DCOLOR color)
{
	if (texturePtr)
	{
		D3DXMATRIXA16 mat;
		Vector2 CenterPos = Vector2(texturePtr->info.Width / 2, texturePtr->info.Height / 2);
		pos -= CenterPos;

		D3DXMatrixTransformation2D(&mat, &CenterPos, 0, &size, &CenterPos, rot, &pos);

		m_sprite->SetTransform(&mat);
		m_sprite->Draw(texturePtr->texturePtr, nullptr, nullptr, nullptr, color);
	}
}

void ImageManager::Render(texture* texturePtr, Vector2 pos, float rot, Vector2 size)
{
	if (texturePtr)
	{
		D3DXMATRIXA16 mat;
		Vector2 CenterPos = Vector2(0, 0);
		pos -= CenterPos;

		D3DXMatrixTransformation2D(&mat, &CenterPos, 0, &size, &CenterPos, rot, &pos);

		m_sprite->SetTransform(&mat);
		m_sprite->Draw(texturePtr->texturePtr, nullptr, nullptr, nullptr, D3DCOLOR_XRGB(255, 255, 255));
	}
}


void ImageManager::drawText(const string& str, Vector2 pos, float size, D3DCOLOR color, bool Center)
{
	D3DXMATRIX mat;
	if (!Center) {
		D3DXCreateFontA(g_device, size, 0, 10, 1, FALSE, HANGEUL_CHARSET, 0, 0, 0, "Fixedsys", &lpFont);
		D3DXMatrixTranslation(&mat, pos.x, pos.y, 0);
	}
	else {
		D3DXCreateFontA(g_device, size, 0, 0, 1, FALSE, HANGEUL_CHARSET, 0, 0, 0, "Fixedsys", &lpFont);
		D3DXMatrixTranslation(&mat, pos.x - size * (str.size() * 0.25), pos.y - size / 2.f, 0);
	}

	m_sprite->SetTransform(&mat);
	lpFont->DrawTextA(m_sprite, str.c_str(), str.size(), nullptr, DT_NOCLIP, color);

	SAFE_RELEASE(lpFont);
}

void ImageManager::LostDevice()
{
	m_sprite->OnLostDevice();
}

void ImageManager::ResetDevice()
{
	m_sprite->OnResetDevice();
}


VECtexture::VECtexture()
{
}

VECtexture::~VECtexture()
{
	for (auto iter : m_VecTex) {
		iter->Release();
		SAFE_DELETE(iter);
	}
	m_VecTex.clear();
}

void VECtexture::ADDIMAGE(texture* tempImage)
{
	m_VecTex.push_back(tempImage);
}

texture* VECtexture::FINDIMAGE(int count)
{
	if (count == -1)
		return m_VecTex[0];
	else
		return m_VecTex[count];
}
