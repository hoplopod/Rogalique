#include "pch.h"
#include "TimerComponent.h"

namespace Engine {

	TimerComponent::TimerComponent(GameObject* gameObject) : Component(gameObject)
	{
	}

	void TimerComponent::SetTimer(float newRecordedTime)
	{
		clock.restart();
		startTime = clock.getElapsedTime().asSeconds();
		recordedTime = newRecordedTime;
		timerWork = true;
		LOG_INFO("Start timer, at the moment: " + std::to_string(startTime) + ", for a time: " + std::to_string(recordedTime));
	}

	bool TimerComponent::checkTimer()
	{
		currentTime = clock.getElapsedTime().asSeconds();
		if (abs(startTime - currentTime) > recordedTime) {
			LOG_INFO("Timer end at the moment: " + std::to_string(currentTime));
			timerWork = false;
			return true;
		}
		else return false;
	}

	bool TimerComponent::GetTimerWork() const
	{
		return timerWork;
	}

}