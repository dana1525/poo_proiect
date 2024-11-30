
#ifndef OOP_CHARACTER_H
#define OOP_CHARACTER_H

#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Enums.h"

class Character : public Entity {
protected:
    ///sprite-uri

    float m_speed;
    float m_jumpHeight;
    float m_jumpForce; //jump force

public:
    Character(const EntityTag &tag, const size_t &id, const sf::Vector2f &position);

    ///constructor de copiere
    Character(const Character &other);

    ~Character() override = default;

    Character &operator=(const Character &other);

    void print(std::ostream &out) const override;
    // Virtual function - allows a function defined in a base class to be overridden in a derived class.
    // Objects of derived classes will have different behavior when called via a pointer or reference of the base class type.


    friend std::ostream &operator<<(std::ostream &out, const Character &other);
// Needs to be a friend function to be used outside the class.

    void controller();

    virtual void handleInput() = 0;

    void move(float dx, float dy);

    ///sf::FloatRect getBounds() const;

    ///bool checkCollision();

    void jump();

    ///virtual bool isAffectedByObstacle(const std::string& type) const override;

    ///void takeDamage();

};


#endif //OOP_CHARACTER_H
