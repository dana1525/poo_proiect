#include <iostream>
#include <array>
#include <chrono>
#include "headers/Game.h"
#include "headers/GameException.h"

int main() {

    try {
        Game g;
        g.run();
    } catch (const InitializationException &e) {
        std::cerr << "Initialization error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    } catch (const LogicException &e) {
        std::cerr << "Logic error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    } catch (const GeneralException &e) {
        std::cerr << "Game error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    } catch (const std::exception &e) {
        std::cerr << "Standard library error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    } catch (...) {
        std::cerr << "Unknown error: " << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}