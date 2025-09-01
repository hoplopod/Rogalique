#pragma once

#include "Component.h"
#include "GameObject.h"
#include "GameWorld.h"
#include "TransformComponent.h"
#include "RenderSystem.h"
#include "PVESystem.h"
#include "PhysicsSystem.h"

namespace Engine {

	class MouseComponent : public Component {
	public:
		MouseComponent(GameObject* gameObject);

		void Update(float deltaTime) override;
		void Render() override;

		Vector2Df attachmentToAnObject();

	private:
		float maxDistance = 200.f;
		float tapRadius = 200.f;

		TransformComponent* transform;
		sf::Event event;
	};

}
