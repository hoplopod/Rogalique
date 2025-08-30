#pragma once

#include "Component.h"
#include "GameWorld.h"
#include "SpriteRendererComponent.h"
#include "ResourceSystem.h"
#include "SpriteMovementAnimationComponent.h"
#include "TransformComponent.h"

namespace Engine {

	class FeaturesComponent : public Component 
	{
	public:
		FeaturesComponent(GameObject* gameObject);

		void Update(float deltaTime) override;
		void Render() override;

		void setHealth(int newHealth);
		void setArmor(int newArmor);
		void setDeath(bool newStatusOfDeth);
		void changeAbilityToDamage(bool choice);

		int GetHealth() const;
		int GetArmor() const;
		bool GetDeathStatus() const;

		void HitEntity();

	private:
		TransformComponent* transform;
		SpriteRendererComponent* renderer;

		bool abilityToDamage = false;
		bool DeathStatus = false;

		int health = 0;
		int armor = 0;
	};

}


