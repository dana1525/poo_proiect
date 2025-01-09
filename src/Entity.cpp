
#include "../headers/Entity.h"

Entity::Entity(const size_t &id, const sf::Vector2f &position)
        : m_tag(EntityTag::Default), m_id(id), m_position(position) {
    m_shape.setSize({40.f, 20.f});
    m_shape.setFillColor(sf::Color::Green);
    m_shape.setPosition(position);
}


EntityTag Entity::getMTag() const {
    return m_tag;
}

const bool &Entity::getMAlive() const {
    return m_alive;
}

const sf::Vector2f &Entity::getMPosition() const {
    return m_position;
}

const float &Entity::getMyvelocity() const {
    return m_yvelocity;
}

void Entity::draw(sf::RenderWindow &window) {
    window.draw(m_shape);
}

void Entity::destroy() {
    m_alive = false;
}

void Entity::setOnGround(bool onGround) {
    m_onGround = onGround;
}

void Entity::setPosition(float x, float y) {
    m_shape.setPosition({x, y});
}

void Entity::setYvelocity() {
    m_yvelocity = 0.0f;
}

void Entity::applyGravity(unsigned int wHeight, float deltaSec) {
    if (!m_onGround) {
        m_yvelocity += m_gravity * deltaSec;
        m_position.y += m_yvelocity * deltaSec;
    }
    if (m_position.y + m_shape.getSize().y >= (float) wHeight) {
        m_position.y = (float) wHeight - m_shape.getSize().y;
        m_yvelocity = 0.0f;
        m_onGround = true;
    }
    m_shape.setPosition(m_position);
}

void Entity::checkBounds(unsigned int wWidth, unsigned int wHeight) {
    sf::FloatRect bounds = m_shape.getGlobalBounds();
    if (bounds.left < 0)
        m_position.x = 0;
    else if (bounds.left + bounds.width > static_cast<float>(wWidth))
        m_position.x = (float) wWidth - bounds.width;
    if (bounds.top < 0)
        m_position.y = 0;
    else if (bounds.top + bounds.height > static_cast<float>(wHeight))
        m_position.y = (float) wHeight - bounds.height;

    m_shape.setPosition(m_position);
}

void Entity::print(std::ostream &out) const {
    out << "Tag: ";
    switch (m_tag) {
        case EntityTag::Default:
            out << "Default\n";
            break;
        case EntityTag::FireCharacter:
            out << "FireCharacter\n";
            break;
        case EntityTag::WaterCharacter:
            out << "WaterCharacter\n";
            break;
        case EntityTag::FireEnvironment:
            out << "FireEnvironment\n";
            break;
        case EntityTag::WaterEnvironment:
            out << "WaterEnvironment\n";
            break;
        case EntityTag::SlimeEnvironment:
            out << "SlimeEnvironment\n";
            break;
        case EntityTag::Pickup:
            out << "Pickup\n";
            break;
        case EntityTag::Wall:
            out << "Wall\n";
            break;
    }
    out << "Position: (" << m_position.x << ", " << m_position.y << ")\n";
}

std::ostream &operator<<(std::ostream &out, const Entity &other) {
    other.print(out);
    return out;
}

sf::FloatRect Entity::getBounds() const {
    return m_shape.getGlobalBounds();
}
