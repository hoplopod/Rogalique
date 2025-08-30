#pragma once

#include "GameObject.h"

namespace Engine {

	class Decor
	{
	public:
		Decor(const Engine::Vector2Df& position);
		Engine::GameObject* GetGameObject();
	private:
		Engine::GameObject* gameObject;
	};

}
