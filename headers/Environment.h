
#ifndef OOP_ENVIRONMENT_H
#define OOP_ENVIRONMENT_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Character.h"
#include <memory>

/**
* @class Environment
* @brief Represents the environment in the game.
*
* Characters can interact with it and can be affected or not.
*/

class Environment : public Entity {
public:
    Environment(const size_t &id, const sf::Vector2f &position, EntityTag tag);

    ~Environment() override = default;

    /**
     * @brief Destroys the entity if there was an interaction with a harmful obstacle.
     * @param entity The entity interacting with the environment.
     */
    void destroyIfHarmful(Entity &entity); //should be changed to a character??

};


#endif //OOP_ENVIRONMENT_H
