#pragma once
#include"LinkedListLibrary/Node.h"
#include"Player/Direction.h"
#include<vector>
namespace LinekdList {
	enum class Operation {

		HEAD,
		MIDDLE,
		TAIL,
	};
	class  SingleLinkedList {
	private:
		Node* headNode;
		float nodeWidth;
		float nodeHeight;
		sf::Vector2i gridPosition;
		Player::Direction SnakeDirection;
		int linkedListSize;
	 Node* CreateNode();

	public:
		SingleLinkedList();
		~SingleLinkedList();
		void Intialize(float width, float height, sf::Vector2i position, Player::Direction direction);
		void Render();
		
		sf::Vector2i GetNewNodePosition(Node* referenceNode, Operation operation);
		void InsertNodeAtTail();
		void UpdateSingleLinekdListDirection(Player::Direction directionToSet);
		void UpdateSingleLinkedListPosition();
		bool CheckNodeCollision();
		void RemoveNodeAtHead();
		void RemoveAllNodes();
		Node* GetHeadNode();
		std::vector<sf::Vector2i>  GetNodePosition();
		sf::Vector2i NewNodePosition(Node* referenceNode, Operation currentOperation);
		 void IntializeNewNode(Node* newNode, Node* refrennceNode, Operation operation);
		 void InsertNodeAtHead();
		 void InsertAtIndex(int index);
		 void ShiftNodesAfterInsertion(Node* newNode, Node* currentNode, Node* prevNode);
		 int FindTheMiddleIndex();
		 void InsertNodeInMiddle();
		 void ShitNodesAfterRemoval(Node* currentNode);
		 void RemoveNodeAt(int index);
		 void RemoveNodeAtInedx(int Index);
		 void RemovePartAtMiddle();
		 void RemoveNodeAttail();
		 Node* FindNodeAtIndex(int index);
		 void RemoveHalfNode();
		 Direction ReverseLinkedList();
		 Direction GetReverseDirection(Direction ReferenceDirection);
		 void ReverseNodeDirection();
	};
}