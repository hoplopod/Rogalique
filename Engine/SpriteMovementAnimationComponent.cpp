#include "pch.h"
#include "SpriteMovementAnimationComponent.h"

Engine::SpriteMovementAnimationComponent::SpriteMovementAnimationComponent(GameObject* gameObject)
	: Component(gameObject)
{
	movement = gameObject->GetComponent<MovementComponent>();
	renderer = gameObject->GetComponent<SpriteRendererComponent>();

	if (movement == nullptr)
	{
		std::cout << "Need movement component for movement animation" << std::endl;
		gameObject->RemoveComponent(this);
	}
	else if (renderer == nullptr)
	{
		std::cout << "Need renderer component for movement animation" << std::endl;
		gameObject->RemoveComponent(this);
	}
}

void Engine::SpriteMovementAnimationComponent::Initialize(const std::string& textureMapName, float newFramerate)
{
	for (int i = 0; i < ResourceSystem::Instance()->GetTextureMapElementsCount(textureMapName); i++)
	{
		textureMap.push_back(ResourceSystem::Instance()->GetTextureMapElementShared(textureMapName, i));
	}

	secondsForFrame = 1.f / newFramerate;
}

void Engine::SpriteMovementAnimationComponent::Update(float deltaTime)
{
	if (movement->GetAccelerationSquared() == 0.f)
	{
		if (counter > 0)
		{
			counter = 0;
			frame = 0;
			renderer->SetTexture(*textureMap[0]);
		}
		return;
	}

	counter += deltaTime;
	if (counter > secondsForFrame)
	{
		counter = 0;
		frame++;

		if (frame == textureMap.size())
		{
			frame = 0;
		}

		renderer->SetTexture(*textureMap[frame]);
	}
}

void Engine::SpriteMovementAnimationComponent::Render()
{
}
