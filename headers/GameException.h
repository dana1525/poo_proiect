
#ifndef OOP_GAMEEXCEPTION_H
#define OOP_GAMEEXCEPTION_H

#include <exception>
#include <string>
#include <utility>

/**
 * @class GameException
 * @brief Base class for custom exceptions in the game.
 *
 * Inherits from std::exception and includes custom error messages.
 */

class GameException : public std::exception {
protected:
    std::string m_message; ///< The error message associated with the exception.
public:
    explicit GameException(std::string message) : m_message(std::move(message)) {}

    /**
     * @brief Retrieves the error message.
     * @return A string representing the error message.
     * @note The [[nodiscard]] attribute indicates the result should not be ignored.
     */
    [[nodiscard]] const char *what() const noexcept override {
        return m_message.c_str(); //string -> pointer const char*
    }
};


/**
 * @class InitializationException
 * @brief Exception for initialization-related errors.
 *
 * Derived from GameException and used to report errors that occur during initialization.
 */
class InitializationException : public GameException {
public:
    explicit InitializationException(const std::string &detail)
            : GameException("Initialization Error: " + detail) {}
};


/**
 * @class LogicException
 * @brief Exception for logical errors in the game's operation.
 *
 * Derived from GameException and used to report logical inconsistencies.
 */
class LogicException : public GameException {
public:
    explicit LogicException(const std::string &detail)
            : GameException("Logic Error: " + detail) {}
};


/**
 * @class GeneralException
 * @brief General-purpose exception for uncategorized errors.
 *
 * Derived from GameException and used to report errors that do not fall into specific categories.
 */
class GeneralException : public GameException {
public:
    explicit GeneralException(const std::string &detail)
            : GameException("General Exception: " + detail) {}
};

#endif //OOP_GAMEEXCEPTION_H
