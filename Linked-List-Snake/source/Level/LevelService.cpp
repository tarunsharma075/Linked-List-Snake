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
		SpawPlayer();
	}
}
