
#ifndef OOP_ENTITY_H
#define OOP_ENTITY_H

#include <iostream>
#include <memory>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>
#include "Enums.h"

///virtual?????

class Entity {
protected:
    EntityTag m_tag = EntityTag::Default;
    size_t m_id = 0;
    sf::CircleShape m_shape; ///??
    sf::Vector2f m_position;
    bool m_onGround = false;
    float m_yvelocity = 0.0f; //viteza pe y
    float m_gravity = 50.0f;  //constanta gravitationala
    bool m_alive = true;
public:
    Entity() = default;

    Entity(const EntityTag &tag, const size_t &id, const sf::Vector2f &position);

    Entity(const Entity &other) = default;

    EntityTag getMTag() const;

    const bool &getMAlive() const;

    const sf::Vector2f &getMPosition() const;

    void draw(sf::RenderWindow &window);

    void applyGravity(unsigned int wHeight, float deltaSec);

    void checkBounds(unsigned int wWidth, unsigned int wHeight);

    //void destroy();

    virtual void print(std::ostream &out) const;

    friend std::ostream &operator<<(std::ostream &out, const Entity &other);

    virtual ~Entity() = default;
};

#endif //OOP_ENTITY_H
