
#ifndef OOP_CHARACTER_H
#define OOP_CHARACTER_H

#include <SFML/Graphics.hpp>

//functie virtuala - permite ca o functie definita intr-o clasa de baza sa fie suprascrisa intr-o clasa derivata
//astfel, obiectele derivate vor avea comportamente diferite cand sunt apelate prin intermediul unui pointer sau al unei referinte de tipul clasei de baza

class Character {
protected:
    ///sprite-uri
    sf::CircleShape shape;
    sf::Vector2f position;
    float speed, jumpHeight;
    bool onGround;

    float verticalSpeed = 0.0f; //viteza pe y
    float gravity = 9.8f;  //???????constanta gravitationala
    float jumpForce = -10.0f; //forta saritura

public:
    Character(const sf::Vector2f start_position);

    ///constructor de copiere
    Character(const Character& other);

    ~Character() = default;

    void draw(sf::RenderWindow& window);

    void move(float dx, float dy); //cu ce variatie

    const sf::Vector2f &getPosition() const;

    sf::FloatRect getBounds() const;

    void checkBounds(unsigned int wWidth, unsigned int wHeight);

    ///bool checkCollision();

    void jump();

    void applyGravity(unsigned int wHeight);

    ///void takeDamage(); ///probabil personajul si obstacolul???

    Character& operator=(const Character &other);

    virtual void print(std::ostream& out) const;

    friend std::ostream& operator<<(std::ostream& out, const Character &other);

};


#endif //OOP_CHARACTER_H
