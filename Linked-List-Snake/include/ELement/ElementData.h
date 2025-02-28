#pragma once
#include"SFML//System/Vector2.hpp"
using namespace sf;
namespace Element {

	enum class  ElementType {
		
		OBSTACLE,
	};

	struct ElementData {

		ElementData(ElementType type, Vector2i pos) {
			position = pos;
			element = type;
		}
		ElementType element;
		Vector2i position;
	};
}