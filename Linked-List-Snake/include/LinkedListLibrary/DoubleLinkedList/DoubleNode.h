#pragma once
#include"../../LinkedListLibrary/SingleLinkedList/SingleNode.h"
namespace LinkedListLib {
	namespace DoubleLinked {
		using namespace SingleLinked;
	struct DoubelNode :public SingleNode  {

		Node* prevNode = nullptr;
	};
}
}