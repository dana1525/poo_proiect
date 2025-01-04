
#include "../headers/WaterCharacter.h"
#include <SFML/Graphics.hpp>

void WaterCharacter::handleInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        move(-1.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        move(1.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        jump();
}