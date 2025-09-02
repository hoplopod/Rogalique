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
			setDeath(true);
		}

		if (GetDeathStatus()) {
			auto deathComponent = Engine::GameWorld::Instance()->FindGameObject("mogila");
			deathComponent->GetComponent<TransformComponent>()->SetWorldPosition(transform->GetWorldPosition());
			renderer->SetRenderCondition(false);
		}
		else {
			if (catchStatus) {
				if (!timer->GetTimerWork()) timer->SetTimer(damageTime);
				else if (timer->checkTimer()) HitEntity();
			}
			else renderer->SetRenderCondition(true);
		}
		
	}

	void PVEComponent::Render() {}

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
		DeathStatus = newStatusOfDeth;
	}

	void PVEComponent::setCatchStatus(bool newCatchStatus)
	{
		catchStatus = newCatchStatus;
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
		return catchStatus;
	}

	void PVEComponent::HitEntity()
	{
		LOG_INFO("Hit "+ gameObject->GetName() + ", new hp:" + std::to_string(GetHealth()));

		if (armor == 0) {
			--health;
		}
		else --armor;
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


