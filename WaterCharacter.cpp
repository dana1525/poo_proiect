
#include "WaterCharacter.h"

void WaterCharacter::handleInput(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        move(-1.f,0.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        move(1.f,0.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        jump();
}

/*void WaterCharacter::handleInput(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        move(0.f,-1.f);
    float horizontalDir = 0.f;
    bool left = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
    bool right = sf::Keyboard::isKeyPressed(sf::Keyboard::D);

    if(left && right) { //in acelasi timp
        if (lastKeyPressed == sf::Keyboard::A)
            horizontalDir -= speed;
        else if (lastKeyPressed == sf::Keyboard::D)
            horizontalDir += speed;
    }
    else
        if(left)
        {
            horizontalDir -= speed; lastKeyPressed = sf::Keyboard::A;
        }
        else
            if(right){
                horizontalDir += speed; lastKeyPressed = sf::Keyboard::D;
            }
    move(horizontalDir, 0.f);
}*/

/*void WaterCharacter::handleInput(sf::Event event){
    if(event.key.code == sf::Keyboard::A)
        move(-1.f,0.f);
    if(event.key.code == sf::Keyboard::D)
        move(1.f,0.f);
    if(event.key.code == sf::Keyboard::W)
        move(0.f,-1.f);
    if(event.key.code == sf::Keyboard::S)
        move(0.f,1.f);
}*/
///nu functioneaza, deoarece imi detecteaza o singura apasare de tasta ca eveniment la un moment dat
///prin urmare, nu pot sa controlez ambele obiecte in acelasi timp


void WaterCharacter::print(std::ostream& out) const{
    out << "Character: water\n";
    Character::print(out);
}