
#ifndef OOP_STARTGAMECOMMAND_H
#define OOP_STARTGAMECOMMAND_H

#include "Command.h"
#include "StateManager.h"
#include "PlayingState.h"

class StartGameCommand : public Command {
    StateManager &m_stateManager;

public:
    explicit StartGameCommand(StateManager &stateManager) : m_stateManager(stateManager) {};

    void execute() override {
        m_stateManager.setState(std::make_unique<PlayingState>());
    }
};

#endif //OOP_STARTGAMECOMMAND_H
