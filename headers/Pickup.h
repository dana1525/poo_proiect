
#ifndef OOP_PICKUP_H
#define OOP_PICKUP_H

#include "Entity.h"

class Pickup : public Entity {
private:
    bool m_collected;
public:
    Pickup(const size_t &id, const sf::Vector2f &position);

    void collect();

    void draw(sf::RenderWindow &window) override;

    void collision(Entity &entity);
};

#endif //OOP_PICKUP_H
