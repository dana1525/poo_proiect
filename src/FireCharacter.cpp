
#include "../headers/FireCharacter.h"
#include <SFML/Graphics.hpp>

void FireCharacter::handleInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        move(-1.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        move(1.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        jump();
}