#include "pch.h"
#include "PhysicsSystem.h"

namespace Engine
{
	PhysicsSystem* PhysicsSystem::Instance()
	{
		static PhysicsSystem physicsSystem;
		return &physicsSystem;
	}

	float PhysicsSystem::GetFixedDeltaTime() const
	{
		return fixedDeltaTime;
	}

	void PhysicsSystem::Update()
	{
		for (int i = 0; i < colliders.size(); i++)
		{
			auto body = colliders[i]->GetGameObject()->GetComponent<RigidbodyComponent>();
			if (body->GetKinematic())
			{
				continue;
			}

			for (int j = 0; j < colliders.size(); j++)
			{
				if (j == i)
				{
					continue;
				}

				if (!colliders[i]->GetGameObject()->GetComponent<SpriteRendererComponent>()->GetRenderCondition() || !colliders[j]->GetGameObject()->GetComponent<SpriteRendererComponent>()->GetRenderCondition()) {
					continue;
				}

				sf::FloatRect intersection;
				if (colliders[i]->bounds.intersects(colliders[j]->bounds, intersection))
				{
					if (colliders[i]->isTrigger != colliders[j]->isTrigger)
					{
						if (triggersEnteredPair.find(colliders[i]) == triggersEnteredPair.end() && triggersEnteredPair.find(colliders[j]) == triggersEnteredPair.end())
						{
							auto trigger = new Trigger(colliders[i], colliders[j]);
							colliders[i]->OnTriggerEnter(*trigger);
							colliders[j]->OnTriggerEnter(*trigger);

							triggersEnteredPair.emplace(colliders[i], colliders[j]);
						}
					}
					else if (!colliders[i]->isTrigger)
					{
						float intersectionWidth = intersection.width;
						float intersectionHeight = intersection.height;
						Vector2Df intersectionPosition = { intersection.left - 0.5f * intersectionWidth, intersection.top - 0.5f * intersectionHeight };

						Vector2Df aPosition = { colliders[i]->bounds.left,  colliders[i]->bounds.top };
						auto aTransform = colliders[i]->GetGameObject()->GetComponent<TransformComponent>();

						auto secondObject = colliders[j]->GetGameObject()->GetComponent<PVEComponent>();

						auto featureObject = colliders[i]->GetGameObject()->GetComponent<PVEComponent>();

						if (intersectionWidth > intersectionHeight)
						{
							if (intersectionPosition.y > aPosition.y)
							{
								aTransform->SetSignAxis({ 0,-1 });
								std::cout << "Top collision" << std::endl;
							}
							else
							{
								aTransform->SetSignAxis({ 0, 1 });
								std::cout << "Down collision" << std::endl;
							}
						}
						else
						{
							if (intersectionPosition.x > aPosition.x)
							{
								aTransform->SetSignAxis({ -1, 0 });
								std::cout << "Right collision" << std::endl;
							}
							else
							{
								aTransform->SetSignAxis({ 1, 0 });
								std::cout << "Left collision" << std::endl;
							}
						}

							if (secondObject != nullptr && aTransform->GetGameObject()->GetName() == "player") {
								featureObject->HitEntity();
								aTransform->SetEndCoordinats({ intersectionPosition.x + aTransform->GetPowerSmooth(aTransform->GetSignAxis().x), intersectionPosition.y + aTransform->GetPowerSmooth(aTransform->GetSignAxis().y) }, aTransform->GetSignAxis());
							}
							aTransform->MoveBy({ intersectionWidth * aTransform->GetSignAxis().x, intersectionHeight * aTransform->GetSignAxis().y });
						
					}
					auto collision = new Collision(colliders[i], colliders[j], intersection);
					colliders[i]->OnCollision(*collision);
					colliders[j]->OnCollision(*collision);
				}

			}
		}

		for (auto triggeredPair = triggersEnteredPair.cbegin(), nextTriggeredPair = triggeredPair; triggeredPair != triggersEnteredPair.cend(); triggeredPair = nextTriggeredPair)
		{
			++nextTriggeredPair;
			if (!triggeredPair->first->bounds.intersects(triggeredPair->second->bounds))
			{
				auto trigger = new Trigger(triggeredPair->first, triggeredPair->second);
				triggeredPair->first->OnTriggerExit(*trigger);
				triggeredPair->second->OnTriggerExit(*trigger);

				triggersEnteredPair.erase(triggeredPair);
			}
		}
	}

	void PhysicsSystem::SubscribeColider(ColliderComponent* collider)
	{
		std::cout << "Subscribe colider" << collider << std::endl;
		colliders.push_back(collider);
	}
	void PhysicsSystem::UnsubscribeColider(ColliderComponent* collider)
	{
		std::cout << "Unsubscribe colider" << collider << std::endl;
		colliders.erase(std::remove_if(colliders.begin(), colliders.end(), [collider](ColliderComponent* obj) { return obj == collider; }), colliders.end());
	}

}