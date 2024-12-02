
#ifndef OOP_OBSTACLE_H
#define OOP_OBSTACLE_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Character.h"


class Obstacle : public Entity {
public:
    Obstacle(const EntityTag &tag, const size_t &id, const sf::Vector2f &position);

    ~Obstacle() override = default;

    ///friend std::ostream& operator<<(std::ostream& out, const Obstacle& ob);


    //void destroyIfHarmful(Entity &entity);
};


#endif //OOP_OBSTACLE_H
