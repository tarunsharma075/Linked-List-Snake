#include"Player/SnakeController.h"
#include"Global/ServiceLocator.h"
#include"Event/EventService.h"
#include<iostream>
#include"Time/TimeService.h"
#include"Sound/SoundService.h"
#include"ELement/ElementService.h"
#include"Food/FoodType.h"
using namespace Sound;
using namespace Global;
using namespace Event;
using namespace LinekdList;
using namespace Time;
using namespace Element;
using namespace Food;
namespace Player {
	SnakeController::SnakeController()
	{
		
		snakeHead = nullptr;
		currentSnakeDirection = defaultDirection;
		
		CreateLinkedList();
	}
	void Player::SnakeController::Intialize()
	{
		float Width = ServiceLocator::getInstance()->GetLevelServices()->GetCellWidth();
		float Height = ServiceLocator::getInstance()->GetLevelServices()->GetCellHeight();
	
		Reset();
		snakeHead->Intialize(Width, Height, defaultPosition, defaultDirection);
		
		
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
		snakeHead->Render();
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
		snakeHead->UpdateSingleLinekdListDirection(currentSnakeDirection);
	}
	void SnakeController::SnakeMovement()
	{
		snakeHead->UpdateSingleLinkedListPosition();
	
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
			snakeHead->InsertNodeAtTail();
		}
	}
	void SnakeController::SetSnakeState(SnakeState state)
	{
		currentsnakeSate = state;
	}
	void SnakeController::ReSpwanSnake()
	{
		snakeHead->RemoveAllNodes();
		Reset();
		SpawnSnake();
	}
	SnakeState SnakeController::GetSnakeState()
	{
		return currentsnakeSate;
	}
	void SnakeController::CreateLinkedList()
	{
		snakeHead = new SingleLinkedList();
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
			}
		}
	}
	std::vector<sf::Vector2i> SnakeController::GetSnakepsoition()
	{
		return snakeHead->GetNodePosition();
	}
	void SnakeController::SnakeBodyCollision()
	{
		if (snakeHead->CheckNodeCollision()) {
			currentsnakeSate = SnakeState::DEAD;
			Global::ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::DEATH);
		}
	}
	void SnakeController::SnakeElementCollision()
	{
		ElementService* elementService = Global::ServiceLocator::getInstance()->GetElementService();

		if (elementService->ProcessElementCollision(snakeHead->GetHeadNode())) {
			currentsnakeSate = SnakeState::DEAD;
			Global::ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::DEATH);
		}
	}
	void SnakeController::SnakeFoodCollision()
	{
		FoodService* foodService = ServiceLocator::getInstance()->GetFoodService();
		FoodType foodType;
		if (foodService->ProcessFoodCollision(snakeHead->GetHeadNode(), foodType)) {

			foodService->destroyfood();
			OnFoodCollision(foodType);
			playerScore++;
		}
	}
	void SnakeController::OnFoodCollision(Food::FoodType food)
	{
		switch (food) {
		case FoodType::PIZZA:
			snakeHead->InsertNodeAtTail();
			time_complexity = TimeComplexity::ONE;
			last_linked_list_operation = LinkedListOperation::INSERT_AT_HEAD;
			break;

		case FoodType::BURGER:
			snakeHead->InsertNodeAtHead();
			time_complexity = TimeComplexity::ONE;
			last_linked_list_operation = LinkedListOperation::INSERT_AT_HEAD;
			break;

		case FoodType::CHEESE:
			snakeHead->InsertNodeInMiddle();
			time_complexity = TimeComplexity::N;
			last_linked_list_operation = LinkedListOperation::INSERT_AT_MID;
			break;

		case FoodType::APPLE:
			snakeHead->RemoveNodeAtHead();
			time_complexity = TimeComplexity::ONE;
			last_linked_list_operation = LinkedListOperation::REMOVE_AT_HEAD;
			break;

		case FoodType::MANGO:
			snakeHead->RemovePartAtMiddle();
			time_complexity = TimeComplexity::N;
			last_linked_list_operation = LinkedListOperation::REMOVE_AT_MID;
			break;

		case FoodType::ORANGE:
			snakeHead->RemoveNodeAttail();
			time_complexity = TimeComplexity::N;
			last_linked_list_operation = LinkedListOperation::REMOVE_AT_TAIL;
			break;

		case FoodType::POISION:
			snakeHead->RemoveHalfNode();
			time_complexity = TimeComplexity::N;
			last_linked_list_operation = LinkedListOperation::DELETE_HALF_LIST;
			break;

		case FoodType::ALCOHOL:
			currentSnakeDirection = snakeHead->ReverseLinkedList();
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
	SnakeController::~SnakeController()
	{
		snakeHead->RemoveNodeAtHead();
		delete(snakeHead);
	}
}
