#include"Food/FoodService.h"
#include"Food/FoodItem.h"
#include"Global/ServiceLocator.h"
#include"Food/FoodType.h"
namespace Food {
Food::FoodService::FoodService()
{
	currentFoodItem = nullptr;
}
void FoodService::Intialize()
{
	
}
void FoodService::Update()
{
	if(currentFoodItem)
	currentFoodItem->Update();
}
void FoodService::Render()
{
	if(currentFoodItem)
	currentFoodItem->Render();
}
void FoodService::StartSpwanFood()
{
	width = Global::ServiceLocator::getInstance()->GetLevelServices()->GetCellWidth();
	 height = Global::ServiceLocator::getInstance()->GetLevelServices()->GetCellHeight();
	spawnfood();
}

FoodItem* FoodService::CreateFood(sf::Vector2i position, FoodType type)
{
	FoodItem* food = new FoodItem();
	food->Intialize(width,height,type,position);
	return food;
}

void FoodService::spawnfood()
{
	currentFoodItem = CreateFood(sf::Vector2i(4, 6), FoodType::BURGER);
}

FoodService::~FoodService()
{
	delete(currentFoodItem);
}
}