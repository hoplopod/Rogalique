#include "pch.h"
#include "PVESystem.h"

namespace Engine {

	PVEComponent::PVEComponent(GameObject* gameObject) : Component(gameObject) {
		
		transform = gameObject->GetComponent<TransformComponent>();
		renderer = gameObject->GetComponent<SpriteRendererComponent>();
		timer = gameObject->GetComponent<TimerComponent>();
		PVESystem::Instance()->SubscribePVE(this);
	}

	void PVEComponent::Update(float deltaTime) {
		if (GetHealth() == 0) {
			if (transform->GetGameObject()->GetName() == "player") renderer->SetRenderCondition(false);
			setDeath(true);
		}

		switch (status)
		{
			
		case Engine::EnenmyStatus::statusCatch: {
			if (DeathStatus) break;
			if (!timer->GetTimerWork()) timer->SetTimer(damageTime);
			else if (timer->checkTimer()) HitEntity();
			break;
		}
			
		default: {
			break;
		}
			
		}
		
	}

	void PVEComponent::Render() {
		if (DeathStatus) renderer->SetTexture(*Engine::ResourceSystem::Instance()->GetTextureMapElementShared("mogila", 0));
	}

	void PVEComponent::setHealth(int newHealth)
	{
		health = newHealth;
	}

	void PVEComponent::setArmor(int newArmor)
	{
		armor = newArmor;
	}

	void PVEComponent::setDeath(bool newStatusOfDeth)
	{
		if (newStatusOfDeth) {
			Engine::GameWorld::Instance()->FindGameObject("Sound: death")->GetComponent<AudioComponent>()->Play();
			health = -1;
			DeathStatus = true;
		}
		else DeathStatus = false;

	}

	void PVEComponent::setCatchStatus(bool newCatchStatus)
	{
		if (newCatchStatus) {
			status = EnenmyStatus::statusCatch;
		}
		else status = EnenmyStatus::statusNothing;
	}

	void PVEComponent::changeAbilityToDamage(bool choice)
	{
		abilityToDamage = choice;
	}

	int PVEComponent::GetHealth() const
	{
		return health;
	}

	int PVEComponent::GetArmor() const
	{
		return armor;
	}

	bool PVEComponent::GetDeathStatus() const
	{
		return DeathStatus;
	}

	bool PVEComponent::GetCatchStatus() const
	{
		if (status == EnenmyStatus::statusCatch) return true;
		else return false;
	}

	void PVEComponent::HitEntity()
	{
		if (armor == 0) {
			--health;
		}
		else --armor;

		Engine::GameWorld::Instance()->FindGameObject("Sound: damageSound")->GetComponent<AudioComponent>()->Play();

		LOG_INFO("Hit "+ gameObject->GetName() + ", new hp:" + std::to_string(GetHealth()));
	}

	PVESystem* PVESystem::Instance()
	{
		static PVESystem PVESystem;
		return &PVESystem;
	}

	void PVESystem::SubscribePVE(PVEComponent* pveObject)
	{
		std::cout << "Subscribe pve" << pveObject << std::endl;
		pveObjects.push_back(pveObject);
	}
	void PVESystem::UnsubscribePVE(PVEComponent* pveObject)
	{
		std::cout << "Unsubscribe pve" << pveObject << std::endl;
		pveObjects.erase(std::remove_if(pveObjects.begin(), pveObjects.end(), [pveObject](PVEComponent* obj) { return obj == pveObject; }), pveObjects.end());
	}
	std::vector<PVEComponent*> PVESystem::GetSubscribePVE()
	{
		return pveObjects;
	}

}


