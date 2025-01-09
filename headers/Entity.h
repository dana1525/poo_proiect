
#ifndef OOP_ENTITY_H
#define OOP_ENTITY_H

#include <iostream>
#include <memory>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>
#include "Enums.h"

/**
 * @class Entity
 * @brief Represents a generic entity in the game world.
 *
 * Serves as a base class for all entities in the game, such as characters, obstacles, and pickups.
 * It provides common functionality such as positioning, gravity application, and collision bounds checking.
 */
class Entity {
protected:
    EntityTag m_tag = EntityTag::Default;  ///< The type/category of the entity.
    size_t m_id = 0;                       ///< Unique identifier for the entity.
    sf::RectangleShape m_shape;            ///< SFML shape used to represent the entity visually.
    sf::Vector2f m_position;               ///< Position of the entity in the game.
    bool m_onGround = false;               ///< Attribute indicating if the entity is currently on the ground.
    float m_yvelocity = 0.0f;              ///< Vertical velocity of the entity (used for gravity).
    float m_gravity = 50.0f;               ///< The gravity strength affecting the entity.
    bool m_alive = true;                   ///< Attribute indicating if the entity is alive or destroyed.
public:
    Entity() = default;

    Entity(const size_t &id, const sf::Vector2f &position);

    Entity(const Entity &other) = default;

    EntityTag getMTag() const;

    const bool &getMAlive() const;

    const sf::Vector2f &getMPosition() const;

    const float &getMyvelocity() const;

    /**
     * @brief Draws the entity on the given window.
     *
     * This function renders the entity's shape onto the window.
     * @param window The SFML window where the entity will be drawn.
     */
    virtual void draw(sf::RenderWindow &window);

    /**
    * @brief Applies gravity to the entity.
    *
    * Updates the entity's vertical velocity and position based on gravity and elapsed time.
    * @param wHeight The height of the window, used to check if the entity is on the ground.
    * @param deltaSec The elapsed time since the last update, used to calculate gravity's effect.
    */
    void setOnGround(bool onGround);

    void setPosition(float x, float y);

    void setYvelocity();

    virtual void applyGravity(unsigned int wHeight, float deltaSec);

    void checkBounds(unsigned int wWidth, unsigned int wHeight);

    /**
     * @brief Destroys the entity, marking it as no longer alive.
     *
     * Sets m_alive to false, which effectively removes the entity from the game.
     */
    void destroy();

    virtual void print(std::ostream &out) const;

    friend std::ostream &operator<<(std::ostream &out, const Entity &other);

    virtual ~Entity() = default;

    sf::FloatRect getBounds() const;
};

#endif //OOP_ENTITY_H
