#pragma once

#include "Component.h"
#include "GameObject.h"

namespace Engine {

	class TimerComponent : public Component{
	public:
		TimerComponent(GameObject* gameObject);

		void Update(float deltaTime) {};
		void Render() {};

		void SetTimer(float newRecordedTime);
		bool checkTimer();
		bool GetTimerWork() const;
		
	private:
		sf::Clock clock;
		float currentTime = 0.f;
		float recordedTime = 0.f;
		float startTime = 0.f;
		bool timerWork = false;
	};

}
