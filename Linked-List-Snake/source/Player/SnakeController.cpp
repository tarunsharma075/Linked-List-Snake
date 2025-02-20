#include"Player/SnakeController.h"
namespace Player {
	SnakeController::SnakeController()
	{
	}
	void Player::SnakeController::Intialize()
	{
		Reset();
	}
	void SnakeController::Update()
	{
		if (currentsnakeSate == SnakeState::ALIVE) {
			ProcessPlayerInput();
			HandelSnakeCollision();
			UpdateSnakeDirection();
			SnakeMovement();


		}
	}
	void SnakeController::Render()
	{
		
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
	SnakeController::~SnakeController()
	{
	}
}
