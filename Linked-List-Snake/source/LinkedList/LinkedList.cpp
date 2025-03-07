#include"LinkedListLibrary/LinkedList.h"
#include"Level/LevelView.h"
#include"Global/Config.h"
using namespace Level;
using namespace Global;
namespace LinkedListLib
{
    LinkedList::LinkedList()
    {
        head_node = nullptr;
    }

    LinkedList::~LinkedList() = default;

    void LinkedList::initialize(float width, float height, sf::Vector2i position, Direction direction)
    {
        node_width = width;
        node_height = height;
        default_position = position;
        default_direction = direction;
        linked_list_size = 0;
    }

    void LinkedList::render()
    {
        Node* cur_node = head_node;

        while (cur_node != nullptr)
        {
            cur_node->bodyPart.Render();
            cur_node = cur_node->next;
        }
    }

    void LinkedList::updateNodeDirection(Direction direction_to_set)
    {
        Node* cur_node = head_node;

        while (cur_node != nullptr)
        {
            Direction previous_direction = cur_node->bodyPart.GetDirection();
            cur_node->bodyPart.SetDirection(direction_to_set);
            direction_to_set = previous_direction;
            cur_node = cur_node->next;
        }
    }

    void LinkedList::updateNodePosition()
    {
        Node* cur_node = head_node;

        while (cur_node != nullptr)
        {
            cur_node->bodyPart.UpdatePosition();
            cur_node = cur_node->next;
        }
    }

    void LinkedList::initializeNode(Node* new_node, Node* reference_node, Operation operation)
    {
        if (reference_node == nullptr)
        {
            new_node->bodyPart.Intialize(node_width, node_height, default_position, default_direction);
            return;
        }

        sf::Vector2i position = getNewNodePosition(reference_node, operation);

        new_node->bodyPart.Intialize(node_width, node_height, position, reference_node-> bodyPart.GetDirection());
    }

    bool LinkedList::processNodeCollision()
    {
        if (head_node == nullptr) return false;

        sf::Vector2i predicted_position = head_node->bodyPart.GetNextPosition();

        Node* cur_node = head_node->next;
        while (cur_node != nullptr)
        {
            if (cur_node->bodyPart.GetNextPosition() == predicted_position)
            {
                return true;
            }

            cur_node = cur_node->next;
        }

        return false;
    }

    Node* LinkedList::createNode()
    {
        return new Node();
    }

    sf::Vector2i LinkedList::getNewNodePosition(Node* reference_node, Operation operation)
    {
        switch (operation)
        {
        case Operation::HEAD:
            return reference_node->bodyPart.GetNextPosition();
        case Operation::TAIL:
            return reference_node->bodyPart.GetPreviousPosition();
        }

        return default_position;
    }

    Node* LinkedList::getHeadNode()
    {
        return head_node;
    }

    int LinkedList::getLinkedListSize()
    {
        return linked_list_size;
    }

    std::vector<sf::Vector2i> LinkedList::getNodesPositionList()
    {
        std::vector<sf::Vector2i> nodes_position_list;

        Node* cur_node = head_node;

        while (cur_node != nullptr)
        {
            nodes_position_list.push_back(cur_node->bodyPart.GetPosition());
            cur_node = cur_node->next;
        }

        return nodes_position_list;
    }

    int LinkedList::findMiddleNode()
    {
        Node* slow = head_node;
        Node* fast = head_node;
        int midIndex = 0;  // This will track the index of the middle node.

        // Move fast pointer at 2x speed and slow pointer at 1x speed.
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            midIndex++;
        }

        // Now, slow is at the middle node
        return midIndex;
    }

    Node* LinkedList::findNodeAtIndex(int index)
    {
        int current_index = 0;
        Node* cur_node = head_node;
        Node* prev_node = nullptr;

        while (cur_node != nullptr && current_index <= index)
        {
            prev_node = cur_node;
            cur_node = cur_node->next;
            current_index++;
        }

        return prev_node;
    }

    void LinkedList::reverseNodeDirections()
    {
        Node* curr_node = head_node;

        while (curr_node != nullptr)
        {
            curr_node->bodyPart.SetDirection(getReverseDirection(curr_node->bodyPart.GetPreviousDirection()));
            curr_node = curr_node->next;
        }
    }

    Direction LinkedList::getReverseDirection(Direction reference_direction)
    {
        switch (reference_direction)
        {
        case Direction::UP:
            return Direction::DOWN;
        case Direction::DOWN:
            return Direction::UP;
        case Direction::LEFT:
            return Direction::RIGHT;
        case Direction::RIGHT:
            return Direction::LEFT;
        }
    }
}