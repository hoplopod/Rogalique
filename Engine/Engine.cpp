#include "pch.h"
#include "Engine.h"
#include <iostream>

Engine::Engine() {}

void Engine::Initialaze()
{
	std::cout << "Движок инцилизирован." << std::endl;
}

void Engine::Run() {
	std::cout << "Движок запущен." << std::endl;
}
