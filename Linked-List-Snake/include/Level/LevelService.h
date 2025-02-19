#pragma once
#include"../../include/Level/LevelNumber.h"
namespace Level {
	class LevelController;
	class LevelService {
	private:
		; LevelController* levelController;
		LevelNumber current_level;
	public:
		LevelService();
		void Initialize();
		void Update();
		void Render();
		~LevelService();
		void createLevel(LevelNumber level_to_load);
	};
}