#pragma once

#include "GameObject.h"
#include "GameWorld.h"
#include "InputComponent.h"
#include "MouseComponent.h"

namespace Roguelike {

	class PlayerItems {
	public:
		PlayerItems(const Engine::Vector2Df& position, std::string name);
		Engine::GameObject* GetGameObject();
	private:
		Engine::GameObject* gameObject;
	};


}