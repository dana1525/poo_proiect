
#ifndef OOP_CHARACTER_H
#define OOP_CHARACTER_H

#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Enums.h"
#include "Environment.h"

class Environment;

class Character : public Entity {
protected:
    ///sprites

    float m_speed;         ///< The speed of the character
    float m_jumpHeight;    ///< The maximum height the character can jump.
    float m_jumpForce;     ///< The force applied to the character when jumping.

public:
    Character(const size_t &id, const sf::Vector2f &position);

    Character(const Character &other);

    ~Character() override = default;

    Character &operator=(const Character &other);

    void print(std::ostream &out) const override;
    // Virtual function - allows a function defined in a base class to be overridden in a derived class.
    // Objects of derived classes will have different behavior when called via a pointer or reference of the base class type.

    friend std::ostream &operator<<(std::ostream &out, const Character &other);
    // Needs to be a friend function to be used outside the class.

    /**
     * @brief Method for handling input.
     *
     * Allows the characters to jump at the same time using the Space.
     */
    void controller();

    /**
    * @brief Abstract method for handling input.
    *
    * Implemented in the derived classes.
    */
    virtual void handleInput() = 0;

    /**
     * @brief Moves the character by a given distance.
     *
     * Updates the character's position based on the specified movement in the x and y directions.
     * @param dx The distance to move horizontally.
     * @param dy The distance to move vertically.
     */
    void move(float dx, float dy);

    ///sf::FloatRect getBounds() const;

    ///bool checkCollision();

    /**
     * @brief Makes the character jump.
     *
     * Applies a force to the character's vertical velocity to simulate a jump.
     */
    void jump();

};


#endif //OOP_CHARACTER_H
