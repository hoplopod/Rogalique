#include "pch.h"
#include "FeaturesComponent.h"

namespace Engine {

	FeaturesComponent::FeaturesComponent(GameObject* gameObject) : Component(gameObject) {
	
		renderer = gameObject->GetComponent<SpriteRendererComponent>();
		if (renderer == nullptr)
		{
			std::cout << "Need renderer component for movement animation" << std::endl;
			gameObject->RemoveComponent(this);
		}

	}

	void FeaturesComponent::Update(float deltaTime) {
		/*if (GetHealth() == 0) {
			setDeath(true);
		}

		if (GetDeathStatus()) {
			renderer->SetTexture(*Engine::ResourceSystem::Instance()->GetTextureShared("mogila"));
			renderer->SetPixelSize(100, 100);

		}*/
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
		std::cout << "hit" << std::endl;

		if (armor == 0) {
			--health;
		}
		else --armor;
	}

}


