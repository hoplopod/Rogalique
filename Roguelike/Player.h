#pragma once

#include "CameraComponent.h"
#include "GameWorld.h"
#include "SpriteRendererComponent.h"
#include "RenderSystem.h"
#include "InputComponent.h"
#include "GameObject.h"
#include "TimerComponent.h"
#include "SpawnerComponent.h"

namespace Roguelike {
class Player {
   public:
    Player(const Engine::Vector2Df& position);
    Engine::GameObject* GetGameObject();

   private:
    Engine::GameObject* gameObject;
};
}  // namespace Roguelike