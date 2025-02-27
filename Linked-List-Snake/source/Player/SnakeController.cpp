#include"Player/SnakeController.h"
#include"Global/ServiceLocator.h"
#include"Event/EventService.h"

using namespace Global;
using namespace Event;
using namespace LinekdList;
namespace Player {
	SnakeController::SnakeController()
	{
		snakeHead = nullptr;
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
		if (currentsnakeSate == SnakeState::ALIVE) {
			ProcessPlayerInput();
			UpdateSnakeDirection();
			HandelSnakeCollision();
			SnakeMovement();
		


		}
		else if (currentsnakeSate == SnakeState::DEAD) {
			handelReset();
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
	}
	void SnakeController::handelReset()
	{
	}
	void SnakeController::Reset()
	{
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
	}
	SnakeState SnakeController::GetSnakeState()
	{
		return currentsnakeSate;
	}
	void SnakeController::CreateLinkedList()
	{
		snakeHead = new SingleLinkedList();
	}
	SnakeController::~SnakeController()
	{
	}
}
