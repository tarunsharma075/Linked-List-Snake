#include "../../include/Level/LevelService.h"
#include"../../include/Level/LevelController.h"
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
	LevelService::~LevelService()
	{
		delete(levelController);
	}
	void LevelService::createLevel(LevelNumber level_to_load)
	{
		current_level = level_to_load;
	}
}
