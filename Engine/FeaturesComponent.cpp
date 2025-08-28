#include "pch.h"
#include "FeaturesComponent.h"

namespace Engine {

	FeaturesComponent::FeaturesComponent(GameObject* gameObject) : Component(gameObject) {
	
	}

	void FeaturesComponent::Update(float deltaTime) {

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

	void FeaturesComponent::changeAbilityToDamage(bool choice)
	{
		abilityToDamage = choice;
	}

	void FeaturesComponent::HitEntity()
	{
		if (armor == 0) {
			--health;
		}
		else --armor;
	}

}


