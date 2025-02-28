#include"ELement/ElementService.h"
#include"Level/LevelModel.h"
#include"Global/ServiceLocator.h"
#include"ELement/Obstacle.h"
#include"ELement/ElementData.h"
namespace Element {
	ElementService::ElementService()
	{
	}
	void Element::ElementService::Intialize()
	{
	}
	void ElementService::Render()
	{
		for (int i = 0; i < obstaclelist.size(); i++)
		{
			obstaclelist[i]->Render();
		}
	}
	void ElementService::Update()
	{
		for (int i = 0; i < obstaclelist.size(); i++)
		{
			obstaclelist[i]->Update();
		}
	}
	void ElementService::SpawnObstacle(sf::Vector2i pos, float width, float height)
	{
		Obstacle* obstacle = new Obstacle();
		obstacle->Intialize(pos, width, height);
		obstaclelist.push_back(obstacle);
	}
	const void ElementService::SpawnElements(std::vector<ElementData>& elementDataList, float width, float height)
	{
		for (int i = 0; i < elementDataList.size(); i++) {
			switch (elementDataList[i].element) {
			case::Element::ElementType::Obstacle:
				SpawnObstacle(elementDataList[i].position, width, height);
				break;
			}
				
		}
	}
	ElementService::~ElementService()
	{
	}
}