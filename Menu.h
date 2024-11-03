
#ifndef OOP_MENU_H
#define OOP_MENU_H
#include "SFML/Graphics.hpp"
#include <vector>

class Menu {
    unsigned long long selectedItemIndex;
    std::vector<sf::Text> menuItems;
    sf::Font myFont;
public:
    Menu(unsigned int wWidth, unsigned int wHeight);
    unsigned long long getSelectedItemIndex() const;
    void draw(sf::RenderWindow &window);
    void moveUp();
    void moveDown();
};


#endif //OOP_MENU_H


