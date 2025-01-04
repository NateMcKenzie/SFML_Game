#pragma once

#include "entity.hpp"

class Enemy : public Entity {
  public:
    using Entity::Entity;

    Enemy(sf::Vector2<float> position) : Entity(position, { 20.f, 40.f }, sf::Color::Red) {}

    virtual void update();
};
