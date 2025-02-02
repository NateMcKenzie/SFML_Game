#pragma once

#include "bullet.hpp"

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>
#include <vector>

class Player {
  public:
    Player(sf::Vector2<float> position);
    Player(sf::Vector2<float> position, sf::Color color);
    void draw(sf::RenderWindow& window);
    void update();
    void move(sf::Vector2<float> vector);

    sf::Vector2<float> position() { return drawable.getPosition(); }

    std::weak_ptr<std::vector<Bullet>> shareBullets();

    constexpr static const float PLAYER_RADIUS = 30.f;
    bool shooting = false;

  private:
    uint fireClock = 0;
    uint fireDelay = 20;
    sf::CircleShape drawable;
    std::shared_ptr<std::vector<Bullet>> bullets = std::make_shared<std::vector<Bullet>>();
};
