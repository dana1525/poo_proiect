
#ifndef OOP_OBSTACLE_H
#define OOP_OBSTACLE_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Character.h"

/**
* @class Obstacle
* @brief Represents an obstacle in the game.
*
* Obstacles can interact with other entities, causing harm.
*/

class Obstacle : public Entity {
public:
    Obstacle(const EntityTag &tag, const size_t &id, const sf::Vector2f &position);

    ~Obstacle() override = default;

    ///friend std::ostream& operator<<(std::ostream& out, const Obstacle& ob);

    /**
     * @brief Destroys the entity if there was an interaction with a harmful obstacle.
     * @param entity The entity interacting with the obstacle.
     */
    void destroyIfHarmful(Entity &entity); //should be changed to a character??
};


#endif //OOP_OBSTACLE_H
