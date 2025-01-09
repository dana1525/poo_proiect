
#ifndef OOP_COMMAND_H
#define OOP_COMMAND_H

class Command {
public:
    virtual ~Command() = default;

    virtual void execute() = 0;
};

#endif //OOP_COMMAND_H
