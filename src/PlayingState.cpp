
#include "../headers/PlayingState.h"

void PlayingState::game_collisions() {
//    for (auto &e: m_entities.getEntities()) {
//        if (auto p = std::dynamic_pointer_cast<Pickup>(e)) {
//            for (auto &other: m_entities.getEntities()) {
//                if (e != other)
//                    p->collision(*other);
//            }
//        } else if (auto o = std::dynamic_pointer_cast<Environment>(e)) {
//            for (auto &other: m_entities.getEntities()) {
//                if (e != other) {
//                    o->destroyIfHarmful(*other);
//                }
//            }
//        }
//    }
    for (auto &c: m_characters.getEntities())
        for (auto &e: m_entities.getEntities())
            if (auto p = std::dynamic_pointer_cast<Pickup>(e))
                p->collision(*c);
            else if (auto o = std::dynamic_pointer_cast<Environment>(e))
                o->destroyIfHarmful(*c);
}

PlayingState::PlayingState()
        : m_entities(), m_characters() {
    m_characters.addEntity<FireCharacter>(EntityTag::FireCharacter, {100.f, 100.f});
    m_characters.addEntity<WaterCharacter>(EntityTag::WaterCharacter, {300.f, 300.f});
    m_entities.addEntity<Environment>(EntityTag::Wall, {10.f, 690.f});
    m_entities.addEntity<Environment>(EntityTag::FireEnvironment, {110.f, 690.f});
    m_entities.addEntity<Environment>(EntityTag::WaterEnvironment, {160.f, 690.f});
    m_entities.addEntity<Pickup>(EntityTag::Pickup, {600.f, 600.f});
}

void PlayingState::update(sf::RenderWindow &window, float deltaSec) {
    m_entities.update();
    m_characters.update();
//    for (auto &e: m_entities.getEntities()) {//to verify later if it's not a pickup item
//        if (auto character = std::dynamic_pointer_cast<Character>(e)) {
//            character->applyGravity(window.getSize().y, deltaSec);
//            character->checkBounds(window.getSize().x, window.getSize().y);
//        } else if (auto p = std::dynamic_pointer_cast<Pickup>(e))
//            p->applyGravity(window.getSize().y, deltaSec);
//    }

    for (auto &c: m_characters.getEntities()) {
        c->applyGravity(window.getSize().y, deltaSec);
        c->checkBounds(window.getSize().x, window.getSize().y);
    }
    for (auto &e: m_entities.getEntities()) //to verify later if it's not a pickup item
        if (auto p = std::dynamic_pointer_cast<Pickup>(e))
            p->applyGravity(window.getSize().y, deltaSec);
    game_collisions();
}

void PlayingState::input(sf::Event &event) {
    if (event.type == sf::Event::Closed)
        std::cerr << "closing";
    for (auto &c: m_characters.getEntities())
        c->controller();
}

void PlayingState::render(sf::RenderWindow &window) {
    window.clear();

    for (auto &e: m_entities.getEntities())
        if (auto p = std::dynamic_pointer_cast<Pickup>(e))
            p->draw(window);
        else e->draw(window);

    for (auto &c: m_characters.getEntities())
        c->draw(window);
    window.display();
}
