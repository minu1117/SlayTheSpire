#pragma once
#include "../3rd/Singleton.h"
#include <SFML/Audio.hpp>
#include <list>
using namespace std;
using namespace sf;

class SoundManager : public Singleton<SoundManager>
{
protected:
	list<Sound*> playing;
	list<Sound*> waiting;

	float totalVolume;

public:
	SoundManager();
	~SoundManager() {};
	const int TotalChannels;

	void Init();
	void Release() { Release(); };

	void Play(string id, bool loop = false);
	void StopAll();
	void Update(float dt);
};

#define SOUND_MGR (SoundManager::GetInstance())