
#include "../headers/Entity.h"

Entity::Entity(const EntityTag &tag, const size_t &id, const sf::Vector2f &position)
        : m_tag(tag), m_id(id), m_position(position) {
    m_shape.setRadius(20.f);  // set the radius of the shape
    m_shape.setFillColor(sf::Color::Green);  // add color for visibility
    m_shape.setPosition(position);  // set the position
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

void Entity::draw(sf::RenderWindow &window) {
    window.draw(m_shape);
}

void Entity::destroy() {
    m_alive = false;
}

void Entity::applyGravity(unsigned int wHeight, float deltaSec) {
    if (!m_onGround) {
        m_yvelocity += m_gravity * deltaSec;
        m_position.y += m_yvelocity * deltaSec;
    }
    if (m_position.y + m_shape.getRadius() * 2 >= (float) wHeight) {
        m_position.y = (float) wHeight - m_shape.getRadius() * 2;
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
        case EntityTag::FireObstacle:
            out << "FireObstacle\n";
            break;
        case EntityTag::WaterObstacle:
            out << "WaterObstacle\n";
            break;
        case EntityTag::SlimeObstacle:
            out << "SlimeObstacle\n";
            break;
        case EntityTag::Pickup:
            out << "Pickup\n";
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