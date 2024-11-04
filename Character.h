
#ifndef OOP_CHARACTER_H
#define OOP_CHARACTER_H

#include <SFML/Graphics.hpp>

class Character {
protected:
    ///sprite-uri

    sf::CircleShape shape;
    sf::Vector2f position;
    float speed;
    float jumpHeight;
    bool onGround = true;

    float yvelocity; //viteza pe y
    float gravity;  //???????constanta gravitationala
    float jumpForce; //forta saritura

public:
    explicit Character(sf::Vector2f start_position); //am adaugat explicit, pentru ca era un constructor cu un singur parametru si se putea crea confuzie

    ///constructor de copiere
    Character(const Character& other);

    ~Character() = default;

    Character& operator=(const Character &other);

    virtual void print(std::ostream& out) const;
//functie virtuala - permite ca o functie definita intr-o clasa de baza sa fie suprascrisa intr-o clasa derivata
//astfel, obiectele derivate vor avea comportamente diferite cand sunt apelate prin intermediul unui pointer sau al unei referinte de tipul clasei de baza

    friend std::ostream& operator<<(std::ostream& out, const Character &other);
//trebuie sa fie functie prietena pentru a putea fi folosita in afara

    void draw(sf::RenderWindow& window);

    void move(float dx, float dy); //cu ce variatie

    ///const sf::Vector2f& getPosition() const;  nu cred ca am nevoie de getter? cel putin acum

    ///sf::FloatRect getBounds() const;

    void checkBounds(unsigned int wWidth, unsigned int wHeight);

    ///bool checkCollision();

    void jump();

    void applyGravity(unsigned int wHeight, float deltaSec);

    ///virtual bool isAffectedByObstacle(const std::string& type) const override;

    ///void takeDamage(); ///probabil personajul si obstacolul???

};


#endif //OOP_CHARACTER_H
