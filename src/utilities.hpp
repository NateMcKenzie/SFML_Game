#include <SFML/System/Vector2.hpp>
#include <cmath>

constexpr float distanceCalculate(sf::Vector2<float> point1, sf::Vector2<float> point2) {
    float A = point1.x - point2.x;
    float B = point1.y - point2.y;
    return std::sqrt((A * A) + (B * B));
}
