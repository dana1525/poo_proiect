
#ifndef OOP_LEVELSCOMMAND_H
#define OOP_LEVELSCOMMAND_H

#include <iostream>
#include "Command.h"

class LevelsCommand : public Command {
public:
    void execute() override {
        std::cout << "levels menu selected";
    }
};

#endif //OOP_LEVELSCOMMAND_H
