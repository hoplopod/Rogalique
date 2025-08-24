#pragma once

#include <iostream>
#include <array>

#include "Scene.h"
#include "Player.h"
#include "Wall.h"
#include "Floor.h"
#include "Music.h"

using namespace Engine;

namespace Roguelike
{
	class DeveloperLevel : public Scene
	{
	public:
		void Start() override;
		void Restart() override;
		void Stop() override;
	private:
		std::shared_ptr<Player> player;
		std::unique_ptr<Music> music;

		std::vector<std::unique_ptr<Wall>> walls;
		std::vector<std::unique_ptr<Floor>> floors;
	};
}