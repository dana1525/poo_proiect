
#ifndef OOP_ENTITYMANAGER_H
#define OOP_ENTITYMANAGER_H

#include "../headers/Entity.h"
#include "Character.h"
#include <vector>
#include <map>
#include <string>
#include <memory>

typedef std::vector<std::shared_ptr<Entity>> EntityVec;
typedef std::map<std::string, EntityVec> EntityMap;

class EntityManager {
    EntityVec m_entities;
    EntityMap m_entityMap;
    EntityVec m_toAdd; ///waiting room
    static size_t m_totalEntities;
public:
    EntityManager() = default;

    void update();

    std::shared_ptr<Entity> addEntity(EntityTag tag, const sf::Vector2f &position);

    EntityVec &getEntities();  ///all the entities
    EntityVec getEntities(EntityTag &tag);  ///all the entities of some type
    ///returned???
    ///void collisions();
};

#endif //OOP_ENTITYMANAGER_H
