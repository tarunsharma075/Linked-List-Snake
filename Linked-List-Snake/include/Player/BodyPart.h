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
	

		private:
			void CreateBodyParts();
		public:
			BodyPart();
			void Intialize(float width, float height, sf::Vector2i pos, Direction dir);
			void Update();
			void Render();
			void Destroy();
			void IntializeBodyParts();
			sf::Vector2f BodyScreenPosition();
			~BodyPart();
		
	};


}