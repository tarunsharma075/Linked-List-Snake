#include"LinkedList/SingleLinkedList.h"
namespace LinekdList {
	Player::Node* SingleLinkedList::CreateNode()
	{
		return new Player::Node;;
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
	}
	void SingleLinkedList::Render()
	{
	}
}
