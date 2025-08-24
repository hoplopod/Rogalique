#include "pch.h"
#include "Ai.h"
#include "MovementComponent.h"
#include "SpriteDirectionComponent.h"
#include "SpriteColliderComponent.h"
#include "SpriteMovementAnimationComponent.h"
#include "FollowComponent.h"

namespace Roguelike {

	AI::AI(const Engine::Vector2Df& position, Engine::GameObject* player) {
		gameObject = Engine::GameWorld::Instance()->CreateGameObject("ai");
		auto transform = gameObject->GetComponent<Engine::TransformComponent>();
		transform->SetWorldPosition(position);

		auto renderer = gameObject->AddComponent<Engine::SpriteRendererComponent>();
		renderer->SetTexture(*Engine::ResourceSystem::Instance()->GetTextureMapElementShared("ai", 0));
		renderer->SetPixelSize(100, 100);

		auto follower = gameObject->AddComponent<Engine::FollowComponent>();
		follower->SetTarget(player);
		follower->SetSpeed(120.f);

		auto rigidbody = gameObject->AddComponent<Engine::RigidbodyComponent>();
		rigidbody->SetKinematic(false);

		auto collider = gameObject->AddComponent<Engine::SpriteColliderComponent>();

	}

	Engine::GameObject* AI::GetGameObject()
	{
		return gameObject;
	}

}