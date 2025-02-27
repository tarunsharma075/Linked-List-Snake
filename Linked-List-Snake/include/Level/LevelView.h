#pragma once
#include"SFML/Graphics.hpp"
#include"UI/UIElement/RectangleShapeView.h"
namespace Level {
	class LevelView {
	private:
		sf::Color backGroundColor = sf::Color(255, 218, 185);
		UI::UIElement::RectangleShapeView* backGroundRectangle;
		UI::UIElement::RectangleShapeView* borderrectangle;
		float gridWidth;
		float gridHeight;
		void IntializeImage();
	public:
		LevelView();
		void Intialize();
		void Update();
		void Render();
		static const int borderThickness = 10;
		static const int borderOffSetLeft = 40;
		static const int borderOffSetTop = 40;
		sf::Color borderColor = sf::Color::Black;
		float GetGridheight();
		float GetGridWidth();
		void CalculateGridExtents();
		void Createborders();
		~LevelView();
	};
}