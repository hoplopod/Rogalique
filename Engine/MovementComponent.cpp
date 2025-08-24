#include "pch.h"
#include "MovementComponent.h"

Engine::MovementComponent::MovementComponent(GameObject* gameObject)
	: Component(gameObject)
{
	input = gameObject->GetComponent<InputComponent>();
	transform = gameObject->GetComponent<TransformComponent>();

	if (input == nullptr)
	{
		std::cout << "Need input component for movement" << std::endl;
		gameObject->RemoveComponent(this);
	}
}

void Engine::MovementComponent::Update(float deltaTime)
{
	float xAxis = input->GetHorizontalAxis();
	float yAxis = input->GetVerticalAxis();

	transform->MoveBy(speed * deltaTime * Vector2Df{ xAxis, yAxis });

	acceleration = transform->GetWorldPosition() - previousPosition;
	previousPosition = transform->GetWorldPosition();
}

void Engine::MovementComponent::Render()
{
}

void Engine::MovementComponent::SetSpeed(float newSpeed)
{
	speed = newSpeed;
}

float Engine::MovementComponent::GetSpeed() const
{
	return speed;
}

float Engine::MovementComponent::GetAccelerationSquared() const
{
	return acceleration.x * acceleration.x + acceleration.y * acceleration.y;
}
