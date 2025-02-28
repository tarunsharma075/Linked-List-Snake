#pragma once
#include"SFML//System/Vector2.hpp"
using namespace sf;
namespace Element {

	enum class  ElementType {
		
		Obstacle,
	};

	struct ElementData {

		ElementData(Vector2i pos, ElementType type) {
			position = pos;
			element = type;
		}
		ElementType element;
		Vector2i position;
	};
}