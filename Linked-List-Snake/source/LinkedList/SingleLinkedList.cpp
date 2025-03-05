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
	
	sf::Vector2i SingleLinkedList::GetNewNodePosition(Node* referenceNode, Operation operation)
	{
	;
	switch (operation)
	{
	case LinekdList::Operation::HEAD:
		return referenceNode->bodyPart.GetNextPosition();
	case LinekdList::Operation::TAIL:
		return referenceNode->bodyPart.GetNextPosition();
	}
	
	return gridPosition;
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
		sf::Vector2i predictedPosition = headNode->bodyPart.GetNextPosition(); // Corrected

		Node* currentNode = headNode->next;
		while (currentNode != nullptr) {
			if (currentNode->bodyPart.GetPosition() == predictedPosition) { // Corrected
				std::cout << "collision detected" << std::endl;
				return true;
			}
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
			return;
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

		int middleIndex=0;

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

	void SingleLinkedList::ShitNodesAfterRemoval(Node* currentNode)
	{
		sf::Vector2i previousNodePosition = currentNode->bodyPart.GetPosition();
		Direction previousNodeDirection = currentNode->bodyPart.GetDirection();
		currentNode = currentNode->next;
		while(currentNode!=nullptr){

			sf::Vector2i tempPosition = currentNode->bodyPart.GetPosition();
			Direction tempDirection = currentNode->bodyPart.GetDirection();

			currentNode->bodyPart.SetPosition(previousNodePosition);
			currentNode->bodyPart.SetDirection(previousNodeDirection);

			currentNode = currentNode->next;
			previousNodePosition = tempPosition;
			previousNodeDirection = tempDirection;


	}
	}

	void SingleLinkedList::RemoveNodeAt(int index)
	{
		if (index<0 || index>=linkedListSize) return;

		if (index == 0) {
			RemoveAllHead();
			return;
		}

		RemoveNodeAtInedx(index);
	}

	void SingleLinkedList::RemoveNodeAtInedx(int Index)
	{
		Node* currentNode = headNode;
		Node* prevNode = nullptr;
		int currentIndex = 0;

		while (currentNode != nullptr && currentIndex < Index) {

			prevNode = currentNode;
			currentNode = currentNode->next;
			currentIndex++;
		}
		prevNode->next = currentNode->next;
		ShitNodesAfterRemoval(currentNode);
		delete(currentNode);
		linkedListSize--;
	}

	void SingleLinkedList::RemovePartAtMiddle()
	{
		if (headNode == nullptr)return;
		int midIndex = FindTheMiddleIndex();
		RemoveNodeAt(midIndex);
	}

	void SingleLinkedList::RemoveNodeAttail()
	{
		if (headNode == nullptr)return;

		Node* currentNode;
		currentNode = headNode;
		if (currentNode->next == nullptr) {
			RemoveAllHead();
			return;
		}
		while (currentNode->next->next != nullptr) {
			currentNode = currentNode->next;
		}
		delete(currentNode->next);
		currentNode->next = nullptr;
	}

	Node* SingleLinkedList::FindNodeAtIndex(int index)
	{
		Node* currentNode = headNode;
		Node* prevNode = nullptr;
		int currentIndex = 0;
		
		
		while (currentNode != nullptr && currentIndex <= index) {
			prevNode = currentNode;
			currentNode = currentNode->next;
			currentIndex++;
		}
		return prevNode;
	}

	void SingleLinkedList::RemoveHalfNode()
	{
		if (linkedListSize <= 0)return;
		int halfLength = linkedListSize / 2;
		int newTailIndex = halfLength - 1;

		Node* prevNode = FindNodeAtIndex(newTailIndex);
		Node* currentNode = prevNode->next;
		while (currentNode != nullptr) {
			Node* nodeToDelete = currentNode;
			currentNode = currentNode->next;
			delete(nodeToDelete);
			linkedListSize--;
		}
		prevNode->next= nullptr;

	}

	Direction SingleLinkedList::ReverseLinkedList()
	{
		if (headNode == nullptr || headNode->next == nullptr) return SnakeDirection; 

		Node* currentNode = headNode;
		Node* prevNode = nullptr;
		Node* nextNode = nullptr;

		while (currentNode != nullptr) {
			
			nextNode = currentNode->next;
			currentNode->next = prevNode;
			prevNode = currentNode;
			currentNode = nextNode;

		}
		headNode = prevNode;
		return headNode->bodyPart.GetDirection();
	}

	Direction SingleLinkedList::GetReverseDirection(Direction ReferenceDirection)
	{
		switch (ReferenceDirection)
		{
		case Player::Direction::UP:
			return Direction::DOWN;
		case Player::Direction::DOWN:
			return Direction::UP;
		case Player::Direction::LEFT:
			return Direction::RIGHT;
		case Player::Direction::RIGHT:
			return Direction::LEFT;
		
		}
	}

	void SingleLinkedList::ReverseNodeDirection()
	{
		Node* currentNode = headNode;
		while (currentNode != nullptr) {
			currentNode->bodyPart.SetDirection(currentNode->bodyPart.GetPreviousDirection());
		}
	}
	
	
}
