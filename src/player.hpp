#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>
#include <vector>

class Player {
  public:
    Player(sf::Vector2<float> position);
    Player(sf::Vector2<float> position, sf::Color color);
    void draw(sf::RenderWindow& window);
    void update();
    void move(sf::Vector2<float> vector);
    sf::Vector2<float> position() { return drawable.getPosition(); }

    constexpr static const float PLAYER_RADIUS = 30.f;

  private:
    sf::RectangleShape bulletGen();

    const float BULLET_SPEED = 1.f;

    uint fire_clock = 0;
    sf::CircleShape drawable;
    std::shared_ptr<std::vector<sf::RectangleShape>> bullets = std::make_shared<std::vector<sf::RectangleShape>>();
};
