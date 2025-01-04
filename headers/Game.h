
#ifndef OOP_GAME_H
#define OOP_GAME_H

#include <thread>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics.hpp>
#include "Environment.h"
#include "Menu.h"
#include "EntityManager.h"
#include "FireCharacter.h"
#include "WaterCharacter.h"


class Game {
    sf::RenderWindow m_window;
    sf::View m_view;
    EntityManager m_entities;
    unsigned int wWidth = 800, wHeight = 700;
    sf::Font m_font;
    //config file?
//    int m_currentFrame = 0;
//    bool m_paused = false;
//    bool m_running = true;
    GameState m_currentState = GameState::MENU; //initialize game state
    std::shared_ptr<FireCharacter> m_fire;
    std::shared_ptr<WaterCharacter> m_water;


    /**
    * @brief Initializes the game systems and resources.
    */
    void initialize();

//static void setPaused(bool &m_paused);

///systems
//void sMovement();

    /**
     * @brief Updates the state of all entities in the game.
     */
    void sUpdate(float deltaSec);

    /**
     * @brief Processes user input.
     */
    void sUserInput();

    /**
    * @brief Renders all game elements.
    */
    void sRender();

    /**
    * @brief Handles collisions between entities.
    */
    void sCollision(float deltaSec);

public:
    Game() = default;

    /**
     * @brief Starts the main game loop.
     *
     * Continuously updates, processes input, and renders the game until it is closed.
     */
    void run();
};

#endif //OOP_GAME_H
