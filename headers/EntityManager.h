
#ifndef OOP_ENTITYMANAGER_H
#define OOP_ENTITYMANAGER_H

#include "../headers/Entity.h"
#include "Character.h"
#include "FireCharacter.h"
#include "WaterCharacter.h"
#include <vector>
#include <map>
#include <string>
#include <memory>
#include "Pickup.h"


/**
 * @class EntityManager
 * @brief Manages all entities in the game.
 *
 * This class is responsible for adding, updating, and retrieving entities.
 */

template<typename T>
class EntityManager {
    std::vector<std::shared_ptr<T>> m_entities;            ///< List of all entities in the game.
    std::vector<std::shared_ptr<T>> m_toAdd;               ///< Temporary storage for entities that are to be added.
    size_t m_totalEntities = 1;   ///< Keeps track of the total number of entities.

public:
    EntityManager() = default;

    /**
     * @brief Updates the vector of entities in the game.
     */
    void update() {
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

    /**
     * @brief Adds a new entity to the game.
     *
     * Creates a new entity of a specific type (determined by the EntityTag) and adds it to the temporary storage.
     *
     * @param tag The type of entity to add.
     * @param position The position where the entity should be placed.
     * @return A shared pointer to the newly added entity.
     */
    template<typename U>
    std::shared_ptr<T> addEntity(EntityTag tag, const sf::Vector2f &position) {
        std::shared_ptr<T> e = std::make_shared<U>(m_totalEntities++, position, tag);

//        if (tag == EntityTag::FireCharacter) {
//            e = std::make_shared<FireCharacter>(m_totalEntities++, position);
//        } else if (tag == EntityTag::WaterCharacter) {
//            e = std::make_shared<WaterCharacter>(m_totalEntities++, position);
//        } else if (tag == EntityTag::SlimeEnvironment || tag == EntityTag::WaterEnvironment ||
//                   tag == EntityTag::FireEnvironment || tag == EntityTag::Wall)
//            e = std::make_shared<Environment>(m_totalEntities++, position, tag);
//        else if (tag == EntityTag::Pickup) {
//            e = std::make_shared<Pickup>(m_totalEntities++, position);
//        } else {
//            e = std::make_shared<T>(m_totalEntities++, position);
//        }
        m_toAdd.push_back(e);
        return e;
    }

    /**
     * @brief Retrieves all entities.
     *
     * @return A reference to the vector containing all entities in the game.
     */
    std::vector<std::shared_ptr<T>> &getEntities() {
        return m_entities;
    }

    /**
    * @brief Retrieves all entities of a specific type.
    *
    * Filters the entities by their EntityTag and returns those that match the specified type.
    *
    * @param tag The type of entity to retrieve.
    * @return A vector containing all entities of the specified type.
    */
    std::vector<std::shared_ptr<T>> getEntities(EntityTag &tag) {
        std::vector<std::shared_ptr<T>> matchingEntities;
        for (const auto &m: m_entities)
            if (m->getMTag() == tag)
                matchingEntities.push_back(m);
        return matchingEntities;
    }
};

#endif //OOP_ENTITYMANAGER_H
