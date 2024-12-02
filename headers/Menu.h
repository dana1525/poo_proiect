
#ifndef OOP_MENU_H
#define OOP_MENU_H

#include <SFML/Graphics.hpp>
#include <vector>

/**
 * @class Menu
 * @brief Represents a graphical menu for the game, allowing navigation through menu items.
 *
 * The Menu class handles displaying menu items and user interaction for navigation.
 */

class Menu {
    unsigned long long selectedItemIndex; ///< Index of the currently selected menu item.
    std::vector<sf::Text> menuItems; ///< Collection of menu items represented as SFML text objects.
    sf::Font myFont; ///< Font used for rendering menu items.
public:
    Menu(unsigned int wWidth, unsigned int wHeight);

    unsigned long long getSelectedItemIndex() const;

    /**
     * @brief Draws the menu items to the specified SFML window.
     * @param window The window where the menu should be rendered.
     */
    void draw(sf::RenderWindow &window);

    /**
     * @brief Moves the selection up by one item.
     */
    void moveUp(); //to do: if it's up -> goes to the last one

    /**
     * @brief Moves the selection down by one item.
     */
    void moveDown();

    /**
     * @brief Handles user input for interacting with the menu.
     * @param event The SFML event object representing user input.
     */
    void run(const sf::Event &event);
};


#endif //OOP_MENU_H
