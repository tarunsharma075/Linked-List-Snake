#pragma once
#include"Player/SnakeController.h"
#include<vector>
#include<SFML/System/Vector2.hpp>
namespace Player {

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
		int GetPlayerScore();
		TimeComplexity GetTimeComplexity();
		LinkedListOperation GetLinkedListOperation();
		~PlayerService();
	};
}