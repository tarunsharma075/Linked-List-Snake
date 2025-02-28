#include "../../include/Level/LevelModel.h"
namespace Level {
	Level::LevelModel::LevelModel()
	{
	}
	void LevelModel::Intialize(int Width, int Height)
	{
		cellWidth = Width / number_of_columns;
		cellHeight = Height / number_of_rows;
		IntializeLevelData();
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
	const std::vector<Element::ElementData>& LevelModel::GetElementDataList(int leveltoload)
	{
		return*levelConfiguration[leveltoload].elementList;
	}
	void LevelModel::IntializeLevelData()
	{
		levelConfiguration.push_back(Level::LevelData(Level::LevelNumber::ONE, &level_one_list));
		levelConfiguration.push_back(Level::LevelData(Level::LevelNumber::TWO, &level_two_list));
	}
	LevelModel::~LevelModel()
	{
	}
}
