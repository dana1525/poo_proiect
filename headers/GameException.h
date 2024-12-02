
#ifndef OOP_GAMEEXCEPTION_H
#define OOP_GAMEEXCEPTION_H

#include <exception>
#include <string>
#include <utility>

class GameException : public std::exception {
protected:
    std::string m_message;
public:
    explicit GameException(std::string message) : m_message(std::move(message)) {}

    [[nodiscard]] const char *what() const noexcept override {
        return m_message.c_str(); //string -> pointer const char*
        //[[nodiscard]] - the caller must use the result
    }
};

class InitializationException : public GameException {
public:
    explicit InitializationException(const std::string &detail)
            : GameException("Initialization Error: " + detail) {}
};

class LogicException : public GameException {
public:
    explicit LogicException(const std::string &detail)
            : GameException("Logic Error: " + detail) {}
};

class GeneralException : public GameException {
public:
    explicit GeneralException(const std::string &detail)
            : GameException("General Exception: " + detail) {}
};

#endif //OOP_GAMEEXCEPTION_H
