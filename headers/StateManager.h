
#ifndef OOP_STATEMANAGER_H
#define OOP_STATEMANAGER_H

#include "State.h"
#include <memory>
#include <SFML/Graphics.hpp>

class StateManager {
    std::unique_ptr<State> m_state;
    sf::RenderWindow &m_window;
public:
    explicit StateManager(sf::RenderWindow &window) : m_window(window) {}

    void setState(std::unique_ptr<State> newState) {
        m_state = std::move(newState);
    }

    void input(sf::Event &event) {
        if (m_state) m_state->input(event);
    }

    void update(sf::RenderWindow &window, float deltaSec) {
        if (m_state) m_state->update(window, deltaSec);
    }

    void render() {
        if (m_state) m_state->render(m_window);
    }

    sf::RenderWindow &getWindow() { return m_window; }
};

#endif //OOP_STATEMANAGER_H
