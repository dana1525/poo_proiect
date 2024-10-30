
#ifndef OOP_FIRECHARACTER_H
#define OOP_FIRECHARACTER_H
#include <SFML/Graphics.hpp>
#include "Character.h"

class FireCharacter : public Character {
private:
    sf::Color color;
public:
    FireCharacter(const sf::Vector2f& start_position)
    : Character(start_position) {
        shape.setFillColor(sf::Color::Red);
    };

    void handleInput();

    const bool walkOnFire() const{
        return true;
    };

    const bool walkOnWater() const{
        return false;
    };

    void print(std::ostream& out) const override;
};


#endif //OOP_FIRECHARACTER_H
