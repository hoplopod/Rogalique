#include "pch.h"
#include "SpriteColliderComponent.h"

namespace Engine
{
	SpriteColliderComponent::SpriteColliderComponent(GameObject* gameObject) : ColliderComponent(gameObject)
	{
		auto spriteRenderer = gameObject->GetComponent<SpriteRendererComponent>();
		if (spriteRenderer == nullptr)
		{
			std::cout << "SpriteRenderer required to SpriteCollider." << std::endl;
			gameObject->RemoveComponent(this);
			return;
		}

		sprite = gameObject->GetComponent<SpriteRendererComponent>()->GetSprite();
		PhysicsSystem::Instance()->SubscribeColider(this);
	}
	SpriteColliderComponent::~SpriteColliderComponent()
	{
		if (&bounds != nullptr)
		{
			std::destroy_at(&bounds);
		}
		PhysicsSystem::Instance()->UnsubscribeColider(this);
	}

	void SpriteColliderComponent::Update(float deltaTime)
	{
		bounds = sprite->getGlobalBounds();
	}
	void SpriteColliderComponent::Render()
	{
		if (gameObject->GetComponent<SpriteRendererComponent>()->GetRenderCondition()) {
			sf::RectangleShape rectangle(sf::Vector2f(bounds.width, bounds.height));
			rectangle.setPosition(bounds.left, bounds.top);
			rectangle.setFillColor(sf::Color::Transparent);
			rectangle.setOutlineColor(sf::Color::White);
			rectangle.setOutlineThickness(4);

			RenderSystem::Instance()->Render(rectangle);
		}
	}
}