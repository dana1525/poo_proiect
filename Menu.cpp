
#include "Menu.h"
#include <iostream>
#include <fstream>

Menu::Menu(float wWidth, float wHeight)
{
    if(!myFont.loadFromFile("E://facultate//an2_sem1//poo 1//poo_proiect//Comfortaa//static//Comfortaa-Regular.ttf"))
    {
        ///sa fac operatorul <<
        std::cout << "eroare la încărcarea fontului";
        return;
    }

    ///optiuni meniu
    std::string items[] = {"Start","Niveluri","Ieșire"};
    selectedItemIndex = 0;

    for(int i = 0; i < 3; i++)
    {
        sf::Text text;
        text.setFont(myFont);
        text.setString(items[i]);
        text.setCharacterSize(50);
        text.setFillColor(sf::Color(255,182,193));
        text.setPosition(wWidth/2 - text.getGlobalBounds().width/2, wHeight/4*(i+1));
        menuItems.push_back(text);
    }
    menuItems[0].setFillColor(sf::Color::Red); //optiunea selectata
}

void Menu::draw(sf::RenderWindow &window) {
    for(const auto &item : menuItems)
        window.draw(item);
}

void Menu::moveUp() {
    if(selectedItemIndex - 1 >= 0)
    {
        menuItems[selectedItemIndex].setFillColor(sf::Color(255,182,193));
        selectedItemIndex--;
        menuItems[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}

void Menu::moveDown() {
    if(selectedItemIndex + 1 < menuItems.size())
    {
        menuItems[selectedItemIndex].setFillColor(sf::Color(255,182,193));
        selectedItemIndex--;
        menuItems[selectedItemIndex].setFillColor(sf::Color::Red);

    }
}