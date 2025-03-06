#include"Food/FoodService.h"
#include"Food/FoodItem.h"
#include"Global/ServiceLocator.h"
#include"Food/FoodType.h"
#include"Level/LevelModel.h"
namespace Food {
	Food::FoodService::FoodService() :randomEngine(randomDevice())
{
	currentFoodItem = nullptr;
}
void FoodService::Intialize()
{
	ElapsedTime = spawnDuration;
}
void FoodService::Update()
{
	if (CurrentStatus == FoodSpawningStatus::ACTIVE) {
		UpdateElapsedDuration();
		handelfoodSpawing();
	}
	if(currentFoodItem)
	currentFoodItem->Update();
}
void FoodService::Render()
{
	if(currentFoodItem)
	currentFoodItem->Render();
}
void FoodService::reset()
{
	ElapsedTime = 0.f;
}
void FoodService::StartSpwanFood()
{
	CurrentStatus == FoodSpawningStatus::ACTIVE;
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
	currentFoodItem = CreateFood(GetValidSpawnPoint(), GetRandomFood());
}

sf::Vector2i FoodService::GetRandomPosition()
{
	std::uniform_int_distribution<int>xDistribution(0, Level::LevelModel::number_of_columns - 1);
	std::uniform_int_distribution<int>yDistribution(0, Level::LevelModel::number_of_rows - 1);
	int xposition = xDistribution(randomEngine);
	int yPosition = yDistribution(randomEngine);
	return sf::Vector2i(xposition, yPosition);
}

bool FoodService::IsPositionValid(std::vector<sf::Vector2i> playerPosition, sf::Vector2i foodPsoition)
{
	for (int i = 0; i < playerPosition.size(); i++) {
		if (foodPsoition == playerPosition[i])
			return false;
	}
	return true;
}

sf::Vector2i FoodService::GetValidSpawnPoint()
{
	std::vector<sf::Vector2i> playerposition = Global::ServiceLocator::getInstance()->GetPlayerService()->GetSnakePsoition();
	std::vector<sf::Vector2i> elementPosition = Global::ServiceLocator::getInstance()->GetElementService()->GetElemetpsoitionList();
	sf::Vector2i spawnPosition;
	do spawnPosition = GetRandomPosition();
	while (!IsPositionValid(playerposition, spawnPosition) || !IsPositionValid(elementPosition, spawnPosition));
	return spawnPosition;
}

FoodType FoodService::GetRandomFood()
{
	std::uniform_int_distribution<int> foodDistribution(0, FoodItem::numberOfFoods-1);
	return static_cast<FoodType>(foodDistribution(randomEngine));
}

void FoodService::UpdateElapsedDuration()
{
	ElapsedTime += Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
}

void FoodService::handelfoodSpawing()
{
	if (ElapsedTime >= spawnDuration) {
		destroyfood();
		reset();
		spawnfood();
		
	}
}

void FoodService::StopSpawningFood()
{
	CurrentStatus = FoodSpawningStatus::IN_ACTIVE;
	destroyfood();
	reset();

}

void FoodService::destroyfood()
{
	if (currentFoodItem)delete(currentFoodItem);
	currentFoodItem = nullptr;
}

bool FoodService::ProcessFoodCollision(LinekdList::Node* headNode, Food::FoodType& food)
{
	if (currentFoodItem && currentFoodItem->GetPsoitionOfFood() == headNode->bodyPart.GetPosition()) {
		food = currentFoodItem->GetCurrentFoodType();
		return true;
	}
	return false;
}

FoodService::~FoodService()
{
	destroyfood();
}
}