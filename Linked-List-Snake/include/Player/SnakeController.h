#pragma once
#include<SFML/Graphics.hpp>
#include"Player/Direction.h"
#include"LinkedListLibrary/Node.h"
#include"LinkedListLibrary/LinkedList.h"
#include"Food/FoodType.h"
#include"Level/LevelConfig.h"
namespace Player {
	
	

	enum class TimeComplexity {

		NONE,
		ONE,
		N,
	};



	enum class InputState {

		Processing,
		Waiting,
	};
	
		enum class SnakeState
		{
			ALIVE,
			DEAD,
		};

		enum class LinkedListOperation{

			NONE,
			INSERT_AT_HEAD,
			INSERT_AT_TAIL,
			INSERT_AT_MID,
			REMOVE_AT_HEAD,
			REMOVE_AT_TAIL,
			REMOVE_AT_MID,
			DELETE_HALF_LIST,
			REVERSE_LIST,


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
	TimeComplexity time_complexity;
	LinkedListOperation last_linked_list_operation;
	LinkedListLib::LinkedList* snake;
int playerScore = 0;
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
		void CreateLinkedList(Level::LinkedListType levelType);
		void DelayedMovement();
		std::vector<sf::Vector2i> GetSnakepsoition();
		void SnakeBodyCollision();
		void SnakeElementCollision();
		void SnakeFoodCollision();
		void OnFoodCollision(Food::FoodType food);
		int GetPlayerScore();
		LinkedListOperation GetLinkedListoperation();
		TimeComplexity GetTimeComplexity();
		void intializeLinkedList();
		~SnakeController();
	};
}