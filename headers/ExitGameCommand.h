
#ifndef OOP_EXITGAMECOMMAND_H
#define OOP_EXITGAMECOMMAND_H

#include <SFML/Graphics.hpp>
#include "Command.h"

class ExitGameCommand : public Command {
    sf::RenderWindow &m_window;
public:
    explicit ExitGameCommand(sf::RenderWindow &window) : m_window(window) {}

    void execute() override {
        m_window.close();
    }
};

#endif //OOP_EXITGAMECOMMAND_H
