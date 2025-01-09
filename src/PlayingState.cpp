
#include "../headers/PlayingState.h"

void PlayingState::game_collisions() {
    for (auto &e: m_entities.getEntities()) {
        if (auto p = std::dynamic_pointer_cast<Pickup>(e)) {
            for (auto &other: m_entities.getEntities()) {
                if (e != other)
                    p->collision(*other);
            }
        } else if (auto o = std::dynamic_pointer_cast<Environment>(e)) {
            for (auto &other: m_entities.getEntities()) {
                if (e != other) {
//                    if (auto character = std::dynamic_pointer_cast<Character>(e))
//                        character->stayOnWall(*o, m_window.getSize().y, deltaSec * 3);
                    o->destroyIfHarmful(*other);
                }
            }
        }
    }
}

PlayingState::PlayingState()
        : m_entities() {
    m_entities.addEntity<FireCharacter>(EntityTag::FireCharacter, {100.f, 100.f});
    m_entities.addEntity<WaterCharacter>(EntityTag::WaterCharacter, {300.f, 300.f});
    m_entities.addEntity<Environment>(EntityTag::Wall, {10.f, 690.f});
    m_entities.addEntity<Environment>(EntityTag::FireEnvironment, {110.f, 690.f});
    m_entities.addEntity<Environment>(EntityTag::WaterEnvironment, {160.f, 690.f});
    m_entities.addEntity<Pickup>(EntityTag::Pickup, {600.f, 600.f});
}

void PlayingState::update(sf::RenderWindow &window, float deltaSec) {
    m_entities.update();
    for (auto &e: m_entities.getEntities()) {//to verify later if it's not a pickup item
        if (auto character = std::dynamic_pointer_cast<Character>(e)) {
            character->applyGravity(window.getSize().y, deltaSec);
            character->checkBounds(window.getSize().x, window.getSize().y);
        } else if (auto p = std::dynamic_pointer_cast<Pickup>(e))
            p->applyGravity(window.getSize().y, deltaSec);
    }
    game_collisions();
}

void PlayingState::input(sf::Event &event) {
    if (event.type == sf::Event::Closed)
        std::cerr << "closing";
    for (auto &e: m_entities.getEntities())
        if (auto character = std::dynamic_pointer_cast<Character>(e))
            character->controller();
}

void PlayingState::render(sf::RenderWindow &window) {
    window.clear();

    //players' positions - in every level a different one
    for (auto &e: m_entities.getEntities())
        if (auto p = std::dynamic_pointer_cast<Pickup>(e))
            p->draw(window);
        else e->draw(window);

    window.display();
}
