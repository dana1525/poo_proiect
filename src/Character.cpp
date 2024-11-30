
#include "../headers/Character.h"
#include <SFML/Graphics.hpp>

Character::Character(const EntityTag &tag, const size_t &id, const sf::Vector2f &position)
        : Entity(tag, id, position), m_speed(25.f), m_jumpHeight(10.f), m_jumpForce(50.0f) {
    m_shape.setRadius(15.f);
    m_shape.setPosition(position);
}

Character::Character(const Character &other)
        : Entity(other.m_tag, other.m_id, other.m_position),
          m_speed(other.m_speed), m_jumpHeight(other.m_jumpHeight), m_jumpForce(other.m_jumpForce) {}

Character &Character::operator=(const Character &other) {
    ///sprite-uri
    if (this != &other) {
        m_tag = other.m_tag;
        m_position = other.m_position;
        m_onGround = other.m_onGround;
        m_yvelocity = other.m_yvelocity;
        m_gravity = other.m_gravity;
        m_alive = other.m_alive;
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

///const sf::Vector2f& Character::getPosition() const {
///    return position;
///}


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

