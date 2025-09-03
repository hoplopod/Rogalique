#include "Audio.h"

namespace Roguelike {

	Music::Music(const std::string& soundName) {
		gameObject = Engine::GameWorld::Instance()->CreateGameObject("Music: " + soundName);
		auto music = gameObject->AddComponent<Engine::AudioComponent>();
		music->SetAudio(*Engine::ResourceSystem::Instance()->GetSound(soundName));
		music->SetLoop(true);
		music->Play();
	}

	Sound::Sound(const std::string& soundName)
	{
		gameObject = Engine::GameWorld::Instance()->CreateGameObject("Sound: " + soundName);
		auto sound = gameObject->AddComponent<Engine::AudioComponent>();
		sound->SetAudio(*Engine::ResourceSystem::Instance()->GetSound(soundName));
		sound->SetLoop(false);
	}

}