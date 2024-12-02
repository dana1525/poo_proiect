
#include "../headers/Pickup.h"

Pickup::Pickup(const size_t &id, const sf::Vector2f &position)
        : Entity(EntityTag::Pickup, id, position), m_collected(false) {
    m_shape.setRadius(5.f);
    m_shape.setPointCount(4);
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

//override applyGravity??