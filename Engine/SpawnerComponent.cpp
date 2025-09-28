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
	width = random(100, 1300);
	height = random(100, 1300);
	numObjects.push_back(std::make_unique<AI>(std::forward<Engine::Vector2Df>({float(width), float(height)}), timerObject, "ai " + std::to_string(numObjects.size())));
	LOG_INFO("Spawn ai " + std::to_string(numObjects.size()) + " coordinats: " + std::to_string(width) + " " + std::to_string(height));
}

void SpawnerComponent::setSpawnSettings(float timeForSpawn, int width, int height)
{
	timer = timeForSpawn;
	spawnBorders = {width, height};
}

} // namespace Roguelike