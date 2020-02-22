#ifndef ECS_COMPONENTS_HPP
#define ECS_COMPONENTS_HPP

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <memory>

namespace ecs
{

namespace comp
{

enum class EComponentType : uint32_t
{
    Transform,
    Movement,
    Render,
    NUM // number of different types
};


template<typename ...Args>
auto createMaskForComponents(Args ...args)
{
    return (std::underlying_type_t<EComponentType>(args) | ...);
}

//template<EComponentType C>
//uint32_t createMaskForComponents(EComponentType C)
//{
//    return std::underlying_type_t<EComponentType>(C);
//}
//
//template<EComponentType C, EComponentType... Rest>
//uint32_t createMaskForComponents(EComponentType C, EComponentType Rest...)
//{
//    uint32_t mask = createMaskForComponents<Rest...>();
//    return std::underlying_type_t<EComponentType>(C) | mask;
//}

struct IComponent
{
    bool active {true};
    virtual void reset() = 0;
};

struct Transform : public IComponent
{
    sf::Vector2f position;

    void reset() override {
        position = sf::Vector2f();
    }
};

struct Movement : public IComponent
{
    sf::Vector2f velocity;

    void reset() override {
        velocity = sf::Vector2f();
    }
};

struct Render : public IComponent
{
    std::unique_ptr<sf::Drawable> drawable;
    
    void reset() override {
        drawable.reset();
    }
};
    
}

}

#endif