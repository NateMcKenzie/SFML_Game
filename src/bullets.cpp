#include "bullets.hpp"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>

void Bullets::draw(sf::RenderWindow& window) {
    for (sf::RectangleShape& bullet : *bullets) {
        window.draw(bullet);
    }
}

void Bullets::update(const sf::Vector2<float>& player_position) {
    if (++bullet_time >= 60) {
        sf::RectangleShape bullet({ 5.f, 10.f });
        bullet.setPosition(player_position);
        bullet.setFillColor(sf::Color::Blue);
        bullets->push_back(bullet);
        bullet_time = 0;
    }

    for (auto it = bullets->begin(); it != bullets->end();) {
        it->move({ 0.f, -BULLET_SPEED });
        if (it->getPosition().y < 0) {
            it = bullets->erase(it);
        } else {
            ++it;
        }
    }
    std::cout << bullets->size() << std::endl;
}
