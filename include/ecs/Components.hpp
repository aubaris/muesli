#ifndef ECS_COMPONENTS_HPP
#define ECS_COMPONENTS_HPP

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <memory>
#include <list>
#include <algorithm>

namespace ecs
{

namespace comp
{

enum class EComponentType : uint32_t
{
    INVALID_VALUE = 0,
    Transform = 1 << 1,
    Movement = 1 << 2,
    RectangleShapeRender = 1 << 3,
    DebugInfo = 1 << 4,
    CircleShapeRender = 1 << 5,
    NUM // number of different types
};


template<typename ...Args>
auto createMaskForComponents(Args ...args)
{
    return (std::underlying_type_t<EComponentType>(args) | ...);
}


bool isPartOfMask(uint32_t mask, EComponentType type);


struct IComponent
{
    IComponent(EComponentType type) : type(type) {}
    EComponentType type;
    bool active {true};
    virtual void reset() = 0;
};

struct Transform : public IComponent
{
    Transform() : IComponent(EComponentType::Transform) {}
    sf::Vector2f position;

    void reset() override {
        position = sf::Vector2f();
    }
};

struct Movement : public IComponent
{
    Movement() : IComponent(EComponentType::Movement) {}
    sf::Vector2f velocity;

    void reset() override {
        velocity = sf::Vector2f();
    }
};

struct RectangleShapeRender : public IComponent
{
    RectangleShapeRender() : IComponent(EComponentType::RectangleShapeRender) {}

    sf::RectangleShape shape;

    void reset() override {
        sf::RectangleShape swapShape;
        std::swap(shape, swapShape);
    }
};

struct DebugInfo : public IComponent
{
    DebugInfo() : IComponent(EComponentType::DebugInfo) {}

    std::list<float> fpsQueue;

    void reset() override {
        std::list<float> swapQueue;
        std::swap(fpsQueue, swapQueue);
    }
};

struct CircleShapeRender : public IComponent
{
    CircleShapeRender() : IComponent(EComponentType::CircleShapeRender) {}

    sf::CircleShape shape;

    void reset() override {
        sf::CircleShape swapShape;
        std::swap(shape, swapShape);
    }
};


//template<typename T>
//struct Render : public IComponent
//{
//    Render() : IComponent(EComponentType::Render)
//    {
//        static_assert(
//            std::is_base_of<sf::Drawable, T>::value,
//            "T must be a subclass of sf::Drawable"
//            );
//    }
//
//    T drawable;
//
//    void reset() override {
//        drawable = T{};
//    }
//};
    
}

}

#endif