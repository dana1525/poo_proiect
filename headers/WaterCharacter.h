
#ifndef OOP_WATERCHARACTER_H
#define OOP_WATERCHARACTER_H

#include <SFML/Graphics.hpp>
#include "Character.h"

/**
 * @class WaterCharacter
 * @brief Represents a water-based character in the game.
 *
 * Inherits from the Character base class and provides water-specific behavior
 * such as handling input or custom visual representation.
 */

class WaterCharacter : public Character {
private:
    sf::Color color; ///< The color of the WaterCharacter
public:
    explicit WaterCharacter(const size_t &id, const sf::Vector2f &position, EntityTag tag)
            : Character(id, position) {
        m_shape.setFillColor(sf::Color::Blue);
        m_tag = tag;
    }

    /**
     * @brief Handles input specific to the WaterCharacter.
     */
    void handleInput() override;

    ///void print(std::ostream& out) const override;
};


#endif //OOP_WATERCHARACTER_H
