#pragma once
#include<vector>
#include<SFML/System/Vector2.hpp>
namespace Player {
	class SnakeController;
	class PlayerService {
	private:
		SnakeController* snake;
	public:
		PlayerService();
		void Intialize();
		void Update();
		void Render();
		void SpawnPlayer();
		std::vector<sf::Vector2i> GetSnakePsoition();
		~PlayerService();
	};
}