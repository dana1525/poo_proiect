
#ifndef OOP_STATE_H
#define OOP_STATE_H

#include <SFML/Graphics.hpp>

class State {
public:
    virtual ~State() = default;

    virtual void input(sf::Event &event) = 0;

    virtual void update(sf::RenderWindow &window, float deltaSec) = 0;

    virtual void render(sf::RenderWindow &window) = 0;
};


#endif //OOP_STATE_H
