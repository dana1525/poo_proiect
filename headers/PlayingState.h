
#ifndef OOP_PLAYINGSTATE_H
#define OOP_PLAYINGSTATE_H

#include "EntityManager.h"
#include "State.h"
#include "StateManager.h"
#include "FireCharacter.h"
#include "WaterCharacter.h"
#include "Entity.h"

class PlayingState : public State {
protected:
    EntityManager<Entity> m_entities;
    std::shared_ptr<FireCharacter> m_fire;
    std::shared_ptr<WaterCharacter> m_water;
public:
    explicit PlayingState();

    void update(sf::RenderWindow &window, float deltaSec) override;

    void input(sf::Event &event) override;

    void render(sf::RenderWindow &window) override;

    void game_collisions();
};


#endif //OOP_PLAYINGSTATE_H
