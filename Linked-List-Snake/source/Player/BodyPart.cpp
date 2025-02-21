#include "Player/BodyPart.h"
#include"Global/Config.h"
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
		bodyPartWidth = width;
		bodyPartHeight = height;
		gridPosition = pos;
		direction = di;
		IntializeBodyParts();
	}

	void Player::BodyPart::Update()
	{
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
		bodyPart->initialize(Global::Config::snake_body_texture_path, bodyPartWidth, bodyPartHeight, BodyScreenPosition());
		bodyPart->setOriginAtCentre();
	}
	sf::Vector2f BodyPart::BodyScreenPosition()
	{
		return sf::Vector2f(0, 0);
	}
	BodyPart::~BodyPart()
	{
		Destroy();
	}
}
