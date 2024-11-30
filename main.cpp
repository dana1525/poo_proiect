#include <iostream>
#include <array>
#include <chrono>
#include <thread>

#include <SFML/Graphics.hpp>
#include "headers/FireCharacter.h"
#include "headers/WaterCharacter.h"
#include "headers/Menu.h"
#include "headers/Obstacle.h"
#include "headers/Enums.h"
#include "headers/Game.h"
#include "env_fixes.h"   //environment-specific fixes

int main() {

    init_threads();  //environment-specific fixes

    //Helper helper;
    //helper.help();

    Game g;
    g.run();

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

