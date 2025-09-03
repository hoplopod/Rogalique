#pragma once

#include "Component.h"
#include "SpriteRendererComponent.h"
#include "TransformComponent.h"
#include <SFML/Window.hpp> 

namespace Engine
{
	class InputComponent : public Component
	{
	public:
		InputComponent(GameObject* gameObject);

		void Update(float deltaTime) override;
		void Render() override;

		float GetHorizontalAxis() const;
		float GetVerticalAxis() const;

	private:
		SpriteRendererComponent* spriteRenderer = nullptr;
		TransformComponent* transformObject = nullptr;

		float horizontalAxis = 0.f;
		float verticalAxis = 0.f;
	};
}