
#include "../headers/Game.h"


void Game::initialize() {

    /*if (!m_font.loadFromFile("..//Comfortaa/Comfortaa-VariableFont_wght.ttf")) {
        std::cout << "eroare la încărcarea fontului";
        return;
    }*/

    //read something from config file????
    m_window.create(sf::VideoMode({wWidth, wHeight}), "Fire and Water", sf::Style::Default);

    m_window.setFramerateLimit(60);


}

void Game::run() {
    initialize();
    Menu menu(wWidth, wHeight);

    FireCharacter fireCharacter(0, sf::Vector2f(100.f, 100.f));
    WaterCharacter waterCharacter(1, sf::Vector2f(300.f, 300.f));
    Obstacle ob(EntityTag::SlimeObstacle, 2, sf::Vector2f(250.f, 250.f));
    //FireCharacter c = fireCharacter;

    m_entities.addEntity(fireCharacter.getMTag(), fireCharacter.getMPosition());
    m_entities.addEntity(waterCharacter.getMTag(), waterCharacter.getMPosition());
    m_entities.addEntity(ob.getMTag(), ob.getMPosition());


    sf::Clock clock;

    while (m_window.isOpen()) {

        sf::Event event = {};
        sf::Time deltaTime = clock.restart();
        float deltaSec = deltaTime.asSeconds();
        while (m_window.pollEvent(event)) {

            if (event.type == sf::Event::Closed)
                m_window.close();

            //Logica meniu
            if (m_currentState == GameState::MENU) {
                menu.run(event);
                if (event.key.code == sf::Keyboard::Enter) {
                    switch (menu.getSelectedItemIndex()) {
                        case 0: //start
                            m_currentState = GameState::PLAYING;
                            break;
                        case 1: //niveluri
                            std::cout << "Selecteaza nivelul\n";
                            m_window.close();//to do
                            break;
                        case 2: //iesire
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

            std::cout << fireCharacter;
            std::cout << waterCharacter;
            std::cout << ob;

            m_entities.update();
            sUserInput();
            sUpdate(deltaSec);
            sRender();
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
        e->draw(m_window);

    m_window.display();
}

//void Game::sMovement() {}

void Game::sUserInput() {
    for (auto &e: m_entities.getEntities())
        if (auto character = std::dynamic_pointer_cast<Character>(e))
            character->controller();
}

void Game::sUpdate(float deltaSec) {
    for (auto &e: m_entities.getEntities()) {//to verify later if it's not a diamond?
        e->applyGravity(m_window.getSize().y, deltaSec * 3);
        e->checkBounds(wWidth, wHeight);
    }
}

//void Game::sCollision() {}