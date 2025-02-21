#pragma once
#include"UI/UIElement/ImageView.h"
#include"Player/Direction.h"
#include<SFML/Graphics.hpp>
namespace Player {
	class BodyPart {

	protected:
		UI::UIElement::ImageView* bodyPart;
		sf::Vector2i gridPosition;
		Direction direction;
		float bodyPartWidth;
		float bodyPartHeight;
	};


}