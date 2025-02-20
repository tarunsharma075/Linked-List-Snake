#include"UI/LevelSelectionUI/LevelSelection.h"
#include "Main/GameService.h"
#include "Graphics/GraphicService.h"
#include "Sound/SoundService.h"
#include "Event/EventService.h"
#include "UI/UIElement/ButtonView.h"
#include "UI/UIElement/ImageView.h"
#include "Global/Config.h"
#include "Level/LevelService.h"
#include<iostream>
namespace UI
{
	using namespace UIElement;
	using namespace Global;
	using namespace Event;
	using namespace Sound;
	using namespace Main;
	namespace LevelSelection
	{
		LevelSelectionUI::LevelSelectionUI()
		{
			createImage();
			createButtons();
		}
		LevelSelectionUI::~LevelSelectionUI()
		{
			destroy();
		}
		void LevelSelectionUI::initialize()
		{
			initializeBackgroundImage();
			initializeButtons();
			registerButtonCallback();
		}
		void LevelSelectionUI::update()
		{
			
			background_image->update();
			level_one_button->update();
			level_two_button->update();
			menu_button->update();
			
			
		}
		void LevelSelectionUI::render()
		{
			background_image->render();
			level_one_button->render();
			level_two_button->render();
			menu_button->render();
		
		}
		void LevelSelectionUI::show()
		{
			background_image->show();
			level_one_button->show();
			level_two_button->show();
			menu_button->show();
		}
		void LevelSelectionUI::createImage()
		{
			background_image = new ImageView();
			
		}
		void LevelSelectionUI::createButtons()
		{
			level_one_button = new ButtonView();
			level_two_button = new ButtonView();
			menu_button = new ButtonView();
		}
		void LevelSelectionUI::initializeBackgroundImage()
		{
			sf::RenderWindow* window = Global::ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
			background_image->initialize(Config::background_texture_path, window->getSize().x, window->getSize().y, sf::Vector2f(0, 0));
			background_image->setImageAlpha(background_alpha);
		}
		void LevelSelectionUI::initializeButtons()
		{
			float xposition = calculateLeftOffsetForButton();
			level_one_button->initialize("Level One Button", Config::level_one_button_texture_path, button_width, button_height, sf::Vector2f(xposition, level_one_button_y_position));
			level_two_button->initialize("Level Two Button", Config::level_two_button_texture_path, button_width, button_height, sf::Vector2f(xposition, level_two_button_y_position));
			menu_button->initialize("Main Menu", Config::menu_button_texture_path, button_width, button_height, sf::Vector2f(xposition, menu_button_y_position));
		}
		void LevelSelectionUI::registerButtonCallback()
		{
			level_one_button->registerCallbackFuntion(std::bind(&LevelSelectionUI::levelOneButtonCallback, this));
			level_two_button->registerCallbackFuntion(std::bind(&LevelSelectionUI::levelTwoButtonCallback, this));
			menu_button->registerCallbackFuntion(std::bind(&LevelSelectionUI::menuButtonCallback, this));
		}
		float LevelSelectionUI::calculateLeftOffsetForButton()
		{
			sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
			return (static_cast<float>(game_window->getSize().x) / 2) - button_width / 2;
		}
		void LevelSelectionUI::levelOneButtonCallback()
		{
			std::cout << "LevelOne";
			ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
			GameService::setGameState(GameState::GAMEPLAY);
			ServiceLocator::getInstance()->GetLevelServices()->createLevel(Level::LevelNumber::ONE);
		}
		void LevelSelectionUI::levelTwoButtonCallback()
		{

			ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
			GameService::setGameState(GameState::GAMEPLAY);
			ServiceLocator::getInstance()->GetLevelServices()->createLevel(Level::LevelNumber::TWO);
		}
		void LevelSelectionUI::menuButtonCallback()
		{
			ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
			GameService::setGameState(GameState::MAIN_MENU);

		}
		void LevelSelectionUI::destroy()
		{
			delete (background_image);
			delete (level_one_button);
			delete (level_two_button);
			delete (menu_button);
		}
	}
}
