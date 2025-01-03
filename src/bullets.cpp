#include "bullets.hpp"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

void Bullets::draw(sf::RenderWindow& window) {
    for (sf::RectangleShape& bullet : *entities) {
        window.draw(bullet);
    }
}

void Bullets::update(const sf::Vector2<float>& player_position) {
    if (++clock >= 60) {
        sf::RectangleShape bullet({ 5.f, 10.f });
        bullet.setPosition(player_position);
        bullet.setFillColor(sf::Color::Blue);
        entities->push_back(bullet);
        clock = 0;
    }

    for (auto it = entities->begin(); it != entities->end();) {
        it->move({ 0.f, -SPEED });
        if (it->getPosition().y < 0) {
            it = entities->erase(it);
        } else {
            ++it;
        }
    }
}
