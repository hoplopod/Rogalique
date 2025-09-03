#include "pch.h"
#include "PlayerItems.h"

namespace Roguelike {

	PlayerItems::PlayerItems(const Engine::Vector2Df& position, std::string name)
	{
		gameObject = Engine::GameWorld::Instance()->CreateGameObject(name);
		auto transform = gameObject->GetComponent<Engine::TransformComponent>();
		transform->SetWorldPosition(position);

		auto renderer = gameObject->AddComponent<Engine::SpriteRendererComponent>();
		renderer->SetTexture(*Engine::ResourceSystem::Instance()->GetTextureMapElementShared(name, 0));
		renderer->SetPixelSize(200, 200);

		auto input = gameObject->AddComponent<Engine::InputComponent>();

		auto movement = gameObject->AddComponent<Engine::MovementComponent>();
		movement->SetSpeed(400.f);

		auto mouse = gameObject->AddComponent<Engine::MouseComponent>();

	}

	Engine::GameObject* PlayerItems::GetGameObject()
	{
		return gameObject;
	}

}