#include "player.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Window.hpp>

const uint WIN_WIDTH = 540u;
const uint WIN_HEIGHT = 960u;

const sf::Vector2f LATERAL_MOVE(1.f, 0.f);
const sf::Vector2f VERTICAL_MOVE(0.f, 1.f);

int main() {
    auto window = sf::RenderWindow(sf::VideoMode({ WIN_WIDTH, WIN_HEIGHT }), "CMake SFML Project", sf::Style::None,
                                   sf::State::Windowed);
    window.setFramerateLimit(144);

    Player player{ { static_cast<float>(WIN_WIDTH) / 2 - Player::PLAYER_RADIUS,
                     WIN_HEIGHT - (2 * Player::PLAYER_RADIUS) - 10 } };

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
            if (player.position().x > 0) {
                player.move(-LATERAL_MOVE);
            }
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
            if (player.position().x < WIN_WIDTH - (2 * Player::PLAYER_RADIUS)) {
                player.move(LATERAL_MOVE);
            }
        }

        player.update();

        window.clear();
        player.draw(window);
        window.display();
    }
}
