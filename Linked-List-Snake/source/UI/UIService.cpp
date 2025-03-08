#include "UI/UIService.h"
#include "Main/GameService.h"
#include "UI/UIElement/TextView.h"
#include"UI/LevelSelectionUI/LevelSelection.h"

namespace UI
{
	using namespace Main;
	using namespace MainMenu;
	using namespace SplashScreen;
	using namespace Instructions;
	using namespace Credits;
	using namespace UIElement;
	using namespace Interface;
	using namespace LevelSelection;
	using namespace GameplayUI;
	using namespace LinkedListUI;

	UIService::UIService()
	{
		splash_screen_controller = nullptr;
		main_menu_controller = nullptr;
		instructions_screen_ui_controller = nullptr;
		credits_screen_ui_controller = nullptr;
		level_Selection_ui_controller = nullptr;
		gameplayUiController = nullptr;
		linkedListcontroller = nullptr;

		createControllers();
	}

	void UIService::createControllers()
	{
		splash_screen_controller = new SplashScreenUIController();
		main_menu_controller = new MainMenuUIController();
		instructions_screen_ui_controller = new InstructionsScreenUIController();
		credits_screen_ui_controller = new CreditsScreenUIController();
		level_Selection_ui_controller = new LevelSelectionUIController();
		gameplayUiController = new GameplayUIController();
		linkedListcontroller = new LinkedListSelectionUIController();
	}

	UIService::~UIService()
	{
		destroy();
	}

	void UIService::initialize()
	{
		TextView::initializeTextView();
		initializeControllers();
	}

	void UIService::update()
	{
		IUIController* ui_controller = getCurrentUIController();
		if (ui_controller) ui_controller->update();
	}

	void UIService::render()
	{
		IUIController* ui_controller = getCurrentUIController();
		if (ui_controller) ui_controller->render();
	}

	void UIService::showScreen()
	{
		IUIController* ui_controller = getCurrentUIController();
		if (ui_controller) ui_controller->show();
	}

	void UIService::initializeControllers()
	{
		splash_screen_controller->initialize();
		main_menu_controller->initialize();
		instructions_screen_ui_controller->initialize();
		credits_screen_ui_controller->initialize();
		level_Selection_ui_controller->initialize();
		gameplayUiController->initialize();
		linkedListcontroller->initialize();
	}

	IUIController* UIService::getCurrentUIController()
	{
		switch (GameService::getGameState())
		{
		case GameState::SPLASH_SCREEN:
			return splash_screen_controller;

		case GameState::MAIN_MENU:
			return main_menu_controller;

		case GameState::INSTRUCTIONS:
			return instructions_screen_ui_controller;

		case GameState::CREDITS:
			return credits_screen_ui_controller;
		case GameState::LEVEL_SELECTION:
			return level_Selection_ui_controller;
		case::GameState::GAMEPLAY:
			return gameplayUiController;
		case::GameState::LINKED_LIST_SELECTION:
			return linkedListcontroller;
		default:
			return nullptr;
		}
	}

	void UIService::destroy()
	{
		delete(splash_screen_controller);
		delete(main_menu_controller);
		delete(instructions_screen_ui_controller);
		delete(credits_screen_ui_controller);
		delete(level_Selection_ui_controller);
		delete(gameplayUiController);
	}
}