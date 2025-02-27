#include"Player/SnakeController.h"
#include"Global/ServiceLocator.h"
#include"Event/EventService.h"
#include<iostream>
#include"Time/TimeService.h"
using namespace Global;
using namespace Event;
using namespace LinekdList;
using namespace Time;
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
		std::cout << defaultPosition.x << " "<<defaultPosition.y;
		
	}
	void SnakeController::Update()
	{
		switch (currentsnakeSate) {
		case SnakeState::ALIVE:
			ProcessPlayerInput();
			DelayedMovement();
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
		if (event->pressedUpArrowKey() && currentSnakeDirection != Direction::DOWN) {
			currentSnakeDirection = Direction::UP;
			
		}
		else if (event->pressedDownArrowKey() && currentSnakeDirection!= Direction::UP) {
			currentSnakeDirection = Direction::DOWN;
		}
		else if (event->pressedLeftArrowKey() && currentSnakeDirection != Direction::RIGHT) {
			currentSnakeDirection = Direction::LEFT;
		}
		else if (event->pressedRightArrowKey() && currentSnakeDirection != Direction::LEFT) {
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
		if (snakeHead->CheckNodeCollision()) {
			currentsnakeSate = SnakeState::DEAD;
		}
	}
	void SnakeController::handelReset()
	{
		resetelapsedtime += Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
		if (resetDuration >= resetDuration) {
			ReSpwanSnake();
		}
	}
	void SnakeController::Reset()
	{
		currentsnakeSate = SnakeState::ALIVE;
		currentSnakeDirection = defaultDirection;
		ElapsedTime = 0.f;
		resetDuration = 0.f;
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
	SnakeController::~SnakeController()
	{
	}
}
