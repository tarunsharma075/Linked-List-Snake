#include"ELement/Obstacle.h"
#include"Global/ServiceLocator.h"
#include"Global/Config.h"
#include"Level/LevelView.h"
namespace Element {
	Element::Obstacle::Obstacle()
	{
		obstacle = new UI::UIElement::ImageView();
	}
	void Obstacle::Intialize(sf::Vector2i grid_pos, float width, float height)
	{
		obstaclePosition = grid_pos;
		obstacleWidth = width;
		obstacleHeight = height;
		createObstacleImage();
	}
	void Obstacle::Render()
	{
		obstacle->render();
	}
	void Obstacle::Update()
	{
		obstacle->update();
	}
	void Obstacle::createObstacleImage()
	{
		sf::Vector2f screenPsoition = getObstacleImagePsoition();
		obstacle->initialize(Global::Config::obstacle_texture_path, obstacleWidth, obstacleHeight, screenPsoition);
		obstacle->show();
	}
	sf::Vector2f Obstacle::getObstacleImagePsoition()
	{
		float xScreenPsoition = Level::LevelView::borderOffSetLeft + (obstacleWidth * obstaclePosition.x);
		float yScreenPsoition = Level::LevelView::borderOffSetTop + (obstacleHeight * obstaclePosition.y);
		return sf::Vector2f(xScreenPsoition, yScreenPsoition);
	}

	sf::Vector2i Obstacle::GetElemetPsoition()
	{
		return obstaclePosition;
	}
	
	Obstacle::~Obstacle()
	{
		delete(obstacle);
	}
}
