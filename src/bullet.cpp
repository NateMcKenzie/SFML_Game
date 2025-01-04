#include "bullet.hpp"

#include "utilities.hpp"

Bullet::Bullet(sf::Vector2<float> position) : Bullet(position, sf::Color::Blue) {}
Bullet::Bullet(sf::Vector2<float> position, sf::Color color) {
    drawable = sf::RectangleShape({ 5.f, 10.f });
    drawable.setPosition(position);
    drawable.setFillColor(color);
}

Bullet::Bullet(const Bullet& rhs) : destroyed(rhs.destroyed), speed(rhs.speed), drawable(rhs.drawable) {} // copy
Bullet::Bullet(Bullet&& rhs) noexcept :
    destroyed(rhs.destroyed), speed(rhs.speed), drawable(std::move(rhs.drawable)) {} // move
Bullet& Bullet::operator=(const Bullet& rhs) {                                       // copy
    // Should check rhs != this but I don't have that operator implemented right now.
    destroyed = rhs.destroyed;
    speed = rhs.speed;
    drawable = rhs.drawable;
    return *this;
}
Bullet& Bullet::operator=(Bullet&& rhs) noexcept { // move
    // Should check rhs != this but I don't have that operator implemented right now.
    destroyed = rhs.destroyed;
    speed = rhs.speed;
    drawable = std::move(rhs.drawable);
    return *this;
}

void Bullet::destroy() {
    destroyed = true;
}

bool Bullet::isColliding(sf::RectangleShape other) {
    return other.getLocalBounds().findIntersection(drawable.getLocalBounds()).has_value();
}
bool Bullet::isColliding(sf::CircleShape other) {
    // Slight approximation
    float corner0Distance = distanceCalculate({ drawable.getPoint(0) }, other.getGeometricCenter());
    float corner1Distance = distanceCalculate({ drawable.getPoint(0) }, other.getGeometricCenter());
    float corner2Distance = distanceCalculate({ drawable.getPoint(0) }, other.getGeometricCenter());
    float corner3Distance = distanceCalculate({ drawable.getPoint(0) }, other.getGeometricCenter());

    return corner0Distance < other.getRadius() || corner1Distance < other.getRadius() ||
           corner2Distance < other.getRadius() || corner3Distance < other.getRadius();
}
void Bullet::draw(sf::RenderWindow& window) {
    window.draw(drawable);
}
void Bullet::update() {
    drawable.move({ 0.f, -speed });
    if (drawable.getPosition().y < 0) {
        destroy();
    }
}
