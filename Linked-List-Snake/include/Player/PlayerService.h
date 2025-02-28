#pragma once
namespace Player {
	class SnakeController;
	class PlayerService {
	private:
		SnakeController* snake;
	public:
		PlayerService();
		void Intialize();
		void Update();
		void Render();
		void SpawnPlayer();
		~PlayerService();
	};
}