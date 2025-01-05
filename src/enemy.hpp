#pragma once

#include "entity.hpp"

class Enemy : public Entity {
  public:
    using Entity::Entity;

    Enemy(sf::Vector2<float> position) : Entity(position, SIZE, sf::Color::Red) {}

    virtual void update();

    static constexpr sf::Vector2<float> SIZE = { 20.f, 40.f };
};
