#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Bullet {
  public:
    Bullet(sf::Vector2<float> position);
    Bullet(sf::Vector2<float> position, sf::Color color);
    Bullet(const Bullet& rhs);                // copy
    Bullet(Bullet&& rhs) noexcept;            // move
    Bullet& operator=(const Bullet& rhs);     // copy
    Bullet& operator=(Bullet&& rhs) noexcept; // move

    void destroy();
    bool isColliding(sf::RectangleShape other);
    bool isColliding(sf::CircleShape other);
    void draw(sf::RenderWindow& window);
    void update();

    bool destroyed = false;

  private:
    float speed = 1.f;
    sf::RectangleShape drawable;
};
