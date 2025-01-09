
#ifndef OOP_PICKUP_H
#define OOP_PICKUP_H

#include "Entity.h"
#include "Character.h"

/**
 * @class Pickup
 * @brief Represents an object that can be collected in the game.
 */

class Pickup : public Entity {
private:
    bool m_collected;
public:
    Pickup(const size_t &id, const sf::Vector2f &position, EntityTag tag);

    /**
     * @brief Marks the Pickup as collected and triggers its destruction.
     */
    void collect();

    /**
     * @brief Draws the Pickup to the specified window, if it was not collected.
     * @param window Reference to the SFML RenderWindow where the Pickup should be drawn.
     */
    void draw(sf::RenderWindow &window) override;

    /**
     * @brief Handles collision with another entity.
     * @param entity The entity involved in the collision.
     */
    void collision(const Character &character);

    void applyGravity(unsigned int wHeight, float deltaSec) override;
};

#endif //OOP_PICKUP_H
