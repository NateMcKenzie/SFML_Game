#include "level.hpp"

#include <SFML/Graphics/RectangleShape.hpp>

Level::Level() {
    enemies = std::make_shared<std::vector<Enemy>>();
    enemyTicks = std::make_shared<std::deque<uint>>();

    for (uint i = 0; i < 40; i++) {
        enemyTicks->push_back(i * 120);
    }
}

void Level::update() {
    if (enemyTicks->front() <= ++clock) {
        enemyTicks->pop_front();
        enemies->push_back(Enemy({ 20.f, 0.f }));
    }

    for (auto it = enemies->begin(); it != enemies->end();) {
        it->update();
        if (it->destroyed) {
            it = enemies->erase(it);
        } else {
            ++it;
        }
    }
}

void Level::draw(sf::RenderWindow& window) {
    for (Enemy& enemy : *enemies) {
        enemy.draw(window);
    }
}
