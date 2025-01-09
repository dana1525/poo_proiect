
#ifndef OOP_MENUSTATE_H
#define OOP_MENUSTATE_H

#include "State.h"
#include "Menu.h"
#include "StateManager.h"
#include "PlayingState.h"
#include "StartGameCommand.h"
#include "ExitGameCommand.h"
#include "LevelsCommand.h"

class MenuState : public State {
    Menu m_menu;
    StateManager &m_stateManager;
public:
    MenuState(unsigned int wWidth, unsigned int wHeight, StateManager &stateManager) :
            m_menu(wWidth, wHeight), m_stateManager(stateManager) {
        m_menu.addCommand(std::make_shared<StartGameCommand>(m_stateManager));
        m_menu.addCommand(std::make_shared<LevelsCommand>());
        m_menu.addCommand(std::make_shared<ExitGameCommand>(m_stateManager.getWindow()));
    };

    void update(sf::RenderWindow &window, float deltaSec) override {
        if (window.getSize().x < 1 || deltaSec < 0.0f) {
            std::cerr << "error";
        }
    }

    void input(sf::Event &event) override;

    void render(sf::RenderWindow &window) override;
};


#endif //OOP_MENUSTATE_H
