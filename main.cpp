#include <iostream>
#include <array>
#include <chrono>
#include <thread>

#include <SFML/Graphics.hpp>
#include "FireCharacter.h"
#include "WaterCharacter.h"
#include "Menu.h"

#include <Helper.h>
#include "env_fixes.h"   //environment-specific fixes


///???????????????????????????????
enum gameState{
    MENU,
    PLAYING,
    PAUSE,
    EXIT
};



int main() {

    init_threads();  //environment-specific fixes

    //Helper helper;
    //helper.help();

    sf::RenderWindow window;
    unsigned int wWidth = 800, wHeight = 700;
    window.create(sf::VideoMode({wWidth, wHeight}), "Fire and Water", sf::Style::Default);

    Menu menu(wWidth,wHeight);

    //window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);

    FireCharacter fireCharacter(sf::Vector2f(100.f,100.f));
    WaterCharacter waterCharacter(sf::Vector2f(300.f,300.f));

    while(window.isOpen()) {

        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed)
                window.close();
        }


        std::cout << fireCharacter;
        std::cout << waterCharacter;

        fireCharacter.handleInput();
        waterCharacter.handleInput();

        //gravitatia
        //fireCharacter.applyGravity(window.getSize().y);
        //waterCharacter.applyGravity(window.getSize().y);


        fireCharacter.checkBounds(wWidth,wHeight);
        waterCharacter.checkBounds(wWidth,wHeight);

        window.clear();
        fireCharacter.draw(window);
        waterCharacter.draw(window);
        window.display();

        using namespace std::chrono_literals;   ///de ce trebuie sa pastrez chestia astaaaa???????
        std::this_thread::sleep_for(100ms);
    }
    return 0;
}



//bool shouldExit = false;
//sf::Event e{};
//while(window.pollEvent(e)) {
//switch(e.type) {
//case sf::Event::Closed:
//window.close();
//break;
//case sf::Event::Resized:
//std::cout << "New width: " << window.getSize().x << '\n'
//<< "New height: " << window.getSize().y << '\n';
//break;
//case sf::Event::KeyPressed:
//std::cout << "Received key " << (e.key.code == sf::Keyboard::X ? "X" : "(other)") << "\n";
//if(e.key.code == sf::Keyboard::Escape)
//shouldExit = true;
//break;
/////?????????????????????????????????????
///*if(e.key.code == sf::Keyboard::Up)
//    menu.moveUp();
//break;
//if(e.key.code == sf::Keyboard::Down)
//    menu.moveDown();
//break;
//if(e.key.code == sf::Keyboard::Enter)
//    switch (menu.getPressedItem()) {
//    case 0:
//    }*/
//default:
//break;
//}}