
#include "../headers/MenuState.h"

void MenuState::input(sf::Event &event) {
    m_menu.run(event);
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
        m_menu.executeCommand();
    }
}

void MenuState::render(sf::RenderWindow &window) {
    window.clear();
    m_menu.draw(window);
    window.display();
}