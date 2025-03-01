#include"Level/LevelView.h";
#include"Global/ServiceLocator.h"
using namespace Global;
namespace Level {
	void LevelView::IntializeImage()
	{
		sf::RenderWindow* gameWindow = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		sf::Vector2f backGroundsize=sf::Vector2f(gameWindow->getSize().x, gameWindow->getSize().y);
		backGroundRectangle->initialize(backGroundsize, sf::Vector2f(0, 0),0, backGroundColor);
		backGroundRectangle->show();


	}
	Level::LevelView::LevelView()
	{
		backGroundRectangle = new UI::UIElement::RectangleShapeView();
		borderrectangle = new UI::UIElement::RectangleShapeView();
	}
void LevelView::Intialize()
	{
	IntializeImage();
	CalculateGridExtents();
	Createborders();
	}
	void LevelView::Update()
	{
		backGroundRectangle->update();
		borderrectangle->update();
	}
	void LevelView::Render()
	{
		backGroundRectangle->render();
		borderrectangle->render();
	}
	float LevelView::GetGridheight()
	{
		return gridHeight;
	}
	float LevelView::GetGridWidth()
	{
		return gridWidth;
	}
	void LevelView::CalculateGridExtents()
	{
		sf::RenderWindow* window = Global::ServiceLocator::getInstance()->getInstance()->getGraphicService()->getGameWindow();
		gridHeight = window->getSize().y - 2 * borderOffSetTop;
		gridWidth = window->getSize().x - 2 * borderOffSetLeft;

	}
	void LevelView::Createborders()
	{
		sf::RenderWindow* window = Global::ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		sf::Vector2f borderSize = sf::Vector2f(gridWidth, gridHeight);
		sf::Vector2f borderPosition = sf::Vector2f(borderOffSetLeft, borderOffSetTop);
		borderrectangle->initialize(borderSize, borderPosition, borderThickness, sf::Color::Transparent, borderColor);
		borderrectangle->show();
	}
	LevelView::~LevelView()
	{
		delete(backGroundRectangle);
		delete(borderrectangle);
	}
}