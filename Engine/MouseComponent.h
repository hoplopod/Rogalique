#pragma once

#include "Component.h"
#include "GameObject.h"
#include "GameWorld.h"
#include "TransformComponent.h"
#include "RenderSystem.h"
#include "PVESystem.h"
#include "PhysicsSystem.h"
#include "TimerComponent.h"

namespace Engine {

	enum class MouseStatus {
		statusPalm,
		statusFist
	};

	class MouseComponent : public Component {
	public:
		MouseComponent(GameObject* gameObject);

		void Update(float deltaTime) override;
		void Render() override;

		Vector2Df attachmentToAnObject();

	private:
		float maxDistance = 200.f;
		float tapRadius = 100.f;

		MouseStatus status = MouseStatus::statusPalm;
		TransformComponent* transform;
		SpriteRendererComponent* renderer;
		sf::Event event;
	};

}
