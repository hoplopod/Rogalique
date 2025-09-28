#pragma once
#include <array>
#include "Component.h"
#include "GameObject.h"
#include "TimerComponent.h"
#include "Vector.h"
#include "GameWorld.h"
#include "Ai.h"

namespace Engine
{

class SpawnerComponent : public Component
{
  public:
	SpawnerComponent(GameObject *gameObject);

	void Update(float deltaTime) override;
	void Render() override;

	void spawnNewObject();
	void setSpawnSettings(float timeForSpawn, int width, int height);

  private:
	GameObject *timerObject;
	std::vector<std::unique_ptr<AI>> numObjects;

	float timer = 0.f;
	int width = 15;
	int height = 15;

	Vector2Di spawnBorders;
};

} // namespace Engine