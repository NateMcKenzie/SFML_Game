#include "player.hpp"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

Player::Player(sf::Vector2<float> position) : Player(position, sf::Color::Green) {}
Player::Player(sf::Vector2<float> position, sf::Color color) {
    drawable = sf::CircleShape(PLAYER_RADIUS);
    drawable.setPosition(position);
    drawable.setFillColor(color);
}

void Player::move(sf::Vector2<float> vector) {
    drawable.move(vector);
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(drawable);

    for (sf::RectangleShape& bullet : *bullets) {
        window.draw(bullet);
    }
}

void Player::update() {
    if (++fire_clock >= 60) {
        sf::RectangleShape bullet({ 5.f, 10.f });
        bullet.setPosition(drawable.getPosition());
        bullet.setFillColor(sf::Color::Blue);
        bullets->push_back(bullet);
        fire_clock = 0;
    }

    for (auto it = bullets->begin(); it != bullets->end();) {
        it->move({ 0.f, -BULLET_SPEED });
        if (it->getPosition().y < 0) {
            it = bullets->erase(it);
        } else {
            ++it;
        }
    }
}
