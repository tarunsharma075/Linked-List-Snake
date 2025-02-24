#pragma once
#include"Player/BodyPart.h"
namespace Player {

	struct Node {
		BodyPart bodyPart;
		Node* next = nullptr;
	};

	

}