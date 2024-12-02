
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
    FireObstacle,       ///< Represents a fire obstacle.
    WaterObstacle,      ///< Represents a water obstacle.
    SlimeObstacle,      ///< Represents a slime obstacle.
    Pickup              ///< Represents a pickup object.
};

//to change??
enum class GameState {
    MENU,
    PLAYING,
    //PAUSE,
    EXIT
};


#endif //OOP_ENUMS_H
