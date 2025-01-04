#include "bullets.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Window.hpp>

const uint WIN_WIDTH = 540u;
const uint WIN_HEIGHT = 960u;
const float PLAYER_RADIUS = 40.f;
const float LOST_Y = WIN_HEIGHT - (2 * PLAYER_RADIUS) - 10;

const sf::Vector2f LATERAL_MOVE(1.f, 0.f);
const sf::Vector2f VERTICAL_MOVE(0.f, 1.f);

int main() {
    auto window = sf::RenderWindow(sf::VideoMode({ WIN_WIDTH, WIN_HEIGHT }), "CMake SFML Project", sf::Style::None,
                                   sf::State::Windowed);
    window.setFramerateLimit(144);

    sf::CircleShape player(PLAYER_RADIUS);
    player.setFillColor(sf::Color::Green);
    player.setPosition({ static_cast<float>(WIN_WIDTH) / 2 - PLAYER_RADIUS, LOST_Y });

    Bullets bullets;

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
            player.move(-LATERAL_MOVE);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
            player.move(LATERAL_MOVE);
        }

        bullets.update(player.getPosition());

        window.clear();
        window.draw(player);
        bullets.draw(window);
        window.display();
    }
}
