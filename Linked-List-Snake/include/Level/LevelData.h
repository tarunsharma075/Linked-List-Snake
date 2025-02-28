#pragma once
#include"../../include/Level/LevelService.h"
#include"ELement/ElementData.h"
namespace Level {

	struct LevelData {

		LevelData(LevelNumber ind, std::vector<Element::ElementData>*dataList) :level_index(ind),elementList(dataList) {} 
			LevelNumber level_index;
			std::vector<Element::ElementData>* elementList;
		
	};
}