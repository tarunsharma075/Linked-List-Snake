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
		float ChangeRotation;
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
			sf::Vector2f BodyPartScreenPosition();
			sf::Vector2i GetNextPosition();
			sf::Vector2i getNextPositionUp();
			sf::Vector2i getNextPositionDown();
			sf::Vector2i getNextPositionLeft();
			sf::Vector2i getNextPositioRight();
			void SetPosition(sf::Vector2i position);
			void UpdatePosition();
			float GetRotation();
			Direction GetDirection();
			sf::Vector2i GetPosition();


			
			~BodyPart();
		
	};


}