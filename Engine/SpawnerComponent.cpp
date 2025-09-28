#include "pch.h"
#include "SpawnerComponent.h"

namespace Engine
{

SpawnerComponent::SpawnerComponent(GameObject* gameObject) : Component(gameObject)
{
	timerObject = gameObject;
}

void SpawnerComponent::Update(float deltaTime)
{
	if (!timerObject->GetComponent<TimerComponent>()->GetTimerWork())
	{
		timerObject->GetComponent<TimerComponent>()->SetTimer(timer);
	}
	else
	{
		if (timerObject->GetComponent<TimerComponent>()->checkTimer())
		{
			spawnNewObject();
		}
	}
}

void SpawnerComponent::Render()
{
}

void SpawnerComponent::spawnNewObject()
{
	numObjects.push_back(std::make_unique<AI>(std::forward<Engine::Vector2Df>({width/ 3 * 128.f, height/ 3 * 128.f}), timerObject, "ai " + std::to_string(numObjects.size() + 1)));
}

void SpawnerComponent::setSpawnSettings(float timeForSpawn, int width, int height)
{
	timer = timeForSpawn;
	spawnBorders = {width, height};
}

} // namespace Roguelike