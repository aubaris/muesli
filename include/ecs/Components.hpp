#ifndef ECS_COMPONENTS_HPP
#define ECS_COMPONENTS_HPP

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <memory>

namespace ecs
{

namespace comp
{

enum class EComponentType
{
    Transform,
    Movement,
    Render,
    NUM // number of different types
};

struct Transform
{
    sf::Vector2f position;

    void reset() {
        position = sf::Vector2f();
    }
};

struct Movement
{
    sf::Vector2f velocity;

    void reset() {
        velocity = sf::Vector2f();
    }
};

struct Render
{
    std::unique_ptr<sf::Drawable> drawable;
    
    void reset() {
        drawable.reset();
    }
};
    
}

}

#endif