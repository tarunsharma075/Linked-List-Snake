#pragma once
#include<SFML/Graphics.hpp>
#include"Player/Direction.h"
#include"LinkedList/SingleLinkedList.h"
namespace Player {
	
	
	
		enum class SnakeState
		{
			ALIVE,
			DEAD,
		};

		
	class SnakeController {
	private:
		const int snakeLength = 100;
		SnakeState currentsnakeSate;
		const sf::Vector2i defaultPosition = sf::Vector2i(840,480);
	const Direction defaultDirection = Direction::RIGHT;
	Direction currentSnakeDirection;
LinekdList::SingleLinkedList* snakeHead;
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
		void CreateLinkedList();
		~SnakeController();
	};
}