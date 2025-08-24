#include "Music.h"

namespace Roguelike {

	Music::Music(const std::string& soundName) {
		gameObject = Engine::GameWorld::Instance()->CreateGameObject("Music: " + soundName);
		auto music = gameObject->AddComponent<Engine::AudioComponent>();
		music->SetAudio(*Engine::ResourceSystem::Instance()->GetSound(soundName));
		music->SetLoop(true);
		music->Play();
	}

}