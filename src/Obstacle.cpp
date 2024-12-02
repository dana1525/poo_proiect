
#include "../headers/Obstacle.h"
#include <SFML/Graphics.hpp>

Obstacle::Obstacle(const EntityTag &tag, const size_t &id, const sf::Vector2f &position)
        : Entity(tag, id, position) {
    m_shape.setRadius(10.f);
    m_shape.setPointCount(4);
    //m_shape.setPosition(position);
    if (m_tag == EntityTag::FireObstacle)
        m_shape.setFillColor(sf::Color::Red);
    else if (m_tag == EntityTag::WaterObstacle)
        m_shape.setFillColor(sf::Color::Blue);
    else if (m_tag == EntityTag::SlimeObstacle)
        m_shape.setFillColor(sf::Color::Green);
}


void Obstacle::destroyIfHarmful(Entity &entity) {
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