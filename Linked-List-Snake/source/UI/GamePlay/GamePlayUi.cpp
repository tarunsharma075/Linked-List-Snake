#include"UI/GamePlay/GamePlayUi.h"
#include "Main/GameService.h"
#include "Graphics/GraphicService.h"
#include "Sound/SoundService.h"
#include "Event/EventService.h"
#include "Global/Config.h"
#include "Level/LevelModel.h"
#include "Player/PlayerService.h"
#include<iostream>
namespace UI
{
    namespace GameplayUI
    {
        using namespace Global;
        using namespace Event;
        using namespace Sound;
        using namespace Main;
        using namespace Graphics;
        using namespace Level;
        using namespace Player;
        using namespace UI::UIElement;

        GameplayUIController::GameplayUIController()
        {
            createTexts();
        }

        GameplayUIController::~GameplayUIController()
        {
            destroy();
        }

        void GameplayUIController::initialize()
        {
            initializeTexts();
        }

        void GameplayUIController::createTexts()
        {
            level_number_text = new TextView();
            score_text = new TextView();
            time_complexity_text = new TextView();
            operation_text = new TextView();
        }

        void GameplayUIController::initializeTexts()
        {
            initializeLevelNumberText();
            initializeScoreText();
            initializeOperationText();
            initializeTimeComplexityText();
        }

        void GameplayUIController::initializeLevelNumberText()
        {
            level_number_text->initialize("Level : 1", sf::Vector2f(level_number_text_x_position, text_y_position), FontType::BUBBLE_BOBBLE, font_size, sf::Color::Black);
        }

        void GameplayUIController::initializeScoreText()
        {
            score_text->initialize("Score : 0", sf::Vector2f(score_text_x_position, text_y_position), FontType::BUBBLE_BOBBLE, font_size, sf::Color::Black);
        }

        void GameplayUIController::initializeTimeComplexityText()
        {
            time_complexity_text->initialize("Time Complexity : O(1)", sf::Vector2f(time_complexity_text_x_position, time_complexity_text_y_position), FontType::BUBBLE_BOBBLE, operations_font_size, sf::Color::Black);
        }

        void GameplayUIController::initializeOperationText()
        {
            operation_text->initialize("Last Operation : Insert at Middle", sf::Vector2f(operations_text_x_position, operations_text_y_position), FontType::BUBBLE_BOBBLE, operations_font_size, sf::Color::Black);
        }

        void GameplayUIController::updateLevelNumberText()
        {
            LevelNumber level_number = ServiceLocator::getInstance()->GetLevelServices()->GetCurrentLevel();
            sf::String level_number_value = std::to_string(1 + static_cast<int>(level_number));

            level_number_text->setText("Level : " + level_number_value);
            level_number_text->update();
        }

        void GameplayUIController::updateScoreText()
        {
            int player_score = ServiceLocator::getInstance()->GetPlayerService()->GetPlayerScore();
            sf::String score_value = std::to_string(player_score);

            score_text->setText("Score : " + score_value);
            score_text->update();
        }

        void GameplayUIController::updateTimeComplexityText()
        {
            TimeComplexity timeComplexity = ServiceLocator::getInstance()->GetPlayerService()->GetTimeComplexity();
            sf::String timeComplexityValue;
            switch (timeComplexity) {

            case TimeComplexity::NONE:
                timeComplexityValue = "";
                break;
            case TimeComplexity::ONE:
                timeComplexityValue = "1";
                break;
            case TimeComplexity::N:
                timeComplexityValue = "N";
                break;
            }
            time_complexity_text->setText("Time Complexity : (" + timeComplexityValue + ")");
            time_complexity_text->update();
        }

        void GameplayUIController::updateOperationText()
        {

            // Get last operation type from player service
            LinkedListOperation operation = ServiceLocator::getInstance()->GetPlayerService()->GetLinkedListOperation();
            sf::String operation_value;

            // Convert operation type to string based on enum value
            switch (operation)
            {
            case LinkedListOperation::NONE:
                operation_value = "";
                break;  // <-- MISSING BREAK ADDED
            case LinkedListOperation::INSERT_AT_HEAD:
                operation_value = "Insert at Head";
                break;
            case LinkedListOperation::INSERT_AT_TAIL:
                operation_value = "Insert at Tail";
                break;
            case LinkedListOperation::INSERT_AT_MID:
                operation_value = "Insert at Mid";
                break;
            case LinkedListOperation::REMOVE_AT_HEAD:
                operation_value = "Remove at Head";
                break;
            case LinkedListOperation::REMOVE_AT_TAIL:
                operation_value = "Remove at Tail";
                break;
            case LinkedListOperation::REMOVE_AT_MID:
                operation_value = "Remove at Mid";
                break;
            case LinkedListOperation::DELETE_HALF_LIST:
                operation_value = "Delete Half List";
                break;
            case LinkedListOperation::REVERSE_LIST:
                operation_value = "Reverse List";
                break;

            }

            // Update text with formatted operation information
            operation_text->setText("Last Operation : " + operation_value);
            operation_text->update();

        }

        void GameplayUIController::update()
        {
            updateLevelNumberText();
            updateScoreText();
            updateTimeComplexityText();
            updateOperationText();
        }

        void GameplayUIController::render()
        {
            
            level_number_text->render();
            score_text->render();
            operation_text->render();
            time_complexity_text->render();
        }

        void GameplayUIController::show()
        {
            level_number_text->show();
            score_text->show();
            operation_text->show();
            time_complexity_text->show();
        }

        void GameplayUIController::destroy()
        {
            delete (level_number_text);
            delete (score_text);
            delete(time_complexity_text);
            delete(operation_text);
        }
    }
}