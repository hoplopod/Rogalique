#pragma once

#include "GameObject.h"
#include "GameWorld.h"
#include "ResourceSystem.h"

namespace Roguelike {

class Decor {
   public:
    Decor(const Engine::Vector2Df& position, std::string name);
    Engine::GameObject* GetGameObject();

   private:
    Engine::GameObject* gameObject;
};

}  // namespace Roguelike
