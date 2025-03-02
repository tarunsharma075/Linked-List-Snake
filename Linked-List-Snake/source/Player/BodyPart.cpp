#include "Player/BodyPart.h"
#include"Global/Config.h"
#include"Level/LevelView.h"
#include"Level/LevelModel.h"
namespace Player {
	void Player::BodyPart::CreateBodyParts()
	{
		bodyPart = new UI::UIElement::ImageView();

	}

	BodyPart::BodyPart()
	{
		
		gridPosition = sf::Vector2i(0, 0);
		CreateBodyParts();
	}

	void Player::BodyPart::Intialize(float width, float height, sf::Vector2i pos, Direction di)
	{
		bodypartWidth = width;
		bodyPartHeight = height;
		gridPosition = pos;
		direction = di;
		IntializeBodyParts();
	}

	void Player::BodyPart::Update()
	{
		UpdatePosition();
	}

	void Player::BodyPart::Render()
	{
		bodyPart->render();
	}
	void BodyPart::Destroy()
	{
		delete(bodyPart);
	}
	void BodyPart::IntializeBodyParts()
	{
		bodyPart->initialize(Global::Config::snake_body_texture_path, bodypartWidth, bodyPartHeight, BodyPartScreenPosition());
		bodyPart->setOriginAtCentre();
	}
	sf::Vector2f BodyPart::BodyPartScreenPosition()
	{
		float xPosition = Level::LevelView::borderOffSetLeft + (gridPosition.x * bodypartWidth) + (bodypartWidth / 2);
		float yPosition = Level::LevelView::borderOffSetTop + (gridPosition.y * bodyPartHeight) + (bodyPartHeight / 2);
		return sf::Vector2f(xPosition, yPosition);
	}
	sf::Vector2i BodyPart::GetNextPosition()
	{
		switch(direction){	
		case  Direction::UP:
				return getNextPositionUp();

			case Direction::DOWN:
				return getNextPositionDown();
			case Direction::LEFT:
					return getNextPositionLeft();
			case Direction::RIGHT:
				return getNextPositioRight();
			default:
				return gridPosition;
		}
		
				
			
	}
	sf::Vector2i BodyPart::getNextPositionUp()
	{
		return sf::Vector2i(gridPosition.x,
			(gridPosition.y - 1 + Level::LevelModel::number_of_rows) % Level::LevelModel::number_of_rows);
	}

	sf::Vector2i BodyPart::getNextPositionDown()
	{
		return sf::Vector2i(gridPosition.x,
			(gridPosition.y + 1)%(Level::LevelModel::number_of_rows));
	}

	sf::Vector2i BodyPart::getNextPositionLeft()
	{
		return sf::Vector2i((gridPosition.x - 1 + Level::LevelModel::number_of_columns) % Level::LevelModel::number_of_columns,
			gridPosition.y);
	}

	sf::Vector2i BodyPart::getNextPositioRight()
	{
		return sf::Vector2i((gridPosition.x == Level::LevelModel::number_of_columns - 1 ? 0 : gridPosition.x + 1),
			gridPosition.y);
	}

	sf::Vector2i BodyPart::GetPreviousPosition()
	{
		switch (direction) {

		case Direction::UP:
			return getNextPositionDown();
		case Direction::DOWN:
			return getNextPositionUp();
		case Direction::RIGHT:
			return getNextPositionLeft();
		case Direction::LEFT:
			return getNextPositioRight();
		default:
			return gridPosition;

		}
	}

	void BodyPart::SetPosition(sf::Vector2i position)
	{
		gridPosition = position;  // Fix: Ab correctly set hoga position
	}


	void BodyPart::UpdatePosition()
	{
		gridPosition = GetNextPosition();
		bodyPart->setPosition(BodyPartScreenPosition());
		bodyPart->setRotation(GetRotation());
		bodyPart->update();
	}
	float  BodyPart::GetRotation()
	{
		switch (direction) {
			case Direction::UP:
				return 270.f;
			case Direction::DOWN:
				return 90.f;
			case Direction::RIGHT:
				return 0;
			case Direction::LEFT:
				return 180.f;
		}
	}
	Direction BodyPart::GetDirection()
	{
		return direction;
	}
	sf::Vector2i BodyPart::GetPosition()
	{
		return gridPosition;
	}
	void BodyPart::SetDirection(Direction DirectionToSet)
	{
		this->direction = DirectionToSet;
	}
	BodyPart::~BodyPart()
	{
		Destroy();
	}
}
