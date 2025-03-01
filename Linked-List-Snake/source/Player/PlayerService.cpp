#include"Player/PlayerService.h"
#include"Player/SnakeController.h"
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
	PlayerService::~PlayerService()
	{
		delete(snake);
	}
}
