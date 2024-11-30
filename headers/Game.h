
#ifndef OOP_GAME_H
#define OOP_GAME_H

#include <thread>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics.hpp>
#include "Obstacle.h"
#include "Menu.h"
#include "EntityManager.h"
#include "FireCharacter.h"
#include "WaterCharacter.h"


class Game {
    sf::RenderWindow m_window;
    EntityManager m_entities;
    unsigned int wWidth = 800, wHeight = 700;
    sf::Font m_font;
    //config file?
//    int m_currentFrame = 0;
//    bool m_paused = false;
//    bool m_running = true;
    GameState m_currentState = GameState::MENU; //initializare stare joc
    std::shared_ptr<Entity> m_player;

    void initialize();

    //static void setPaused(bool &m_paused);

    ///systems
    //void sMovement();

    void sUpdate(float deltaSec);

    void sUserInput();

    void sRender();

    //void sCollision();

public:
    Game() = default;

    void run();
};

#endif //OOP_GAME_H
