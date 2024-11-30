
#ifndef OOP_FIRECHARACTER_H
#define OOP_FIRECHARACTER_H

#include <SFML/Graphics.hpp>
#include "Character.h"

class FireCharacter : public Character {
private:
    sf::Color color;
public:
    explicit FireCharacter(const size_t &id, const sf::Vector2f &position)
            : Character(EntityTag::FireCharacter, id, position) {
        m_shape.setFillColor(sf::Color::Red);
    };

    void handleInput() override;

//    void walkOnFire();
//
//    void walkOnWater();

};


#endif //OOP_FIRECHARACTER_H
