#include "pch.h"
#include "SpriteDirectionComponent.h"

Engine::SpriteDirectionComponent::SpriteDirectionComponent(GameObject* gameObject)
	: Component(gameObject)
{
	input = gameObject->GetComponent<InputComponent>();
	spriteRenderer = gameObject->GetComponent<SpriteRendererComponent>();
}

void Engine::SpriteDirectionComponent::Update(float deltaTime)
{
	if (input->GetHorizontalAxis() < 0)
	{
		spriteRenderer->FlipX(true);
	}
	if (input->GetHorizontalAxis() > 0)
	{
		spriteRenderer->FlipX(false);
	}
}

void Engine::SpriteDirectionComponent::Render()
{
}
