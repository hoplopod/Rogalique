#pragma once

#include "CameraComponent.h"
#include "GameWorld.h"
#include "SpriteRendererComponent.h"
#include "RenderSystem.h"
#include "GameObject.h"
#include "Vector.h"
#include "PVESystem.h"
#include "TimerComponent.h"

namespace Engine {

	class AI {
	public:
		AI(const Engine::Vector2Df& position, Engine::GameObject* player, std::string name);
		Engine::GameObject* GetGameObject();
	private:
		Engine::GameObject* gameObject;

	};

}