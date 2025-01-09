
#include "../headers/Pickup.h"

Pickup::Pickup(const size_t &id, const sf::Vector2f &position, EntityTag tag)
        : Entity(id, position), m_collected(false) {
    m_shape.setSize({20.f, 20.f});
    //m_shape.setPointCount(4);
    m_tag = tag;
    m_shape.setFillColor(sf::Color::Magenta);
}

void Pickup::collect() {
    if (!m_collected) {
        m_collected = true;
        destroy();
    }
}

void Pickup::draw(sf::RenderWindow &window) {
    if (!m_collected)
        window.draw(m_shape);
}

void Pickup::collision(const Entity &entity) {
    if (entity.getMTag() == EntityTag::FireCharacter ||
        entity.getMTag() == EntityTag::WaterCharacter)
        if (entity.getBounds().intersects(this->getBounds()))
            collect();
}


//override applyGravity
//so the pickup levitates
void Pickup::applyGravity(unsigned int wHeight, float deltaSec) {
    if (!m_onGround) {
        m_yvelocity += m_gravity * deltaSec;
        m_position.y += m_yvelocity * deltaSec;
    }
    if (m_position.y + m_shape.getSize().y >= (float) wHeight - 20) {
        m_position.y = (float) wHeight - m_shape.getSize().y - 20;
        m_yvelocity = 0.0f;
        m_onGround = true;
    }
    m_shape.setPosition(m_position);
}