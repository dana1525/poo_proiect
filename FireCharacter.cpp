
#include "FireCharacter.h"

void FireCharacter::handleInput(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        move(-1.f,0.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        move(1.f,0.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        move(0.f,-1.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        move(0.f,1.f);
}

void FireCharacter::print(std::ostream& out) const{
    out << "Character: fire\n";
    Character::print(out);
}