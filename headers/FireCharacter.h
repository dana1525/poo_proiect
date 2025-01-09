
#ifndef OOP_FIRECHARACTER_H
#define OOP_FIRECHARACTER_H

#include <SFML/Graphics.hpp>
#include "Character.h"

/**
 * @class FireCharacter
 * @brief Represents a fire-based character in the game.
 *
 * Inherits from the Character base class and provides fire-specific behavior
 * such as handling input or custom visual representation.
 */

class FireCharacter : public Character {
private:
    sf::Color color; ///< The color of the WaterCharacter
public:
    explicit FireCharacter(const size_t &id, const sf::Vector2f &position, EntityTag tag)
            : Character(id, position) {
        m_shape.setFillColor(sf::Color::Red);
        m_tag = tag;
    }

/**
     * @brief Handles input specific to the FireCharacter.
     */
    void handleInput() override;
};


#endif //OOP_FIRECHARACTER_H
