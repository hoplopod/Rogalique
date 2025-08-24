#include "pch.h"
#include "FollowComponent.h"
#include <iostream>

namespace Engine {

	FollowComponent::FollowComponent(GameObject* gameObject) : Component(gameObject)
	{
		transform = gameObject->GetComponent<TransformComponent>();
		spriteRenderer = gameObject->GetComponent<SpriteRendererComponent>();
		if (transform == nullptr) {
			std::cout << "FollowComponent requires a TransformComponent." << std::endl;
			gameObject->RemoveComponent(this);
		}
	}

	void FollowComponent::SetTarget(GameObject* targetObject) {
		if (targetObject) {
			targetTransform = targetObject->GetComponent<TransformComponent>();
			if (targetObject == nullptr) {
				std::cout << "Target object has no TransformComponent." << std::endl
					;
			}
		}
	}

	void FollowComponent::Update(float deltaTime) {
		if (transform == nullptr || targetTransform == nullptr) return;

		Vector2Df currentPos = transform->GetWorldPosition();
		Vector2Df targetPos = targetTransform->GetWorldPosition();
		Vector2Df direction = targetPos - currentPos;

		float length = direction.GetLength();

		if (length > 0.001f) {
			Vector2Df normalized = Vector2Df(direction.x / length, direction.y / length);
			transform->MoveBy(normalized * speed * deltaTime);

			if (spriteRenderer) {
				spriteRenderer->FlipX(direction.x < 0);
			}
		}
	}

	void FollowComponent::Render() {

	}

	void FollowComponent::SetSpeed(float newSpeed) {
		speed = newSpeed;
	}

	float FollowComponent::getSpeed() const{
		return speed;
	}
}