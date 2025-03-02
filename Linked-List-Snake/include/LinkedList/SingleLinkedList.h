#pragma once
#include"LinkedList/Node.h"
#include"Player/Direction.h"
#include<vector>
namespace LinekdList {
	class  SingleLinkedList {
	private:
		Node* headNode;
		float nodeWidth;
		float nodeHeight;
		sf::Vector2i gridPosition;
		Player::Direction SnakeDirection;
	 Node* CreateNode();

	public:
		SingleLinkedList();
		~SingleLinkedList();
		void Intialize(float width, float height, sf::Vector2i position, Player::Direction direction);
		void Render();
		
		sf::Vector2i GetNewNodePosition(Node*referenceNode);
		void InsertNodeAtTail();
		void UpdateSingleLinekdListDirection(Player::Direction directionToSet);
		void UpdateSingleLinkedListPosition();
		bool CheckNodeCollision();
		void RemoveAllHead();
		void RemoveAllNodes();
		Node* GetHeadNode();
		std::vector<sf::Vector2i>  GetNodePosition();
	};
}