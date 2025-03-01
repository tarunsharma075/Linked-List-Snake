#include"Food/FoodItem.h"
#include"Food/FoodType.h"
#include"Global/Config.h"
#include"Level/LevelView.h"
namespace Food {
	FoodItem::FoodItem()
	{
		foodImage = new UI::UIElement::ImageView();
	}
	void Food::FoodItem::Intialize(float width, float height, FoodType Type, sf::Vector2i pos)
	{
		foodWidth = width;
		foodHeight = height;
		foodType = Type;
		gridPosition = pos;
		IntializeFoodImage();
	}
	void FoodItem::Render()
	{
		foodImage->render();
	}
	void FoodItem::Update()
	{
		foodImage->update();
	}
	sf::String FoodItem::GetFoodTexturePath()
	{
		switch (foodType)
		{
		case Food::FoodType::APPLE:
			return Global::Config::apple_texture_path;
			
		case Food::FoodType::MANGO:
			return Global::Config::mango_texture_path;
		
			
			
			case Food::FoodType::ORANGE:
				return Global::Config::orange_texture_path;


			case Food::FoodType::PIZZA:
				return Global::Config::pizza_texture_path;
			case Food::FoodType::BURGER:
				return Global::Config::burger_texture_path;
			case Food::FoodType::CHEESE:
				return Global::Config::cheese_texture_path;
			case Food::FoodType::POISION:
				return Global::Config::poision_texture_path;
			case Food::FoodType::ALCOHOL:
				return Global::Config::alcohol_texture_path;
	
		}
	}
	sf::Vector2f FoodItem::GetFoodPosition()
	{
		float xposition = Level::LevelView::borderOffSetLeft + (gridPosition.x * foodWidth) + (foodWidth / 2);
		float yposition = Level::LevelView::borderOffSetTop + (gridPosition.y * foodHeight) + (foodHeight / 2);

		return sf::Vector2f(xposition, yposition);
	}
	void FoodItem::IntializeFoodImage()
	{
		sf::Vector2f position = GetFoodPosition();
		sf::String foodTexture = GetFoodTexturePath();
		foodImage->initialize(foodTexture, foodWidth, foodHeight, position);
		foodImage->show();


	}
	FoodItem::~FoodItem()
	{
		delete(foodImage);
	}
}