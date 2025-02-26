#include"Player/SnakeController.h"
#include"Global/ServiceLocator.h"

using namespace Global;
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
			HandelSnakeCollision();
			UpdateSnakeDirection();
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
	}
	void SnakeController::UpdateSnakeDirection()
	{
	}
	void SnakeController::SnakeMovement()
	{
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
		snakeHead->CreateHeadNode();
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
