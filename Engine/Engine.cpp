#include "pch.h"
#include "Engine.h"
#include <iostream>

namespace Engine {

	Engine::Engine() {}

	void Engine::Initialaze()
	{
		std::cout << "������ �������������." << std::endl;
	}

	void Engine::Run() {
		std::cout << "������ �������." << std::endl;
	}

}