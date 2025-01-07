#pragma once

#include "entity.hpp"

class Enemy : public Entity {
  public:
    using Entity::Entity;

    Enemy(sf::Vector2<float> position, sf::Vector2<float> size) : Entity(position, size, sf::Color::Red) {
        speed = 0.5f;
    }

    virtual void update();
};
