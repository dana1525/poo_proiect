
#include "Menu.h"
#include <iostream>

Menu::Menu(unsigned int wWidth, unsigned int wHeight)
{
    if(!myFont.loadFromFile("Comfortaa//static//Comfortaa-Regular.ttf"))
    {
        ///sa fac operatorul <<
        std::cout << "eroare la încărcarea fontului";
        return;
    }

    ///optiuni meniu
    std::vector<std::string> items = {"Start","Niveluri","Iesire"};
    selectedItemIndex = 0;

    for(int i = 0; i < (int)items.size(); i++)
    {
        sf::Text text;
        text.setFont(myFont);
        text.setString(items[i]);
        text.setCharacterSize(50);
        text.setFillColor(sf::Color(255,182,193));
        text.setPosition((float)wWidth/2 - text.getGlobalBounds().width/2, (float)wHeight/4*((float)i+1));
        menuItems.push_back(text);
    }
    if (!menuItems.empty()) {
        menuItems[0].setFillColor(sf::Color::Red);
    } else {
        std::cout << "Eroare: vectorul menuItems este gol." << std::endl;
    }
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
        selectedItemIndex++;
        menuItems[selectedItemIndex].setFillColor(sf::Color::Red);

    }
}

unsigned long long Menu::getSelectedItemIndex() const{
    return selectedItemIndex;
}

///std::ostream& operator<<(std::ostream& out, ){}