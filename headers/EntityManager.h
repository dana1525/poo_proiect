
#ifndef OOP_ENTITYMANAGER_H
#define OOP_ENTITYMANAGER_H

#include "../headers/Entity.h"
#include "Character.h"
#include <vector>
#include <map>
#include <string>
#include <memory>

/// Type alias for a vector of shared pointers to Entity objects.
typedef std::vector<std::shared_ptr<Entity>> EntityVec;

/// Type alias for a map that groups entities.
typedef std::map<std::string, EntityVec> EntityMap;


/**
 * @class EntityManager
 * @brief Manages all entities in the game.
 *
 * This class is responsible for adding, updating, and retrieving entities.
 */

class EntityManager {
    EntityVec m_entities;            ///< List of all entities in the game.
    EntityMap m_entityMap;           ///< Map that categorizes entities.
    EntityVec m_toAdd;               ///< Temporary storage for entities that are to be added.
    static size_t m_totalEntities;   ///< Keeps track of the total number of entities.
public:
    EntityManager() = default;

    /**
     * @brief Updates the vector of entities in the game.
     */
    void update();

    /**
     * @brief Adds a new entity to the game.
     *
     * Creates a new entity of a specific type (determined by the EntityTag) and adds it to the temporary storage.
     *
     * @param tag The type of entity to add.
     * @param position The position where the entity should be placed.
     * @return A shared pointer to the newly added entity.
     */
    std::shared_ptr<Entity> addEntity(EntityTag tag, const sf::Vector2f &position);

    /**
     * @brief Retrieves all entities.
     *
     * @return A reference to the vector containing all entities in the game.
     */
    EntityVec &getEntities();

    /**
    * @brief Retrieves all entities of a specific type.
    *
    * Filters the entities by their EntityTag and returns those that match the specified type.
    *
    * @param tag The type of entity to retrieve.
    * @return A vector containing all entities of the specified type.
    */
    EntityVec getEntities(EntityTag &tag);


    ///returned???
    ///void collisions();
};

#endif //OOP_ENTITYMANAGER_H
