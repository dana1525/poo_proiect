
#ifndef OOP_WATERCHARACTER_H
#define OOP_WATERCHARACTER_H
#include <SFML/Graphics.hpp>
#include "Character.h"

class WaterCharacter : public Character {
private:
    sf::Color color;
public:
    explicit WaterCharacter(const sf::Vector2f& start_position)
            : Character(start_position) {
        shape.setFillColor(sf::Color::Blue);
    };

    void handleInput();

//    static bool walkOnFire() {
//        return false;
//    };
//
//    static bool walkOnWater() {
//        return true;
//    };

    void print(std::ostream& out) const override;
};


#endif //OOP_WATERCHARACTER_H
