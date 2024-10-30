
#include "WaterCharacter.h"



void WaterCharacter::handleInput(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        move(-1.f,0.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        move(1.f,0.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        move(0.f,-1.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        move(0.f,1.f);
}

void WaterCharacter::print(std::ostream& out) const{
    out << "Character: water\n";
    Character::print(out);
}