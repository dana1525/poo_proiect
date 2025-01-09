
#ifndef OOP_GAME_H
#define OOP_GAME_H

#include <thread>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics.hpp>
#include "Environment.h"
#include "Menu.h"
#include "MenuState.h"
#include "PlayingState.h"
#include "StateManager.h"

class Game {
    sf::RenderWindow m_window;
    sf::View m_view;
    unsigned int wWidth = 800, wHeight = 700;
    sf::Font m_font;
    StateManager m_stateManager;

    /**
    * @brief Initializes the game systems and resources.
    */
    void initialize();

///systems
//void sMovement();
//
//    /**
//     * @brief Updates the state of all entities in the game.
//     */
//    void sUpdate(float deltaSec);
//
//    /**
//     * @brief Processes user input.
//     */
//    void sUserInput();
//
//    /**
//    * @brief Renders all game elements.
//    */
//    void sRender();
//
//    /**
//    * @brief Handles collisions between entities.
//    */
//    void sCollision(float deltaSec);

public:
    Game() : m_stateManager(m_window) {};

    /**
     * @brief Starts the main game loop.
     *
     * Continuously updates, processes input, and renders the game until it is closed.
     */
    void run();
};

#endif //OOP_GAME_H
