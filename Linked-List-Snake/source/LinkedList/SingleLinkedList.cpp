#include"LinkedList/SingleLinkedList.h"
#include"Player/Direction.h"
#include<iostream>
using namespace Player;
namespace LinekdList {
	SingleNode* SingleLinkedList::CreateNode()
	{
		return new SingleNode;
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
		
		SingleNode* currentNode = headNode;
		while (currentNode != nullptr) {
			currentNode->bodyPart.Render();
			currentNode = currentNode->next;
		}
	}
	
	sf::Vector2i SingleLinkedList::GetNewNodePosition(SingleNode* referenceNode, Operation operation)
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
		SingleNode*newNode = CreateNode();
		SingleNode* currentNode = headNode;

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

		SingleNode* currentNode = headNode;
		while (currentNode != nullptr) {

			Direction previousDirection = currentNode->bodyPart.GetDirection();
			currentNode->bodyPart.SetDirection(directionToSet);
			directionToSet = previousDirection;
			currentNode = currentNode->next;
		}
	}

	void SingleLinkedList::UpdateSingleLinkedListPosition()
	{
		

		SingleNode* currenNode = headNode;

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

		SingleNode* currentNode = headNode->next;
		while (currentNode != nullptr) {
			if (currentNode->bodyPart.GetPosition() == predictedPosition) { // Corrected
				
				return true;
			}
			currentNode = currentNode->next;
		}
		return false;
	}

	void SingleLinkedList::RemoveNodeAtHead()
	{
		
		SingleNode* currentNode = headNode;
		headNode = headNode->next;
		currentNode->next = nullptr;
		delete(currentNode);
		linkedListSize--;
	}

	void SingleLinkedList::RemoveAllNodes()
	{
		if (headNode == nullptr)return;
		while (headNode != nullptr) {
			RemoveNodeAtHead();
		}

	}

	SingleNode* SingleLinkedList::GetHeadNode()
	{
		return headNode;
	}

	std::vector<sf::Vector2i> SingleLinkedList::GetNodePosition()
	{
		SingleNode* currentNode;
		currentNode = headNode;
		std::vector<sf::Vector2i> nodePositionList;
		while (currentNode != nullptr) {
			nodePositionList.push_back(currentNode->bodyPart.GetPosition());
			currentNode = currentNode->next;
		}
		return nodePositionList;
	}

	sf::Vector2i SingleLinkedList::NewNodePosition(SingleNode* referenceNode, Operation currentOperation)
	{
		switch (currentOperation) {
		case Operation::HEAD:
			return referenceNode->bodyPart.GetNextPosition();
		
		case Operation::TAIL:
			return referenceNode->bodyPart.GetPreviousPosition();
			
		}

		return gridPosition;
	}

	void  SingleLinkedList::IntializeNewNode(SingleNode* newNode, SingleNode* refrennceNode, Operation operation)
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
		SingleNode* newNOde = CreateNode();
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
		SingleNode* newNode;
		
		if (index < 0 || index >= linkedListSize)return;
		if (index == 0) {
			InsertNodeAtHead();
			return;
		}
		newNode = CreateNode();
		int currentIndex = 0;
		SingleNode* currentnode = headNode;
		SingleNode* prevNode = nullptr;
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

	void SingleLinkedList::ShiftNodesAfterInsertion(SingleNode* newNode, SingleNode* currentNode, SingleNode* prevNode)
	{
		SingleNode* nextNode = currentNode;
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
		SingleNode* slow = headNode;
		SingleNode* fast = headNode;

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

	void SingleLinkedList::ShitNodesAfterRemoval(SingleNode* currentNode)
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
			RemoveNodeAtHead();
			return;
		}

		RemoveNodeAtInedx(index);
	}

	void SingleLinkedList::RemoveNodeAtInedx(int Index)
	{
		SingleNode* currentNode = headNode;
		SingleNode* prevNode = nullptr;
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

		SingleNode* currentNode;
		currentNode = headNode;
		if (currentNode->next == nullptr) {
			RemoveNodeAtHead();
			return;
		}
		while (currentNode->next->next != nullptr) {
			currentNode = currentNode->next;
		}
		delete(currentNode->next);
		currentNode->next = nullptr;
	}

	SingleNode* SingleLinkedList::FindNodeAtIndex(int index)
	{
		SingleNode* currentNode = headNode;
		SingleNode* prevNode = nullptr;
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

		SingleNode* prevNode = FindNodeAtIndex(newTailIndex);
		SingleNode* currentNode = prevNode->next;
		while (currentNode != nullptr) {
			SingleNode* nodeToDelete = currentNode;
			currentNode = currentNode->next;
			delete(nodeToDelete);
			linkedListSize--;
		}
		prevNode->next= nullptr;

	}

	Direction SingleLinkedList::ReverseLinkedList()
	{
		 

		SingleNode* currentNode = headNode;
		SingleNode* prevNode = nullptr;
		SingleNode* nextNode = nullptr;

		while (currentNode != nullptr) {
			
			nextNode = currentNode->next;
			currentNode->next = prevNode;
			prevNode = currentNode;
			currentNode = nextNode;

		}
		headNode = prevNode;
		ReverseNodeDirection();
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
		SingleNode* currentNode = headNode;
		while (currentNode != nullptr) {
			currentNode->bodyPart.SetDirection(GetReverseDirection(currentNode->bodyPart.GetPreviousDirection()));
			currentNode = currentNode->next;
		}
	}
	
	
}
