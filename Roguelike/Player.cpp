#include "Player.h"
#include <ResourceSystem.h>
#include <SpriteColliderComponent.h>

namespace Roguelike
{
	Player::Player()
	{
		gameObject = Engine::GameWorld::Instance()->CreateGameObject("Player");
		auto playerRenderer = gameObject->AddComponent<Engine::SpriteRendererComponent>();

		playerRenderer->SetTexture(*Engine::ResourceSystem::Instance()->GetTextureShared("ball"));
		playerRenderer->SetPixelSize(32, 32);

		auto playerCamera = gameObject->AddComponent<Engine::CameraComponent>();
		playerCamera->SetWindow(&Engine::RenderSystem::Instance()->GetMainWindow());
		playerCamera->SetBaseResolution(1280, 720);

		auto playerInput = gameObject->AddComponent<Engine::InputComponent>();

		auto transform = gameObject->GetComponent<Engine::TransformComponent>();

		auto body = gameObject->AddComponent<Engine::RigidbodyComponent>();

		auto collider = gameObject->AddComponent<Engine::SpriteColliderComponent>();
	}

	Engine::GameObject* Player::GetGameObject()
	{
		return gameObject;
	}
}