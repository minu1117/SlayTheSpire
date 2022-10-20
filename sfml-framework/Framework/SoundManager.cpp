#include "SoundManager.h"
#include "ResourceMgr.h"

SoundManager::SoundManager()
	: TotalChannels(64), totalVolume(100.f) {}

void SoundManager::Init()
{
	Release();

	for (int i = 0; i < TotalChannels; i++)
	{
		waiting.push_back(new Sound());
	}
}

void SoundManager::Release()
{
	for (auto sound : waiting)
	{
		delete sound;
	}
	waiting.clear();

	for (auto sound : playing)
	{
		delete sound;
	}
	playing.clear();
}

void SoundManager::Play(string id, bool loop)
{
	if (waiting.empty())
		return;

	Sound* sound = waiting.front();
	waiting.pop_front();

	SoundBuffer* sBuffer = RESOURCE_MGR->GetSoundBuffer(id);
	sound->setBuffer(*sBuffer);
	sound->setLoop(loop);
	sound->setVolume(totalVolume);
	sound->play();

	playing.push_back(sound);
}

void SoundManager::StopAll()
{
	for (auto sound : playing)
	{
		sound->stop();
	}
}

void SoundManager::Update(float dt)
{
	auto it = playing.begin();
	while (it != playing.end())
	{
		if ((*it)->getStatus() == SoundSource::Stopped)
		{
			(*it)->resetBuffer();
			waiting.push_back((*it));
			it = playing.erase(it);
		}
		else
		{
			it++;
		}
	}
}
