#include "pch.h"
#include "FeaturesComponent.h"

namespace Engine {

	FeaturesComponent::FeaturesComponent(GameObject* gameObject) : Component(gameObject) {
		
		transform = gameObject->GetComponent<TransformComponent>();
		renderer = gameObject->GetComponent<SpriteRendererComponent>();
	}

	void FeaturesComponent::Update(float deltaTime) {
		if (GetHealth() == 0) {
			setDeath(true);
		}

		if (GetDeathStatus()) {
			auto deathComponent = Engine::GameWorld::Instance()->FindGameObject("mogila");
			deathComponent->GetComponent<TransformComponent>()->SetWorldPosition(transform->GetWorldPosition());
			renderer->SetRenderCondition(false);
		}
	}

	void FeaturesComponent::Render() {}

	void FeaturesComponent::setHealth(int newHealth)
	{
		health = newHealth;
	}

	void FeaturesComponent::setArmor(int newArmor)
	{
		armor = newArmor;
	}

	void FeaturesComponent::setDeath(bool newStatusOfDeth)
	{
		DeathStatus = newStatusOfDeth;
	}

	void FeaturesComponent::changeAbilityToDamage(bool choice)
	{
		abilityToDamage = choice;
	}

	int FeaturesComponent::GetHealth() const
	{
		return health;
	}

	int FeaturesComponent::GetArmor() const
	{
		return armor;
	}

	bool FeaturesComponent::GetDeathStatus() const
	{
		return DeathStatus;
	}

	void FeaturesComponent::HitEntity()
	{
		LOG_INFO("Hit palyer, new hp:" + std::to_string(GetHealth()));

		if (armor == 0) {
			--health;
		}
		else --armor;
	}

}


