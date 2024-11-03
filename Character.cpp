
#include "Character.h"
#include <SFML/Graphics.hpp>

Character::Character(sf::Vector2f start_position)
    : position(start_position),
    speed(25.f), jumpHeight(10.f), onGround(true){
    shape.setRadius(15.f);
    shape.setPosition(position);
}

Character::Character(const Character &other)
    : position(other.position), speed(other.speed), jumpHeight(other.jumpHeight), onGround(other.onGround), shape(other.shape){}

Character& Character::operator=(const Character& other){
    ///de umblat la el cand adaug sprite-uri
    if(this != &other)
    {
        position = other.position;
        speed = other.speed;
        jumpHeight = other.jumpHeight;
        onGround = other.onGround;
        shape = other.shape;
    }
    return *this;
}

void Character::print(std::ostream& out) const{
    out << "Position: (" << position.x << ", " << position.y << ")\n";
    out << "Speed: " << speed << "\n";
}

std::ostream& operator<<(std::ostream& out, const Character& character){
    character.print(out);
    return out;
}

///const sf::Vector2f& Character::getPosition() const {
///    return position;
///}

void Character::draw(sf::RenderWindow& window){
    window.draw(shape);
}

void Character::move(float dx, float dy){
    position.x += dx * speed;
    position.y += dy * speed;
    shape.setPosition(position);
}

void Character::checkBounds(unsigned int wWidth, unsigned int wHeight){
    sf::FloatRect bounds = shape.getGlobalBounds();
    if(bounds.left < 0)
        position.x = 0;
    else
        if(bounds.left+bounds.width > (float)wWidth)
            position.x = (float)wWidth - bounds.width;
    if(bounds.top < 0)
        position.y = 0;
    else
        if(bounds.top+bounds.height > (float)wHeight)
            position.y = (float)wHeight - bounds.height;

    shape.setPosition(position);
}

/*void Character::jump(){
    if(onGround)
    {
        verticalSpeed = jumpForce;
        onGround = false;
    }
}
*/
/*
void Character::applyGravity(unsigned int wHeight) {
    if(!onGround) //aplic gravitatia daca nu este pe sol
    {
        verticalSpeed += gravity; //maresc viteza verticala cu gravitatia
        position.y += verticalSpeed;  ////??????
    }
    if(position.y + shape.getRadius()*2 >= wHeight)
    {
        position.y = wHeight - shape.getRadius()*2;
        verticalSpeed = 0.0f;
        onGround = true;
    }
    shape.setPosition(position);
}
*/
