
#ifndef OOP_MENU_H
#define OOP_MENU_H
#include "SFML/Graphics.hpp"
#include <vector>

class Menu {
    int selectedItemIndex;
    std::vector<sf::Text> menuItems;
    sf::Font myFont;
public:
    Menu(float wWidth, float wHeight);
    void draw(sf::RenderWindow &window);
    void moveUp();
    void moveDown();
    int getPressedItem;

};


#endif //OOP_MENU_H
