#include "bullet.hpp"

void Bullet::update() {
    drawable.move({ 0.f, -speed });
    if (drawable.getPosition().y < 0) {
        destroy();
    }
}
