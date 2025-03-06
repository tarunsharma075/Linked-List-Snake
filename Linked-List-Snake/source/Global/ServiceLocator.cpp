#include "Global/ServiceLocator.h"
#include "Main/GameService.h"
namespace Global
{
	
	using namespace Main;

	
	ServiceLocator::ServiceLocator()
	{
		graphic_service = nullptr;
		event_service = nullptr;
		sound_service = nullptr;
		ui_service = nullptr;
		time_service = nullptr;
		levelService = nullptr;
		playerService = nullptr;
		elemetservice = nullptr;
		foodService =nullptr;

		createServices();
	}

	ServiceLocator::~ServiceLocator() { clearAllServices(); }

	void ServiceLocator::createServices()
	{
		event_service = new EventService();
		graphic_service = new GraphicService();
		sound_service = new SoundService();
		ui_service = new UIService();
		time_service = new TimeService();
		levelService = new LevelService();
		playerService = new PlayerService();
		elemetservice = new ElementService();
		foodService = new FoodService();
	}
	void ServiceLocator::initialize()
	{
		graphic_service->initialize();
		sound_service->initialize();
		event_service->initialize();
		levelService->Initialize();
		playerService->Intialize();
		ui_service->initialize();
		time_service->initialize();
		elemetservice->Intialize();
		foodService->Intialize();
	
	}

	void ServiceLocator::update()
	{
		graphic_service->update();
		event_service->update();
		if (GameService::getGameState() == GameState::GAMEPLAY) {
			levelService->Update();
			playerService->Update();
			elemetservice->Update();
			foodService->Update();
		}
		ui_service->update();
		time_service->update();
		levelService->Update();
	}

	void ServiceLocator::render()
	{
		
		graphic_service->render();

		if (GameService::getGameState() == GameState::GAMEPLAY) {
			levelService->Render();
			playerService->Render();
			elemetservice->Render();
			foodService->Render();
		}
		ui_service->render();
		

	}

	void ServiceLocator::clearAllServices()
	{
		delete(ui_service);
		delete(graphic_service);
		delete(sound_service);
		delete(event_service);
		delete(time_service);
		delete(levelService);
		delete(playerService);
		delete(elemetservice);
		delete(foodService);
	}

	ServiceLocator* ServiceLocator::getInstance()
	{
		static ServiceLocator instance;
		return &instance;
	}

	EventService* ServiceLocator::getEventService() { return event_service; }

	GraphicService* ServiceLocator::getGraphicService() { return graphic_service; }

	SoundService* ServiceLocator::getSoundService() { return sound_service; }

	UIService* ServiceLocator::getUIService() { return ui_service; }

	Time::TimeService* ServiceLocator::getTimeService() { return time_service; }

	Level::LevelService* ServiceLocator::GetLevelServices()
	{
		return levelService;
	}

	Player::PlayerService* ServiceLocator::GetPlayerService()
	{
		return playerService;
	}

	Element::ElementService* ServiceLocator::GetElementService()
	{
		return elemetservice;
	}

	FoodService* ServiceLocator::GetFoodService()
	{
		return foodService;
	}

	void ServiceLocator::deleteServiceLocator() { delete(this); }
}