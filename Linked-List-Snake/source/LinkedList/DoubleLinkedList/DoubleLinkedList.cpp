#include"LinkedListLibrary/DoubleLinkedList/DoubleLinkedList.h"
#include"LinkedListLibrary/DoubleLinkedList/DoubleNode.h"
namespace LinkedListLib{
Node* LinkedListLib::DoubleLinked::DoubleLinkedList::createNode()
{
	return new DoubelNode();
}

DoubleLinked::DoubleLinkedList::DoubleLinkedList()
{
	createNode();
}

DoubleLinked::DoubleLinkedList::~DoubleLinkedList()
{
}

void DoubleLinked::DoubleLinkedList::insertNodeAtTail()
{
	linked_list_size++;
	Node* newnode = createNode();
	Node* currentNode = head_node;
	if (currentNode == nullptr) {

		static_cast<DoubelNode*>(newnode)->prevNode = nullptr;
		initializeNode(newnode, nullptr, Operation::TAIL);
		return;
	}

	while (currentNode->next != nullptr) {
		currentNode = currentNode->next;

	}
	currentNode->next = newnode;
	static_cast<DoubelNode*>(newnode)->prevNode = currentNode;
	initializeNode(newnode, currentNode, Operation::TAIL);

}

void DoubleLinked::DoubleLinkedList::insertNodeAtHead()
{
	linked_list_size++;
	Node* newnode = createNode();
	if (head_node == nullptr) {
		head_node = newnode;
		static_cast<DoubelNode*>(newnode)->prevNode = nullptr;
		initializeNode(newnode, nullptr, Operation::HEAD);
		return;
	}

	initializeNode(newnode, head_node, Operation::HEAD);
	head_node = newnode;

}

void DoubleLinked::DoubleLinkedList::insertNodeAtMiddle()
{
	if (head_node == nullptr) {
		insertNodeAtHead();
		return;
	}

	int middleindex = findMiddleNode();
	insertNodeAtIndex(middleindex);
}

void DoubleLinked::DoubleLinkedList::insertNodeAtIndex(int index)
{
	
	if (index < 0 || index >= linked_list_size)return;

	if (index == 0) {
		insertNodeAtHead();
		return;
	}
	Node* currentNode = head_node;
	int currentindex = 0;
	Node* newNode = createNode();
	Node* prevNode = nullptr;
	while (currentNode != nullptr && currentindex < index) {

		prevNode = currentNode;
		currentNode = currentNode->next;
		currentindex++;
	}
	prevNode->next = newNode;
	static_cast<DoubelNode*>(newNode)->prevNode = prevNode;
	static_cast<DoubelNode*>(currentNode)->prevNode = newNode;
	initializeNode(newNode, head_node, Operation::TAIL);
	linked_list_size++;
	shiftNodesAfterInsertion(newNode, currentNode, prevNode);
}

void DoubleLinked::DoubleLinkedList::shiftNodesAfterInsertion(Node* new_node, Node* cur_node, Node* prev_node)
{
	Node* nextNode = cur_node;
	cur_node = new_node;

	while (cur_node != nullptr && nextNode != nullptr) {

		cur_node->bodyPart.SetPosition(nextNode->bodyPart.GetPosition());
		cur_node->bodyPart.SetDirection(nextNode->bodyPart.GetDirection());
		prev_node = cur_node;
		cur_node = nextNode;
		nextNode = nextNode->next;


	}
	initializeNode(cur_node, prev_node, Operation::TAIL);
}

void DoubleLinked::DoubleLinkedList::removeNodeAtTail()
{
}

void DoubleLinked::DoubleLinkedList::removeNodeAtHead()
{
	Node* currentNode;
	currentNode = head_node;
	head_node = head_node->next;
	if (currentNode != nullptr) {
		static_cast<DoubelNode*>(head_node)->prevNode = nullptr;

	}
	currentNode->next = nullptr;
	delete(currentNode);
}

void DoubleLinked::DoubleLinkedList::removeNodeAtMiddle()
{
}

void DoubleLinked::DoubleLinkedList::removeNodeAt(int index)
{
}

void DoubleLinked::DoubleLinkedList::removeNodeAtIndex(int index)
{
}

void DoubleLinked::DoubleLinkedList::removeAllNodes()
{
}

void DoubleLinked::DoubleLinkedList::removeHalfNodes()
{
}


}


