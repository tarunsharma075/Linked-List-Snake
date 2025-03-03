#pragma once
#include<SFML/Graphics.hpp>
#include"Player/Direction.h"
#include"LinkedList/SingleLinkedList.h"
#include"Food/FoodType.h"
namespace Player {
	
	
	enum class InputState {

		Processing,
		Waiting,
	};
	
		enum class SnakeState
		{
			ALIVE,
			DEAD,
		};

		
	class SnakeController {
	private:
		const int snakeLength = 10;
		SnakeState currentsnakeSate= SnakeState::ALIVE;
		const sf::Vector2i defaultPosition = sf::Vector2i(25,13);
		InputState currenInputState;
	const Direction defaultDirection = Direction::RIGHT;
	float MovementDelay = 0.1f;
	float ElapsedTime;
	float resetDuration = 2, f;
	float resetelapsedtime;
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
		void DelayedMovement();
		std::vector<sf::Vector2i> GetSnakepsoition();
		void SnakeBodyCollision();
		void SnakeElementCollision();
		void SnakeFoodCollision();
		void OnFoodCollsion(Food::FoodType food);
		
		~SnakeController();
	};
}