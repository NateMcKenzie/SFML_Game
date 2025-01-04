#pragma once

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Entity {
  public:
    Entity(sf::Vector2<float> position, sf::Vector2<float> size, sf::Color color);
    Entity(const Entity& rhs);
    Entity(Entity&& rhs) noexcept;
    Entity& operator=(const Entity& rhs);
    Entity& operator=(Entity&& rhs) noexcept;
    virtual ~Entity() = default;
    virtual void destroy();
    virtual void draw(sf::RenderWindow& window);
    virtual void update() = 0;
    bool isColliding(Entity& other);

    bool destroyed = false;

  protected:
    float speed = 1.f;
    sf::RectangleShape drawable;
};
