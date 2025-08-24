#include "pch.h"
#include "Component.h"
#include <iostream>

namespace Engine
{
	Component::Component(GameObject* gameObject) : gameObject(gameObject) {
		std::cout << "Add new component: " << this << std::endl;
	}
	Component::~Component()
	{
		std::cout << "Deleted component: " << this << std::endl;
	}
	GameObject* Component::GetGameObject()
	{
		return gameObject;
	}
}