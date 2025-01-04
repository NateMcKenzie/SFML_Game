#pragma once

#include "bullet.hpp"
#include "enemy.hpp"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <memory>
#include <vector>

class CollissionSystem {
  public:
    CollissionSystem(std::weak_ptr<std::vector<Bullet>> bullets,
                     std::weak_ptr<std::vector<Enemy>> enemies) : bullets(bullets), enemies(enemies) {}
    void runCollisions();

  private:
    std::weak_ptr<std::vector<Bullet>> bullets;
    std::weak_ptr<std::vector<Enemy>> enemies;
};
