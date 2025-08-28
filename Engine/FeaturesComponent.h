#pragma once

#include "Component.h"
#include "GameObject.h"

namespace Engine {

	class FeaturesComponent : public Component 
	{
	public:
		FeaturesComponent(GameObject* gameObject);

		void Update(float deltaTime) override;
		void Render() override;

		void setHealth(int newHealth);
		void setArmor(int newArmor);
		void changeAbilityToDamage(bool choice);

		void HitEntity();

	private:
		GameObject* gameObject = nullptr;

		bool abilityToDamage = false;

		int health = 0;
		int armor = 0;
	};

}


