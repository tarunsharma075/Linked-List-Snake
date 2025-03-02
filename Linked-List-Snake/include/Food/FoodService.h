#pragma once
#include"SFML/System/Vector2.hpp"
#include<random>
namespace Food {
	enum FoodSpawningStatus
	{
		ACTIVE,
		IN_ACTIVE,
	};
	class FoodItem;
	enum class FoodType;
	class FoodService {

	private:
		Food::FoodItem* currentFoodItem;
		float width;
		float height;
		std::default_random_engine randomEngine;
		std::random_device randomDevice;
		const float spawnDuration = 4.f;
		float ElapsedTime;
		FoodSpawningStatus CurrentStatus;
	public:
		FoodService();
		void Intialize();
		void Update();
		void Render();
		void reset();
		void StartSpwanFood();
		FoodItem* CreateFood(sf::Vector2i position, FoodType type);
		void spawnfood();
		sf::Vector2i GetRandomPosition();
		bool IsPositionValid(std::vector<sf::Vector2i>  playerPosition, sf::Vector2i fooPsoition);
		sf::Vector2i GetValidSpawnPoint();
		FoodType GetRandomFood();
		void UpdateElapsedDuration();
		void handelfoodSpawing();
		void StopSpawningFood();
		void destroyfood();
		bool ProcessFoodCollision(LinekdList::Node*headNode,Food::FoodType& food);
		~FoodService();
	};
}