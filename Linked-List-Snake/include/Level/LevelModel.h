#pragma once
#include<vector>
#include"../../include/Level/LevelData.h"
namespace Level {
	class LevelModel {

	private:
		std::vector<Level::LevelData> levelConfiguration;
		float cellWidth;
		float cellHeight;
		std::vector<Element::ElementData>level_one_list;
		std::vector<Element::ElementData>level_two_list;
	public:
		static const int number_of_rows = 29;
		static const int number_of_columns = 51;
		LevelModel();
		void Intialize(int Width,int Height);
		void Update();
		void Render();
		int GetCellHeight();
		int GetCellWidth();
		const std::vector<Element::ElementData>& GetElementDataList(int leveltoload);
		void IntializeLevelData();
		~LevelModel();
	};
}