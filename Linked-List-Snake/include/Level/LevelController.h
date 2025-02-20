#pragma once
namespace Level {
	class LevelView;
	class LevelModel;
	class LevelController
	{
	
	private:
	
	public:
		LevelController();
		void Intialize();
		void Update();
		void Render();
		LevelView* levelView;
		LevelModel* levelModel;
		float GetGridHeight();
		float GetGridWidth();
		int GetCellHeight();
		int GetCellWidth();
		~LevelController();
	};
}