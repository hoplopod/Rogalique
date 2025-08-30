#include "pch.h"
#include "Decor.h"

namespace Roguelike {

	Decor::Decor(const Engine::Vector2Df& position, std::string name)
	{
		gameObject = Engine::GameWorld::Instance()->CreateGameObject(name);
		auto transform = gameObject->GetComponent<Engine::TransformComponent>();
		transform->SetWorldPosition(position);

		auto renderer = gameObject->AddComponent<Engine::SpriteRendererComponent>();
		renderer->SetTexture(*Engine::ResourceSystem::Instance()->GetTextureMapElementShared(name, 0));
		renderer->SetPixelSize(100, 100);

	}

	Engine::GameObject* Decor::GetGameObject()
	{
		return gameObject;
	}

}


