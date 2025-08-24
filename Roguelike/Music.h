#pragma once

#include "AudioComponent.h"
#include "GameWorld.h"
#include "ResourceSystem.h"

namespace Roguelike {

	class Music {
	public:
		Music(const std::string& soundName);

	private:
		Engine::GameObject* gameObject;
	};

}


