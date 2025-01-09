
#ifndef OOP_ENUMS_H
#define OOP_ENUMS_H

/**
 * @enum EntityTag
 * @brief Represents the different types of entities in the game.
 *
 * Each entity is assigned a tag to categorize it, which helps in managing.
 */

enum class EntityTag {
    Default,            ///< Default entity tag, used as a fallback or uninitialized state.
    FireCharacter,      ///< Represents a fire character.
    WaterCharacter,     ///< Represents a water character.
    FireEnvironment,       ///< Represents a fire obstacle.
    WaterEnvironment,      ///< Represents a water obstacle.
    SlimeEnvironment,      ///< Represents a slime obstacle.
    Wall,
    Pickup              ///< Represents a pickup object.
};

#endif //OOP_ENUMS_H
