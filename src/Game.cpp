
#include "../headers/Game.h"
#include "../headers/GameException.h"

void Game::initialize() {
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

    m_stateManager.setState(std::make_unique<MenuState>(wWidth, wHeight, m_stateManager));

    sf::Clock clock;

    while (m_window.isOpen()) {

        sf::Event event = {};
        sf::Time deltaTime = clock.restart();
        float deltaSec = deltaTime.asSeconds();
        while (m_window.pollEvent(event)) {

            if (event.type == sf::Event::Closed)
                m_window.close();

            m_stateManager.input(event);
        }
        m_stateManager.update(m_window, deltaSec * 3);
        m_stateManager.render();

        using namespace std::chrono_literals;
        std::this_thread::sleep_for(100ms);

    }
}