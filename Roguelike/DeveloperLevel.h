#pragma once

#include <iostream>
#include <array>

#include "Scene.h"
#include "Player.h"
#include "Wall.h"
#include "Floor.h"
#include "Audio.h"
#include "Decor.h"
#include "Ai.h"
#include "PlayerItems.h"

using namespace Engine;

namespace Roguelike
{
	class DeveloperLevel : public Scene
	{
	public:
		void Start() override;
		void Restart() override;
		void Stop() override;

		std::vector<std::unique_ptr<Wall>> walls;
		std::vector<std::unique_ptr<Floor>> floors;

	private:
		std::unique_ptr<std::vector<AI>> ai;
		std::shared_ptr<Player> player;
		std::unique_ptr<Music> music;
		std::vector < std::unique_ptr<Sound>> sound;
		std::shared_ptr<Decor> decor;
		std::shared_ptr<PlayerItems> items;
	};
}