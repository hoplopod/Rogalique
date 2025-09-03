
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Engine.h"
#include "ResourceSystem.h"
#include "DeveloperLevel.h"
#include "Matrix2D.h"

using namespace Roguelike;

int main()
{
	Engine::RenderSystem::Instance()->SetMainWindow(new sf::RenderWindow(sf::VideoMode(1280, 720), "SUSRoguelike"));

	ResourceSystem::Instance()->LoadTextureMap("player", "Resources/TextureMaps/Player.png", { 48, 63 }, 4, false);
	ResourceSystem::Instance()->LoadTextureMap("ai", "Resources/TextureMaps/Enemy.png", { 63, 63 }, 5, false);
	ResourceSystem::Instance()->LoadTextureMap("level_floors", "Resources/TextureMaps/Floor.png", { 16, 16 }, 49, false);
	ResourceSystem::Instance()->LoadTextureMap("level_walls", "Resources/TextureMaps/Wall.png", { 16, 16 }, 48, false);
	ResourceSystem::Instance()->LoadTextureMap("mogila", "Resources/Textures/Mogila.png", {100, 100}, 1, false);
	ResourceSystem::Instance()->LoadTextureMap("arm1", "Resources/Textures/arm1.png", {100, 100}, 1, false);
	ResourceSystem::Instance()->LoadTextureMap("arm1(2)", "Resources/Textures/arm1(2).png", {100, 100}, 1, false);

	ResourceSystem::Instance()->LoadSound("music", "Resources/Sounds/music1.wav");
	ResourceSystem::Instance()->LoadSound("damageSound", "Resources/Sounds/damageSound.wav");

	auto developerLevel = std::make_shared<DeveloperLevel>();
	developerLevel->Start();

	Engine::GameEngine::Instance()->Run();

	return 0;
}
