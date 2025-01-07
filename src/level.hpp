#pragma once

#include "enemy.hpp"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <deque>
#include <memory>
#include <random>

class Level {
  public:
    Level(uint width, uint columns);
    void update();
    void draw(sf::RenderWindow& window);
    std::weak_ptr<std::vector<Enemy>> shareEnemies();

  private:
    uint clock{ 0 };
    float col_width;
    uint col_count;
    std::default_random_engine rand_engine;
    std::uniform_real_distribution<float> rand_distibution;
    std::shared_ptr<std::vector<Enemy>> enemies;
    std::vector<std::shared_ptr<std::deque<uint>>> enemyTicks;
    static constexpr sf::Vector2<float> ENEMY_SIZE = { 20.f, 40.f };
};
