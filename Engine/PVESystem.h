#pragma once

#include "Component.h"
#include "GameWorld.h"
#include "SpriteRendererComponent.h"
#include "ResourceSystem.h"
#include "SpriteMovementAnimationComponent.h"
#include "TransformComponent.h"
#include "TimerComponent.h"

namespace Engine {

	class PVEComponent : public Component 
	{
	public:

		PVEComponent(GameObject* gameObject);

		void Update(float deltaTime) override;
		void Render() override;

		void setHealth(int newHealth);
		void setArmor(int newArmor);
		void setDeath(bool newStatusOfDeth);
		void setCatchStatus(bool newCatchStatus);
		void changeAbilityToDamage(bool choice);

		int GetHealth() const;
		int GetArmor() const;
		bool GetDeathStatus() const;
		bool GetCatchStatus() const;

		void HitEntity();

	private:
		TransformComponent* transform;
		SpriteRendererComponent* renderer;
		TimerComponent* timer;

		bool abilityToDamage = false;
		bool DeathStatus = false;
		bool catchStatus = false;

		float damageTime = 2.5f;
		int health = 0;
		int armor = 0;
	};

	class PVESystem {
	public:
		static PVESystem* Instance();

		void SubscribePVE(PVEComponent* pveObject);
		void UnsubscribePVE(PVEComponent* pveObject);
		std::vector<PVEComponent*> GetSubscribePVE();

	private:
		std::vector<PVEComponent*> pveObjects;
	};

}


