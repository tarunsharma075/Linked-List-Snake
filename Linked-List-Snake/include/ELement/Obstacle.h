#pragma once
#include"SFML/System/Vector2.hpp"
#include"UI/UIElement/ImageView.h"
namespace Element {

	class Obstacle {

	private:
		UI::UIElement::ImageView* obstacle;
		float obstacleWidth;
		float obstacleHeight;
		sf::Vector2i obstaclePosition;

	public:
		Obstacle();
		void Intialize(sf::Vector2i grid_pos, float width, float height);
		void Render();
		void Update();
		void createObstacleImage();
		sf::Vector2f getObstacleImagePsoition();
		sf::Vector2i GetElemetPsoition();
		
		~Obstacle();
		
};
}