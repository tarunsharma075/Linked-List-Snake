#pragma once
#include"SFML/System/Vector2.hpp"
namespace Food {
	class FoodItem;
	enum class FoodType;
	class FoodService {

	private:
		Food::FoodItem* currentFoodItem;
		float width;
		float height;

	public:
		FoodService();
		void Intialize();
		void Update();
		void Render();
		void StartSpwanFood();
		FoodItem* CreateFood(sf::Vector2i position, FoodType type);
		void spawnfood();
		~FoodService();
	};
}