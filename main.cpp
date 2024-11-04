#include <iostream>
#include <array>
#include <chrono>
#include <thread>

#include <SFML/Graphics.hpp>
#include "FireCharacter.h"
#include "WaterCharacter.h"
#include "Menu.h"

///#include <Helper.h>
#include "env_fixes.h"   //environment-specific fixes


///???????????????????????????????
enum gameState{
    MENU,
    PLAYING,
    //PAUSE,
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

    window.setFramerateLimit(60);

    FireCharacter fireCharacter(sf::Vector2f(100.f,100.f));
    WaterCharacter waterCharacter(sf::Vector2f(300.f,300.f));
    //FireCharacter c = fireCharacter;

    gameState currentState = MENU; //initializare stare joc

    while(window.isOpen()) {

        sf::Event event = {}; //initializare eveniment
        while(window.pollEvent(event)) {

            if (event.type == sf::Event::Closed)
                window.close();

            //Logica meniu
            if (currentState == MENU) {
                if (event.type == sf::Event::KeyPressed) {
                    if (event.key.code == sf::Keyboard::Up)
                        menu.moveUp();
                    else if (event.key.code == sf::Keyboard::Down)
                        menu.moveDown();
                    else if (event.key.code == sf::Keyboard::Enter) {
                        switch (menu.getSelectedItemIndex()) {
                            case 0: //start
                                currentState = PLAYING;
                                break;
                            case 1: //niveluri
                                std::cout << "Selecteaza nivelul\n";
                                break;
                            case 2: //iesire
                                currentState = EXIT;
                                window.close();
                                break;
                        }
                    }
                }
            }
        }
        window.clear();

        if(currentState == MENU)
            menu.draw(window);
        else
        if(currentState == PLAYING){
            fireCharacter.handleInput();
            waterCharacter.handleInput();

            std::cout << fireCharacter;
            std::cout << waterCharacter;

            //gravitatia
            //fireCharacter.applyGravity(window.getSize().y);
            //waterCharacter.applyGravity(window.getSize().y);

            fireCharacter.checkBounds(wWidth,wHeight);
            waterCharacter.checkBounds(wWidth,wHeight);

            fireCharacter.draw(window);
            //c.draw(window);
            waterCharacter.draw(window);
        }

    window.display();

    using namespace std::chrono_literals;   ///de ce trebuie sa pastrez chestia astaaaa???????
    std::this_thread::sleep_for(100ms);

    }
    return 0;
}





//bool shouldExit = false;
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

