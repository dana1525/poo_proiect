
#include "../headers/Game.h"
#include "../headers/GameException.h"
#include "../headers/Pickup.h"

void Game::initialize() {

    /*if (!m_font.loadFromFile("..//Comfortaa/Comfortaa-VariableFont_wght.ttf")) {
        std::cout << "error loading the font";
        return;
    }*/


    //read something from config file????
    try {
        m_window.create(sf::VideoMode({wWidth, wHeight}), "Fire and Water", sf::Style::Default);
        if (!m_window.isOpen())
            throw InitializationException("Failed to create the game window");
        m_window.setFramerateLimit(60);
    } catch (const InitializationException &e) {
        std::cerr << "Error during initialization: " << e.what() << std::endl;
        throw; //in main
    }

}

void Game::run() {
    initialize();
    Menu menu(wWidth, wHeight);

    m_fire = m_entities.addFire({100.f, 100.f});
    m_water = m_entities.addWater({300.f, 300.f});
    m_entities.addEntity(EntityTag::Wall, {10.f, 690.f});
    m_entities.addEntity(EntityTag::FireEnvironment, {110.f, 690.f});
    m_entities.addEntity(EntityTag::WaterEnvironment, {160.f, 690.f});
    m_entities.addEntity(EntityTag::Pickup, {600.f, 600.f});

    sf::Clock clock;

    while (m_window.isOpen()) {

        sf::Event event = {};
        sf::Time deltaTime = clock.restart();
        float deltaSec = deltaTime.asSeconds();
        while (m_window.pollEvent(event)) {

            if (event.type == sf::Event::Closed)
                m_window.close();

            //Menu
            if (m_currentState == GameState::MENU) {
                menu.run(event);
                if (event.key.code == sf::Keyboard::Enter) {
                    switch (menu.getSelectedItemIndex()) {
                        case 0: //start
                            m_currentState = GameState::PLAYING;
                            break;
                        case 1: //levels
                            std::cout << "Select the level\n";
                            m_window.close();//to do
                            break;
                        case 2: //exit
                            m_currentState = GameState::EXIT;
                            m_window.close();
                            break;
                    }
                }
            }
        }


        if (m_currentState == GameState::MENU) {
            m_window.clear();
            menu.draw(m_window);
            m_window.display();
        } else if (m_currentState == GameState::PLAYING) {

            m_entities.update();
            sUserInput();
            sUpdate(deltaSec);
            sRender();
            sCollision(deltaSec);
        }


        using namespace std::chrono_literals;
        std::this_thread::sleep_for(100ms);

    }
//    while (m_running) {
//        m_entities.update();
//
//        if (!m_paused) {
//            sMovement();
//            sCollision();
//            //sUserInput();
//        }
//        sRender();
//        m_currentFrame++;
//    }
}

//void Game::setPaused(bool &m_paused) {
//    m_paused = true;
//}

void Game::sRender() {
    m_window.clear();

    //players' positions - in every level a different one
    for (auto &e: m_entities.getEntities())
        if (auto p = std::dynamic_pointer_cast<Pickup>(e))
            p->draw(m_window);
        else e->draw(m_window);

    m_window.display();
}

//void Game::sMovement() {}

void Game::sUserInput() {
    for (auto &e: m_entities.getEntities())
        if (auto character = std::dynamic_pointer_cast<Character>(e))
            character->controller();

}

void Game::sUpdate(float deltaSec) {
    for (auto &e: m_entities.getEntities()) {//to verify later if it's not a pickup item
        if (auto character = std::dynamic_pointer_cast<Character>(e)) {
            character->applyGravity(m_window.getSize().y, deltaSec * 3);
            character->checkBounds(wWidth, wHeight);
        } else if (auto p = std::dynamic_pointer_cast<Pickup>(e))
            p->applyGravity(m_window.getSize().y, deltaSec * 3);
    }
}

void Game::sCollision(float deltaSec) {
    //m_fire->setOnGround(false);
    //m_water->setOnGround(false);
    for (auto &e: m_entities.getEntities()) {
        if (auto p = std::dynamic_pointer_cast<Pickup>(e)) {
            for (auto &other: m_entities.getEntities()) {
                if (e != other)
                    p->collision(*other);
            }
        } else if (auto o = std::dynamic_pointer_cast<Environment>(e)) {
            for (auto &other: m_entities.getEntities()) {
                if (e != other) {
//                    if (auto character = std::dynamic_pointer_cast<Character>(e))
//                        character->stayOnWall(*o, m_window.getSize().y, deltaSec * 3);
                    o->destroyIfHarmful(*other);
                }
            }
        }
    }
}
