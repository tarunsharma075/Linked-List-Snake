#pragma once
#include"LinkedList/Node.h"
#include"Player/Direction.h"
namespace LinekdList {
	class  SingleLinkedList {
	private:
		Player::Node* headNode;
		float nodeWidth;
		float nodeHeight;
		sf::Vector2i gridPosition;
		Player::Direction SnakeDirection;
	Player::Node* CreateNode();

	public:
		SingleLinkedList();
		~SingleLinkedList();
		void Intialize(float width, float height, sf::Vector2i position, Player::Direction direction);
		void Render();
		
		sf::Vector2i GetNewNodePosition(Player::Node*referenceNode);
		void InsertNodeAtTail();
	};
}