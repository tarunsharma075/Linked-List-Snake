#pragma once
#include"UI/UIElement/ImageView.h"
#include<string>
#include"SFML/Graphics.hpp"
namespace Food {
	enum class FoodType;
	class FoodItem{
	private:
		UI::UIElement::ImageView* foodImage;
		sf::Vector2i gridPosition;
		float foodWidth;
		float foodHeight;
		FoodType foodType;
	public:
		FoodItem();
		static const int numberOfFoods = 8;
		void Intialize(float width,float height,FoodType Type,sf::Vector2i pos);
		void Render();
		void Update();
		sf::String GetFoodTexturePath();
		sf::Vector2f GetFoodPosition();
		void IntializeFoodImage();
		~FoodItem();
	};
}