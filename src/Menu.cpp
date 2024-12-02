
#include "../headers/Menu.h"
#include <iostream>
#include <SFML/Graphics.hpp>

Menu::Menu(unsigned int wWidth, unsigned int wHeight) {
    if (!myFont.loadFromFile("..//Comfortaa/Comfortaa-VariableFont_wght.ttf")) {
        std::cout << "erorr loading the font";
        return;
    }

    ///optiuni meniu
    std::vector<std::string> items = {"Start", "Levels", "Exit"};
    selectedItemIndex = 0;

    for (int i = 0; i < (int) items.size(); i++) {
        sf::Text text;
        text.setFont(myFont);
        text.setString(items[i]);
        text.setCharacterSize(50);
        text.setFillColor(sf::Color(255, 182, 193));
        text.setPosition((float) wWidth / 2 - text.getGlobalBounds().width / 2, (float) wHeight / 4 * ((float) i + 1));
        menuItems.push_back(text);
    }
    if (!menuItems.empty()) {
        menuItems[0].setFillColor(sf::Color::Red);
    } else {
        std::cout << "Error: menuItems is empty." << std::endl;
    }
}

void Menu::draw(sf::RenderWindow &window) {
    for (const auto &item: menuItems)
        window.draw(item);
}

void Menu::moveUp() {
    if (selectedItemIndex >= 1) {
        menuItems[selectedItemIndex].setFillColor(sf::Color(255, 182, 193));
        selectedItemIndex--;
        menuItems[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}

void Menu::moveDown() {
    if (selectedItemIndex + 1 < menuItems.size()) {
        menuItems[selectedItemIndex].setFillColor(sf::Color(255, 182, 193));
        selectedItemIndex++;
        menuItems[selectedItemIndex].setFillColor(sf::Color::Red);

    }
}

unsigned long long Menu::getSelectedItemIndex() const {
    return selectedItemIndex;
}

void Menu::run(const sf::Event &event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Up)
            this->moveUp();
        else if (event.key.code == sf::Keyboard::Down)
            this->moveDown();
    }
}

///std::ostream& operator<<(std::ostream& out, ){}