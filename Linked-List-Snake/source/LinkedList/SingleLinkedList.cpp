#include"LinkedList/SingleLinkedList.h"
#include"Player/Direction.h"
#include<iostream>
using namespace Player;
namespace LinekdList {
	Node* SingleLinkedList::CreateNode()
	{
		return new Node;
	}
	LinekdList::SingleLinkedList::SingleLinkedList()
	{
		headNode = nullptr;

	}
	SingleLinkedList::~SingleLinkedList()
	{
	}
	void SingleLinkedList::Intialize(float width, float height, sf::Vector2i position, Player::Direction direction)
	{
		nodeWidth = width;
		nodeHeight = height;
		gridPosition = position;
		SnakeDirection = direction;
		CreateNode();
		linkedListSize = 0;
	}
	void SingleLinkedList::Render()
	{
		
		Node* currentNode = headNode;
		while (currentNode != nullptr) {
			currentNode->bodyPart.Render();
			currentNode = currentNode->next;
		}
	}
	
	sf::Vector2i SingleLinkedList::GetNewNodePosition(Node* referenceNode)
	{
		Direction directionReference = referenceNode->bodyPart.GetDirection();
		sf::Vector2i positionReference= referenceNode->bodyPart.GetPosition();

		switch (directionReference)
		{
		case Direction::UP:
			return sf::Vector2i(positionReference.x, positionReference.y - 1);
			break;
		case Direction::DOWN:
			return sf::Vector2i(positionReference.x, positionReference.y + 1);
			break;
		case Direction::LEFT:
			return sf::Vector2i(positionReference.x +1, positionReference.y);
			break;
		case Direction::RIGHT:
			return sf::Vector2i(positionReference.x -1, positionReference.y);
			break;
		default:
			return gridPosition;
			
		}
	}
	void SingleLinkedList::InsertNodeAtTail()
	{
		linkedListSize++;
		Node*newNode = CreateNode();
		Node* currentNode = headNode;

		if (currentNode == nullptr) {
			headNode = newNode;
			IntializeNewNode(newNode, nullptr, Operation::TAIL);
			return;
		}
		while (currentNode->next != nullptr) {
			currentNode = currentNode->next;
	}
		currentNode->next = newNode;
		IntializeNewNode(newNode, currentNode, Operation::TAIL);
		
	}

	void SingleLinkedList::UpdateSingleLinekdListDirection(Player::Direction directionToSet)
	{

		Node* currentNode = headNode;
		while (currentNode != nullptr) {

			Direction previousDirection = currentNode->bodyPart.GetDirection();
			currentNode->bodyPart.SetDirection(directionToSet);
			directionToSet = previousDirection;
			currentNode = currentNode->next;
		}
	}

	void SingleLinkedList::UpdateSingleLinkedListPosition()
	{
		

		Node* currenNode = headNode;

		while (currenNode != nullptr) {
			currenNode->bodyPart.UpdatePosition();
			currenNode = currenNode->next;
		}
	}

	bool SingleLinkedList::CheckNodeCollision()
	{
		if (headNode == nullptr)
			return false;
		sf::Vector2i predictedPsoition = headNode->bodyPart.GetPosition();

		Node* currentNode;
		currentNode = headNode->next;
		while (currentNode != nullptr) {
			if (currentNode->bodyPart.GetPosition() == headNode->bodyPart.GetPosition()) return true;
			std::cout << "collision detected" << std::endl;
			currentNode = currentNode->next;

		}
		return false;
	}

	void SingleLinkedList::RemoveAllHead()
	{
		linkedListSize--;
		Node* currentNode = headNode;
		headNode = headNode->next;
		currentNode->next = nullptr;
		delete(currentNode);
	}

	void SingleLinkedList::RemoveAllNodes()
	{
		if (headNode == nullptr)return;
		while (headNode != nullptr) {
			RemoveAllHead();
		}
	}

	Node* SingleLinkedList::GetHeadNode()
	{
		return headNode;
	}

	std::vector<sf::Vector2i> SingleLinkedList::GetNodePosition()
	{
		Node* currentNode;
		currentNode = headNode;
		std::vector<sf::Vector2i> nodePositionList;
		while (currentNode != nullptr) {
			nodePositionList.push_back(currentNode->bodyPart.GetPosition());
			currentNode = currentNode->next;
		}
		return nodePositionList;
	}

	sf::Vector2i SingleLinkedList::NewNodePosition(Node* referenceNode, Operation currentOperation)
	{
		switch (currentOperation) {
		case Operation::HEAD:
			return referenceNode->bodyPart.GetNextPosition();
		
		//case Operation::MIDDLE:
		//	//
		case Operation::TAIL:
			return referenceNode->bodyPart.GetPreviousPosition();
			
		}

		return gridPosition;
	}

	void  SingleLinkedList::IntializeNewNode(Node* newNode, Node* refrennceNode, Operation operation)
	{
		if (refrennceNode == nullptr) {
			newNode->bodyPart.Intialize(nodeWidth, nodeHeight, gridPosition, SnakeDirection);
			return;
		}
		sf::Vector2i position = NewNodePosition(refrennceNode, operation);
		newNode->bodyPart.Intialize(nodeWidth, nodeHeight, position, refrennceNode->bodyPart.GetDirection());
	}

	void SingleLinkedList::InsertNodeAtHead()
	{
		linkedListSize++;
		Node* newNOde = CreateNode();
		if (headNode == nullptr) {
			headNode = newNOde;
			IntializeNewNode(newNOde, nullptr, Operation::HEAD);
			return;
		}

		IntializeNewNode(newNOde, headNode, Operation::HEAD);
		newNOde->next = headNode;
		headNode = newNOde;
	}

	void SingleLinkedList::InsertAtIndex(int index)
	{
		Node* newNode;
		
		if (index < 0 || index >= linkedListSize)return;
		if (index == 0) {
			InsertNodeAtHead();
		}
		newNode = CreateNode();
		int currentIndex = 0;
		Node* currentnode = headNode;
		Node* prevNode = nullptr;
		while (currentnode != nullptr && currentIndex <index) {
			prevNode = currentnode;
			currentnode = currentnode->next;
			currentIndex++;
				
		}
		prevNode->next = newNode;
		newNode->next = currentnode;
		IntializeNewNode(newNode, currentnode, Operation::TAIL);
		linkedListSize++;
		ShiftNodesAfterInsertion(newNode, currentnode, prevNode);
	}

	void SingleLinkedList::ShiftNodesAfterInsertion(Node* newNode, Node* currentNode, Node* prevNode)
	{
		Node* nextNode = currentNode;
		currentNode = newNode;

		while (currentNode != nullptr && nextNode != nullptr) {
			currentNode->bodyPart.SetPosition(nextNode->bodyPart.GetPosition());
			currentNode->bodyPart.SetDirection(nextNode->bodyPart.GetDirection());
			prevNode = currentNode;
			currentNode = nextNode;
			nextNode = nextNode->next;
		}
		IntializeNewNode(currentNode, prevNode, Operation::TAIL);
	}

	int SingleLinkedList::FindTheMiddleIndex()
	{
		Node* slow = headNode;
		Node* fast = headNode;

		int middleIndex;

		while (fast != nullptr && fast->next != nullptr) {

			slow = slow->next;
			fast = fast->next->next;
			middleIndex++;
		}
		return middleIndex;
	}

	void SingleLinkedList::InsertNodeInMiddle()
	{
		if (headNode == nullptr) {
			InsertNodeAtHead();
			return;
		}

		int middleindex = FindTheMiddleIndex();
		InsertAtIndex(middleindex);
	}
	
}
