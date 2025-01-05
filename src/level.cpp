#include "level.hpp"

#include <SFML/Graphics/RectangleShape.hpp>

Level::Level() {
    enemies = std::make_shared<std::vector<Enemy>>();
    enemyTicks = {
        std::make_shared<std::deque<uint>>(),
        std::make_shared<std::deque<uint>>(),
    };

    for (uint i = 0; i < 40; i++) {
        enemyTicks[0]->push_back(i * 200);
        enemyTicks[1]->push_back(i * 300);
    }
}

void Level::update() {
    for (uint i = 0; i < enemyTicks.size(); i++) {
        std::shared_ptr<std::deque<uint>> column = enemyTicks[i];
        if (column->front() <= clock) {
            column->pop_front();
            enemies->push_back(Enemy({ 30.f * i, -Enemy::SIZE.y }));
        }
    }

    for (auto it = enemies->begin(); it != enemies->end();) {
        it->update();
        if (it->destroyed) {
            it = enemies->erase(it);
        } else {
            ++it;
        }
    }
    clock++;
}

void Level::draw(sf::RenderWindow& window) {
    for (Enemy& enemy : *enemies) {
        enemy.draw(window);
    }
}

std::weak_ptr<std::vector<Enemy>> Level::shareEnemies() {
    return std::weak_ptr(enemies);
}
