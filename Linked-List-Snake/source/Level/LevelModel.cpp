#include "../../include/Level/LevelModel.h"
namespace Level {
	Level::LevelModel::LevelModel()
	{
	}
	void LevelModel::Intialize(int Width, int Height)
	{
		cellWidth = Width / number_of_columns;
		cellHeight = Height / number_of_rows;
	}
	void LevelModel::Update()
	{
	}
	void LevelModel::Render()
	{
	}
	int LevelModel::GetCellHeight()
	{
		return cellHeight;
	}
	int LevelModel::GetCellWidth()
	{
		return cellWidth;
	}
	LevelModel::~LevelModel()
	{
	}
}
