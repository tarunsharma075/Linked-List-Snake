#include"Player/SnakeController.h"
#include"Global/ServiceLocator.h"
#include"Event/EventService.h"
#include<iostream>
#include"Time/TimeService.h"
#include"Sound/SoundService.h"
#include"ELement/ElementService.h"
#include"Food/FoodType.h"
#include"LinkedListLibrary/SingleLinkedList/SingleLinkedList.h"
#include"LinkedListLibrary/DoubleLinkedList/DoubleLinkedList.h"

using namespace LinkedListLib;
using namespace Sound;
using namespace Global;
using namespace Event;
using namespace LinkedListLib;
using namespace Time;
using namespace Element;
using namespace Food;
namespace Player {
	SnakeController::SnakeController()
	{
		
		snake = nullptr;
		currentSnakeDirection = defaultDirection;
		
		
	}
	void Player::SnakeController::Intialize()
	{
		
		
		
	}
	void SnakeController::Update()
	{
		switch (currentsnakeSate) {
		case SnakeState::ALIVE:
			ProcessPlayerInput();
			DelayedMovement();
			currenInputState = InputState::Waiting;
			break;
		case SnakeState::DEAD:
			handelReset();
			break;
		}
	}
	void SnakeController::Render()
	{
		snake->render();
	}
	void SnakeController::ProcessPlayerInput()
	{
		EventService* event = Global::ServiceLocator::getInstance()->getEventService();
		if (event->pressedUpArrowKey() && currentSnakeDirection != Direction::DOWN&&currenInputState== InputState::Waiting) {
			currenInputState = InputState::Processing;
			currentSnakeDirection = Direction::UP;
			
		}
		else if (event->pressedDownArrowKey() && currentSnakeDirection!= Direction::UP && currenInputState == InputState::Waiting) {
			currenInputState = InputState::Processing;
			currentSnakeDirection = Direction::DOWN;
		
		}
		else if (event->pressedLeftArrowKey() && currentSnakeDirection != Direction::RIGHT && currenInputState == InputState::Waiting) {
			currenInputState = InputState::Processing;
			currentSnakeDirection = Direction::LEFT;
			
		}
		else if (event->pressedRightArrowKey() && currentSnakeDirection != Direction::LEFT && currenInputState == InputState::Waiting) {
			currenInputState = InputState::Processing;
			currentSnakeDirection = Direction::RIGHT;
			
		}
	}
	void SnakeController::UpdateSnakeDirection()
	{
		snake->updateNodeDirection(currentSnakeDirection);
	}
	void SnakeController::SnakeMovement()
	{
		snake->updateNodePosition();
	
	}
	void SnakeController::HandelSnakeCollision()
	{
		SnakeBodyCollision();
		SnakeFoodCollision();
		SnakeElementCollision();
	}
	void SnakeController::handelReset()
	{
		resetelapsedtime += Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
		if (resetelapsedtime >= resetDuration) {
			ReSpwanSnake();
		}
	}
	void SnakeController::Reset()
	{
		currentsnakeSate = SnakeState::ALIVE;
		currentSnakeDirection = defaultDirection;
		ElapsedTime = 0.f;
		resetDuration = 0.f;
		currenInputState = InputState::Waiting;
		playerScore = 0;
		time_complexity = TimeComplexity::NONE;
		last_linked_list_operation = LinkedListOperation::NONE;
	}
	void SnakeController::SpawnSnake()
	{
		for (int i = 0; i < snakeLength; i++) {
			snake->insertNodeAtTail();
		}
	}
	void SnakeController::SetSnakeState(SnakeState state)
	{
		currentsnakeSate = state;
	}
	void SnakeController::ReSpwanSnake()
	{
		snake->removeAllNodes();
		Reset();
		SpawnSnake();
	}
	SnakeState SnakeController::GetSnakeState()
	{
		return currentsnakeSate;
	}
	void SnakeController::CreateLinkedList(Level::LinkedListType levelType)
	{
		switch (levelType) {

		case::LinkedListType::SingleLinkedList:
			snake = new SingleLinked::SingleLinkedList();
			break;
		case::LinkedListType::DoubleLinkedList:
			snake = new DoubleLinked::DoubleLinkedList();
			break;

		}
		intializeLinkedList();
	}
	void SnakeController::DelayedMovement()
	{
		ElapsedTime += Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
		if (ElapsedTime >= MovementDelay) {
			ElapsedTime = 0.0f;
			UpdateSnakeDirection();
			HandelSnakeCollision();
			if (currentsnakeSate == SnakeState::ALIVE) {
				SnakeMovement();
				currenInputState = InputState::Waiting;
			}
		}
	}
	std::vector<sf::Vector2i> SnakeController::GetSnakepsoition()
	{
		return snake->getNodesPositionList();
	}
	void SnakeController::SnakeBodyCollision()
	{
		if (snake->processNodeCollision()) {
			currentsnakeSate = SnakeState::DEAD;
			ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::DEATH);
		}
	}
	void SnakeController::SnakeElementCollision()
	{
		ElementService* elementService = Global::ServiceLocator::getInstance()->GetElementService();

		if (elementService->ProcessElementCollision(snake->getHeadNode())) {
			currentsnakeSate = SnakeState::DEAD;
			Global::ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::DEATH);
		}
	}
	void SnakeController::SnakeFoodCollision()
	{
		FoodService* foodService = ServiceLocator::getInstance()->GetFoodService();
		FoodType foodType;
		if (foodService->ProcessFoodCollision(snake->getHeadNode(), foodType)) {

			foodService->destroyfood();
			OnFoodCollision(foodType);
			playerScore++;
		}
	}
	void SnakeController::OnFoodCollision(Food::FoodType food)
	{
		switch (food)
		{
		case FoodType::PIZZA:
			//Insert at TAIL
			snake->insertNodeAtTail();
			time_complexity = TimeComplexity::N;
			last_linked_list_operation = LinkedListOperation::INSERT_AT_TAIL;
			break;

		case FoodType::BURGER:
			//Insert at HEAD
			snake->insertNodeAtHead();
			time_complexity = TimeComplexity::ONE;
			last_linked_list_operation = LinkedListOperation::INSERT_AT_HEAD;
			break;

		case FoodType::CHEESE:
			//Insert at MIDDLE
			snake->insertNodeAtMiddle();
			time_complexity = TimeComplexity::N;
			last_linked_list_operation = LinkedListOperation::INSERT_AT_MID;
			break;

		case FoodType::APPLE:
			//Delete at HEAD
			snake->removeNodeAtHead();
			time_complexity = TimeComplexity::ONE;
			last_linked_list_operation = LinkedListOperation::REMOVE_AT_HEAD;
			break;

		case FoodType::MANGO:
			//Delete at MIDDLE
			snake->removeNodeAtMiddle();
			time_complexity = TimeComplexity::N;
			last_linked_list_operation = LinkedListOperation::REMOVE_AT_MID;
			break;

		case FoodType::ORANGE:
			//Delete at TAIL
			snake->removeNodeAtTail();
			time_complexity = TimeComplexity::N;
			last_linked_list_operation = LinkedListOperation::REMOVE_AT_TAIL;
			break;

		case FoodType::POISION:
			//Delete half nodes
			snake->removeHalfNodes();
			time_complexity = TimeComplexity::N;
			last_linked_list_operation = LinkedListOperation::DELETE_HALF_LIST;
			break;
		case FoodType::ALCOHOL:
			//Reverse Direction
			currentSnakeDirection = snake->reverse();
			time_complexity = TimeComplexity::N;
			last_linked_list_operation = LinkedListOperation::REVERSE_LIST;
			break;
		}
	}
	int SnakeController::GetPlayerScore()
	{
		return playerScore;
	}
	LinkedListOperation SnakeController::GetLinkedListoperation()
	{
		return last_linked_list_operation;
	}
	TimeComplexity SnakeController::GetTimeComplexity()
	{
		return time_complexity;
	}
	void SnakeController::intializeLinkedList()
	{
		float Width = ServiceLocator::getInstance()->GetLevelServices()->GetCellWidth();
		float Height = ServiceLocator::getInstance()->GetLevelServices()->GetCellHeight();

		Reset();
		snake->initialize(Width, Height, defaultPosition, defaultDirection);
	}
	bool SnakeController::IsSnakeDead()
	{
		return currentsnakeSate ==SnakeState::DEAD;
	}
	SnakeController::~SnakeController()
	{
		
		delete(snake);
	}
}
