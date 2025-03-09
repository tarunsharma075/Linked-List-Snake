#pragma once

#include"LinkedListLibrary/Node.h"
#include"SFML/System/Vector2.hpp"
#include<vector>
namespace Element {
	class Obstacle;
	struct ElementData;
	class ElementService {
	private:
		std::vector<Obstacle*> obstaclelist;
	public:

		ElementService();
		void Intialize();
		void Render();
		void Update();
		void SpawnObstacle(sf::Vector2i pos, float width, float height);
		const void SpawnElements(std::vector<ElementData>& elementDataList, float width, float height);
		std::vector<sf::Vector2i> GetElemetpsoitionList();
		bool  ProcessElementCollision(LinkedListLib::Node* headNode);
		~ElementService();
	};
}