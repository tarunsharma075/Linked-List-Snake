#include"Player/PlayerService.h"

namespace Player {
	PlayerService::PlayerService()
	{
		snake = new SnakeController();
	}
	void Player::PlayerService::Intialize()
	{
		snake->Intialize();
	}
	void PlayerService::Update()
	{
		snake->Update();
	}
	void PlayerService::Render()
	{
		snake->Render();
	}
	void PlayerService::SpawnPlayer()
	{
		snake->SpawnSnake();
	}
	std::vector<sf::Vector2i> PlayerService::GetSnakePsoition()
	{
		return snake->GetSnakepsoition();
	}
	int PlayerService::GetPlayerScore()
	{
		return snake->GetPlayerScore();
	}
	TimeComplexity PlayerService::GetTimeComplexity()
	{
		return snake->GetTimeComplexity();
	}
	LinkedListOperation PlayerService::GetLinkedListOperation()
	{
		return snake->GetLinkedListoperation();
	}
	PlayerService::~PlayerService()
	{
		delete(snake);
	}
}
