
#include "../headers/FireCharacter.h"
#include <SFML/Graphics.hpp>

void FireCharacter::handleInput(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) //daca s-a apasat o tasta si acea tasta este Left
        move(-1.f,0.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        move(1.f,0.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        jump();
}

void FireCharacter::print(std::ostream& out) const{
    out << "Character: fire\n";
    Character::print(out);
}