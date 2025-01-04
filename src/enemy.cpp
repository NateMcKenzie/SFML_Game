#include "enemy.hpp"

void Enemy::update() {
    drawable.move({ 0.f, speed });
    if (drawable.getPosition().y > 800) {
        destroy();
    }
}
