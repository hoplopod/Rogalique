#pragma once
#include "GameObject.h"
#include "InputComponent.h"
#include "SpriteRendererComponent.h"

namespace Engine
{
	class SpriteDirectionComponent : public Component
	{
	public:
		SpriteDirectionComponent(GameObject* gameObject);

		void Update(float deltaTime) override;
		void Render() override;
	private:
		InputComponent* input;
		SpriteRendererComponent* spriteRenderer;
	};
}
