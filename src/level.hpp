#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <deque>
#include <memory>

class Level {
  public:
    Level();
    void update();
    void draw(sf::RenderWindow& window);

  private:
    sf::RectangleShape enemyGen();

    const float ENEMY_SPEED = 1.f;

    uint clock{ 0 };
    std::shared_ptr<std::vector<sf::RectangleShape>> enemies;
    std::shared_ptr<std::deque<uint>> enemyTicks;
};
