#include "collisionSystem.hpp"

#include <memory>

void CollissionSystem::runCollisions() {
    auto bullets_handle = bullets.lock();
    auto enemies_handle = enemies.lock();

    for (Bullet& bullet : *bullets_handle) {
        for (Enemy& enemy : *enemies_handle) {
            if (bullet.isColliding(enemy)) {
                enemy.destroy();
                bullet.destroy();
            }
        }
    }
}
