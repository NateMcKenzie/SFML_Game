#include "collisionSystem.hpp"
#include "level.hpp"
#include "player.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Window.hpp>

const uint WIN_WIDTH = 540u;
const uint WIN_HEIGHT = 960u;

int main() {
    auto window = sf::RenderWindow(sf::VideoMode({ WIN_WIDTH, WIN_HEIGHT }), "CMake SFML Project", sf::Style::None,
                                   sf::State::Windowed);
    window.setFramerateLimit(144);

    Player player{ { static_cast<float>(WIN_WIDTH) / 2 - Player::PLAYER_RADIUS,
                     WIN_HEIGHT - (2 * Player::PLAYER_RADIUS) - 10 } };
    Level level;

    CollissionSystem collissionSystem{ player.shareBullets(), level.shareEnemies() };

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
            if (player.position().x > 0) {
                player.move({ -1.f, 0.f });
            }
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
            if (player.position().x < WIN_WIDTH - (2 * Player::PLAYER_RADIUS)) {
                player.move({ 1.f, 0.f });
            }
        }

        player.update();
        level.update();
        collissionSystem.runCollisions();

        window.clear();
        player.draw(window);
        level.draw(window);
        window.display();
    }
}
