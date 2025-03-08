#pragma once
#include"../Level/LevelConfig.h"
namespace Level {
	class LevelController;
	class LevelService {
	private:
		; LevelController* levelController;
		LevelNumber current_level;
		LinkedListType currentLinkedListType;
	public:
		LevelService();
		void Initialize();
		void Update();
		void Render();
		void SpawPlayer();
		~LevelService();
		void createLevel(LinkedListType linkedlistType);
		float GetCellHeight();
		float GetCellWidth();
		void Spawnfood();
		void SpawnLevelElements(Level::LevelNumber leveltoload);
		LevelNumber GetCurrentLevel();
		void SetCurrentLevel(LevelNumber level);
	};
}