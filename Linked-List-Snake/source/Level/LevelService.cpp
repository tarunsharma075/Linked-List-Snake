#include "../../include/Level/LevelService.h"
#include"../../include/Level/LevelController.h"
#include"Global/ServiceLocator.h"
using namespace Global;
namespace Level {
	Level::LevelService::LevelService()
	{
		levelController = new LevelController();
	}
	void LevelService::Initialize()
	{
		levelController->Intialize();
	}
	void LevelService::Update()
	{
		levelController->Update();
	}
	void LevelService::Render()
	{
		levelController->Render();
	}
	void LevelService::SpawPlayer()
	{
		ServiceLocator::getInstance()->GetPlayerService()->SpawnPlayer();
	}
	LevelService::~LevelService()
	{
		delete(levelController);
	}
	void LevelService::createLevel(LevelNumber level_to_load)
	{
		current_level = level_to_load;
		SpawnLevelElements(level_to_load);
		SpawPlayer();
	}
	float LevelService::GetCellHeight()
	{
		return levelController->GetCellHeight();
	}
	float LevelService::GetCellWidth()
	{
		return levelController->GetCellWidth();
	}
	void LevelService::SpawnLevelElements(Level::LevelNumber leveltoload)
	{
		float Width = levelController->GetCellWidth();
		float height = levelController->GetCellHeight();

		std::vector<Element::ElementData>elementList = levelController->GetElementDataList((int)leveltoload);
		ServiceLocator::getInstance()->GetElementService()->SpawnElements(elementList, Width, height);
	}
}
