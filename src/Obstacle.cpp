
#include "../headers/Obstacle.h"
#include <SFML/Graphics.hpp>

Obstacle::Obstacle(const size_t &id, const sf::Vector2f &position, EntityTag tag)
        : Entity(id, position) {
    m_shape.setSize({50.f, 10.f});
    m_tag = tag;
    //m_shape.setPointCount(4);
    //m_shape.setPosition(position);
    if (m_tag == EntityTag::FireObstacle)
        m_shape.setFillColor(sf::Color::Red);
    else if (m_tag == EntityTag::WaterObstacle)
        m_shape.setFillColor(sf::Color::Blue);
    else if (m_tag == EntityTag::SlimeObstacle)
        m_shape.setFillColor(sf::Color::Green);
}


void Obstacle::destroyIfHarmful(Entity &entity) {
    if (this->getBounds().intersects(entity.getBounds())) {
        if (m_tag == EntityTag::WaterObstacle && entity.getMTag() == EntityTag::FireCharacter) {
            entity.destroy();
            //menu window or restart the game?
        }
        if (m_tag == EntityTag::FireObstacle && entity.getMTag() == EntityTag::WaterCharacter) {
            entity.destroy();
        }
        if (m_tag == EntityTag::SlimeObstacle &&
            ((entity.getMTag() == EntityTag::FireCharacter) || (entity.getMTag() == EntityTag::WaterCharacter))) {
            entity.destroy();
        }
    }
}