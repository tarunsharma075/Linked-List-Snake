#pragma once
#include"SFML/System/Vector2.hpp"
#include<random>
namespace Food {
	class FoodItem;
	enum class FoodType;
	class FoodService {

	private:
		Food::FoodItem* currentFoodItem;
		float width;
		float height;
		std::default_random_engine randomEngine;
		std::random_device randomDevice;

	public:
		FoodService();
		void Intialize();
		void Update();
		void Render();
		void StartSpwanFood();
		FoodItem* CreateFood(sf::Vector2i position, FoodType type);
		void spawnfood();
		sf::Vector2i GetRandomPosition();
		bool IsPositionValid(std::vector<sf::Vector2i>  playerPosition, sf::Vector2i fooPsoition);
		sf::Vector2i GetValidSpawnPoint();
		FoodType GetRandomFood();
		~FoodService();
	};
}