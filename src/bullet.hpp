#pragma once

#include "entity.hpp"

class Bullet : public Entity {
  public:
    using Entity::Entity;

    Bullet(sf::Vector2<float> position) : Entity(position, { 5.f, 10.f }, sf::Color::Blue) {}

    virtual void update();
};
