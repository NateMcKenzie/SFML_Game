#include "entity.hpp"

#include "utilities.hpp"

Entity::Entity(sf::Vector2<float> position, sf::Vector2<float> size, sf::Color color) {
    drawable = sf::RectangleShape(size);
    drawable.setPosition(position);
    drawable.setFillColor(color);
}

Entity::Entity(const Entity& rhs) : destroyed(rhs.destroyed), speed(rhs.speed), drawable(rhs.drawable) {} // copy

Entity::Entity(Entity&& rhs) noexcept :
    destroyed(rhs.destroyed), speed(rhs.speed), drawable(std::move(rhs.drawable)) {} // move

Entity& Entity::operator=(const Entity& rhs) { // copy
    // Should check rhs != this but I don't have that operator implemented right now.
    destroyed = rhs.destroyed;
    speed = rhs.speed;
    drawable = rhs.drawable;
    return *this;
}

Entity& Entity::operator=(Entity&& rhs) noexcept { // move
    // Should check rhs != this but I don't have that operator implemented right now.
    destroyed = rhs.destroyed;
    speed = rhs.speed;
    drawable = std::move(rhs.drawable);
    return *this;
}

void Entity::destroy() {
    destroyed = true;
}

bool Entity::isColliding(Entity& other) {
    return other.drawable.getGlobalBounds().findIntersection(drawable.getGlobalBounds()).has_value();
}

void Entity::draw(sf::RenderWindow& window) {
    window.draw(drawable);
}
