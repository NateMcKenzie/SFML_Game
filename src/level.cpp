#include "level.hpp"

#include <SFML/Graphics/RectangleShape.hpp>

Level::Level() {
    enemies = std::make_shared<std::vector<sf::RectangleShape>>();
    enemyTicks = std::make_shared<std::deque<uint>>();

    for (uint i = 0; i < 40; i++) {
        enemyTicks->push_back(i * 120);
    }
}
void Level::update() {
    if (enemyTicks->front() <= ++clock) {
        enemyTicks->pop_front();
        enemies->push_back(enemyGen());
    }

    for (auto it = enemies->begin(); it != enemies->end();) {
        it->move({ 0.f, ENEMY_SPEED });
        if (it->getPosition().y > 800) {
            it = enemies->erase(it);
        } else {
            ++it;
        }
    }
}
void Level::draw(sf::RenderWindow& window) {
    for (sf::RectangleShape& enemy : *enemies) {
        window.draw(enemy);
    }
}

sf::RectangleShape Level::enemyGen() {
    sf::RectangleShape enemy({ 15.f, 25.f });
    enemy.setPosition({ 100, 0 });
    enemy.setFillColor(sf::Color::Red);
    return enemy;
}
