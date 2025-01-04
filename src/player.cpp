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

    for (Bullet& bullet : *bullets) {
        bullet.draw(window);
    }
}

void Player::update() {
    if (++fireClock >= 60) {
        bullets->push_back(Bullet(position()));
        fireClock = 0;
    }

    for (auto it = bullets->begin(); it != bullets->end();) {
        it->update();
        if (it->destroyed) {
            it = bullets->erase(it);
        } else {
            ++it;
        }
    }
}

std::weak_ptr<std::vector<Bullet>> Player::shareBullets() {
    return std::weak_ptr(bullets);
}
