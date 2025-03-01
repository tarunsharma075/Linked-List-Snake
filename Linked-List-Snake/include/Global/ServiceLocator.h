#pragma once
#include "Graphics/GraphicService.h"
#include "Event/EventService.h"
#include "UI/UIService.h"
#include "Sound/SoundService.h"
#include "Time/TimeService.h"
#include"Level/LevelService.h"
#include"Player/PlayerService.h"
#include"ELement/ElementService.h"
#include"Food/FoodService.h"
using namespace Graphics;
using namespace Event;
using namespace Sound;
using namespace UI;
using namespace Time;
using namespace Level;
using namespace  Player;
using namespace Element;
using namespace Food;
namespace Global
{

    class ServiceLocator
    {
    private:
       EventService* event_service;
        GraphicService* graphic_service;
       SoundService* sound_service;
        UIService* ui_service;
        TimeService* time_service;
        LevelService* levelService;
       PlayerService* playerService;
      ElementService* elemetservice;
      FoodService* foodService;

        ServiceLocator();
        ~ServiceLocator();

        void createServices();
        void clearAllServices();

    public:
        static ServiceLocator* getInstance();

        void initialize();
        void update();
        void render();

        EventService* getEventService();
        GraphicService* getGraphicService();
        SoundService* getSoundService();
        UIService* getUIService();
        TimeService* getTimeService();
        LevelService* GetLevelServices();
        PlayerService* GetPlayerService();
        ElementService* GetElementService();
        FoodService* GetFoodService();
        void deleteServiceLocator();
    };
}