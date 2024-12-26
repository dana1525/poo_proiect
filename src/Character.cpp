
#include "../headers/Character.h"
#include <SFML/Graphics.hpp>

Character::Character(const size_t &id, const sf::Vector2f &position)
        : Entity(id, position), m_speed(25.f), m_jumpHeight(10.f), m_jumpForce(50.0f) {
    //m_shape.setRadius(15.f);
    m_shape.setSize({20.f, 30.f});
    m_shape.setPosition(position);
}

//copy the tag
Character::Character(const Character &other)
        : Entity(other.m_id, other.m_position),
          m_speed(other.m_speed), m_jumpHeight(other.m_jumpHeight), m_jumpForce(other.m_jumpForce) {}

Character &Character::operator=(const Character &other) {
    ///sprites
    if (this != &other) {
        Entity::operator=(other);
        m_tag = other.m_tag;
        m_shape = other.m_shape;
        m_speed = other.m_speed;
        m_jumpHeight = other.m_jumpHeight;
        m_jumpForce = other.m_jumpForce;
    }
    return *this;
}

void Character::print(std::ostream &out) const {
    Entity::print(out);
    out << "Speed: " << m_speed << "\n";
}

std::ostream &operator<<(std::ostream &out, const Character &character) {
    character.print(out);
    return out;
}

void Character::move(float dx, float dy) {
    m_position.x += dx * m_speed;
    m_position.y += dy * m_speed;
    m_shape.setPosition(m_position);
}

void Character::jump() {
    if (m_onGround) {
        m_yvelocity = -m_jumpForce;
        m_onGround = false;
    }
}

void Character::controller() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        jump();
    handleInput();
}