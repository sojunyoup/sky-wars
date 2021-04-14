#pragma once
#include "singleton.h"

class SoundManager :
	public singleton<SoundManager>
{
public:
	SoundManager();
	virtual ~SoundManager();
private:
		map<string, CSound*> m_sounds;
		CSoundManager* m_manager;
public:
	void AddSound(string key, wstring path);
	void Play(string key, BOOL isLoop);
	void Copy(string key);
	void Stop(string key);
	
};
#define SOUND SoundManager::GetInstance()

