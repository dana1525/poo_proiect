
#include "../headers/EntityManager.h"
#include "../headers/FireCharacter.h"
#include "../headers/WaterCharacter.h"
#include "../headers/Obstacle.h"
#include "../headers/Pickup.h"
#include <memory>

size_t EntityManager::m_totalEntities = 1;

std::shared_ptr<Entity> EntityManager::addEntity(EntityTag tag, const sf::Vector2f &position) {
//    std::shared_ptr<Entity> e;

    if (tag == EntityTag::FireCharacter) {
        auto e = std::make_shared<FireCharacter>(m_totalEntities++, position);
        m_toAdd.push_back(e);
        return e;
    } else if (tag == EntityTag::WaterCharacter) {
        auto e = std::make_shared<WaterCharacter>(m_totalEntities++, position);
        m_toAdd.push_back(e);
        return e;
    } else if (tag == EntityTag::SlimeObstacle) {
        std::cout << "Obstacle made: " << m_totalEntities << "\n";;
        auto e = std::make_shared<Obstacle>(m_totalEntities++, position, tag);
        m_toAdd.push_back(e);
        return e;
    } else if (tag == EntityTag::Pickup) {
        auto e = std::make_shared<Pickup>(m_totalEntities++, position);
        m_toAdd.push_back(e);
        return e;
    } else {
        auto e = std::make_shared<Entity>(m_totalEntities++, position);
        m_toAdd.push_back(e);
        return e;
    }
}

void EntityManager::update() {
    //also add to the vector inside the map, with the tag as a key
    for (const auto &e: m_toAdd) {
        m_entities.push_back(e);
        ////??m_entityMap[e->getMTag()].push_back(e);
    }
    ///remove entity from m_entities
    for (auto e = m_entities.begin(); e != m_entities.end();) {
        if (!e->get()->getMAlive())
            e = m_entities.erase(e);
        else e++;
    }
    ///removes from the beginning to the end of the vector
    /*for (auto &[tag, entities]: m_entityMap) {
        entities.erase(
                std::remove_if(entities.begin(), entities.end(),
                               [](const std::shared_ptr<Entity> &e) { return !e->getMAlive(); }),
                entities.end()
        );
    }*/
    m_toAdd.clear();
}

EntityVec &EntityManager::getEntities() {
    return m_entities;
}

EntityVec EntityManager::getEntities(EntityTag &tag) {
    EntityVec matchingEntities;
    for (const auto &m: m_entities)
        if (m->getMTag() == tag)
            matchingEntities.push_back(m);
    return matchingEntities; ///i think i should do it for the map too
}