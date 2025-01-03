#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>
#include <vector>

class Bullets {
  public:
    void draw(sf::RenderWindow& window);
    void update(const sf::Vector2<float>& player_position);

  private:
    const float BULLET_SPEED = 1.f;
    uint bullet_time = 0;
    std::shared_ptr<std::vector<sf::RectangleShape>> bullets = std::make_shared<std::vector<sf::RectangleShape>>();
};
