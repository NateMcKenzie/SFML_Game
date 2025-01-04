#pragma once

#include "enemy.hpp"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <deque>
#include <memory>

class Level {
  public:
    Level();
    void update();
    void draw(sf::RenderWindow& window);

  private:
    uint clock{ 0 };
    std::shared_ptr<std::vector<Enemy>> enemies;
    std::shared_ptr<std::deque<uint>> enemyTicks;
};
