#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Bullet {
  public:
    Bullet(sf::Vector2<float> position);
    Bullet(sf::Vector2<float> position, sf::Color color);
    void destroy();
    void isColliding(sf::RectangleShape other);
    void isColliding(sf::CircleShape other);
    void draw(sf::RenderWindow& window);
    void update();
  private:
    const float SPEED = 1.f;
    sf::RectangleShape drawable;
};
