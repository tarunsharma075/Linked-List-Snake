#pragma once
#include<SFML/Graphics.hpp>
#include"Player/Direction.h"
namespace Player {
	
		enum class SnakeState
		{
			ALIVE,
			DEAD,
		};

		
	class SnakeController {
	private:
		const int snakeLength = 10;
		SnakeState currentsnakeSate;
		const sf::Vector2i defaultPosition = sf::Vector2i(25, 13);
	const Direction defaultDirection = Direction::RIGHT;
	Direction currentSnakeDirection;
	public:
		SnakeController();
		void Intialize();
		void Update();
		void Render();
		void ProcessPlayerInput();
		void UpdateSnakeDirection();
		void SnakeMovement();
		void HandelSnakeCollision();
		void handelReset();
		void Reset();
		void SpawnSnake();
		void SetSnakeState(SnakeState state);
		void ReSpwanSnake();
		SnakeState GetSnakeState();
		~SnakeController();
	};
}