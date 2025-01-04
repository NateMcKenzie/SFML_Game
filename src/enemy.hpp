#pragma once

#include "entity.hpp"

class Enemy : public Entity {
  public:
    using Entity::Entity;

    Enemy(sf::Vector2<float> position) : Entity(position, { 10.f, 20.f }, sf::Color::Red) {}

    virtual void update();
};
