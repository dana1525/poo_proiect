
#include "../headers/Environment.h"
#include <SFML/Graphics.hpp>

Environment::Environment(const size_t &id, const sf::Vector2f &position, EntityTag tag)
        : Entity(id, position) {
    m_shape.setSize({50.f, 10.f});
    m_tag = tag;
    m_onGround = true;
    //m_shape.setPointCount(4);
    //m_shape.setPosition(position);
    if (m_tag == EntityTag::FireEnvironment)
        m_shape.setFillColor(sf::Color::Red);
    else if (m_tag == EntityTag::WaterEnvironment)
        m_shape.setFillColor(sf::Color::Blue);
    else if (m_tag == EntityTag::SlimeEnvironment)
        m_shape.setFillColor(sf::Color::Green);
    else if (m_tag == EntityTag::Wall) {
        m_shape.setFillColor(sf::Color::White);
        m_shape.setSize({100.f, 10.f});
    }
}


void Environment::destroyIfHarmful(Character &character) {
    //entity.setOnGround(false);
//    if (m_position.y < entity.getMPosition().y + entity.getBounds().height &&
//        entity.getMPosition().y < m_position.y + getBounds().height &&
//        m_position.x < entity.getMPosition().x + entity.getBounds().width &&
//        entity.getMPosition().x < m_position.x + getBounds().width
//            ) {
//        entity.setYvelocity();
//        entity.setOnGround(true);
//        entity.setPosition(entity.getMPosition().x, m_position.y);
//    }
    if (this->getBounds().intersects(character.getBounds())) {
        if (m_tag == EntityTag::Wall) {
            if (character.getMPosition().y + character.getBounds().height >= m_position.y &&
                character.getMPosition().y <= m_position.y + getBounds().height) {
                character.setOnGround(true);
                character.setPosition(character.getMPosition().x, m_position.y - character.getBounds().height);

                if (character.getMyvelocity() > 0) {
                    character.setYvelocity();
                }
            }
        }
    }

    if (this->getBounds().intersects(character.getBounds())) {
        if (m_tag == EntityTag::WaterEnvironment && character.getMTag() == EntityTag::FireCharacter) {
            character.destroy();
            //menu window or restart the game?
        }
        if (m_tag == EntityTag::FireEnvironment && character.getMTag() == EntityTag::WaterCharacter) {
            character.destroy();
        }
        if (m_tag == EntityTag::SlimeEnvironment &&
            ((character.getMTag() == EntityTag::FireCharacter) ||
             (character.getMTag() == EntityTag::WaterCharacter))) {
            character.destroy();
        }
    }
}