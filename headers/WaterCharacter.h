
#ifndef OOP_WATERCHARACTER_H
#define OOP_WATERCHARACTER_H

#include <SFML/Graphics.hpp>
#include "Character.h"

class WaterCharacter : public Character {
private:
    sf::Color color;
public:
    explicit WaterCharacter(const size_t &id, const sf::Vector2f &position)
            : Character(EntityTag::WaterCharacter, id, position) {
        m_shape.setFillColor(sf::Color::Blue);
    };

    void handleInput() override;

//    void walkOnFire();
//
//    void walkOnWater();

    ///void print(std::ostream& out) const override;
};


#endif //OOP_WATERCHARACTER_H
