
#include "Obstacle.h"

Obstacle::Obstacle(sf::Vector2f position, float width, float height, const std::string& type) : position(position), type(type) {
    ob_shape.setPosition(position.x,position.y);
    ob_shape.setSize({width, height});
    if(type == "fire")
        ob_shape.setFillColor(sf::Color::Red);
    else
    if(type == "water")
        ob_shape.setFillColor(sf::Color::Blue);
};

std::ostream& operator<<(std::ostream& out, const Obstacle& ob){
    out << "Obstacle (" << ob.type << ") position: (" << ob.position.x << ", " << ob.position.y << ")";
}

void Obstacle::draw(sf::RenderWindow& window) const{
    window.draw(ob_shape);
}
