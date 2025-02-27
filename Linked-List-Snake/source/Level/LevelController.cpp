#include "../../include/Level/LevelController.h"
#include"../../include/Level/LevelView.h"
#include"../../include/Level/LevelModel.h"
namespace Level {
	Level::LevelController::LevelController()
	{
		levelView = new LevelView();
		levelModel = new LevelModel();
	}
	void LevelController::Intialize()
	{
		levelView->Intialize();
		levelModel->Intialize(GetGridWidth(), GetGridHeight());
	}
	void LevelController::Update()
	{
		levelView->Update();
		levelModel->Update();
	}
	void LevelController::Render()
	{
		levelView->Render();
		levelModel->Render();
	}
	float LevelController::GetGridHeight()
	{
		return levelView->GetGridheight();
	}
	float LevelController::GetGridWidth()
	{
		return levelView->GetGridWidth();
	}
	int LevelController::GetCellHeight()
	{
		return levelModel->GetCellHeight();
	}
	int LevelController::GetCellWidth()
	{
		return levelModel->GetCellWidth();
	}
	LevelController::~LevelController()
	{
		delete(levelView);
		delete(levelModel);
	}
}
