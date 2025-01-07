#include "level.hpp"

#include <SFML/Graphics/RectangleShape.hpp>
#include <random>

Level::Level(uint width, uint columns) : col_width(static_cast<float>(width) / columns), col_count(columns) {
    enemies = std::make_shared<std::vector<Enemy>>();
    enemyTicks = {
        std::make_shared<std::deque<uint>>(),
        std::make_shared<std::deque<uint>>(),
    };

    for (uint i = 0; i < 60; i++) {
        enemyTicks[0]->push_back(i * 200);
        enemyTicks[1]->push_back(i * 300);
    }

    std::random_device device;
    rand_engine = std::default_random_engine(device());
    rand_distibution = std::uniform_real_distribution<float>(20, col_width - 20 - ENEMY_SIZE.x);
}

void Level::update() {
    for (uint i = 0; i < col_count; i++) {
        std::shared_ptr<std::deque<uint>> column = enemyTicks[i];
        if (column->size() > 0 && column->front() <= clock) {
            column->pop_front();
            enemies->push_back(Enemy({ (col_width * i) + rand_distibution(rand_engine), -ENEMY_SIZE.y }, ENEMY_SIZE));
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
