#pragma once
#include<vector>
#include"../../include/Level/LevelData.h"
namespace Level {
	class LevelModel {

	private:
		std::vector<Level::LevelData> levelConfiguration;
		float cellWidth;
		float cellHeight;
	public:
		static const int number_of_rows = 28;
		static const int number_of_columns = 50;
		LevelModel();
		void Intialize(int Width,int Height);
		void Update();
		void Render();
		int GetCellHeight();
		int GetCellWidth();
		~LevelModel();
	};
}