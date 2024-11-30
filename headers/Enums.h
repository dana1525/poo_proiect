
#ifndef OOP_ENUMS_H
#define OOP_ENUMS_H

enum class EntityTag {
    Default,
    FireCharacter,
    WaterCharacter,
    FireObstacle,
    WaterObstacle,
    SlimeObstacle,
    Pickup
};

enum class GameState {
    MENU,
    PLAYING,
    //PAUSE,
    EXIT
};


#endif //OOP_ENUMS_H
