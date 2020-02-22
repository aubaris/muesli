#ifndef ECS_SYSTEM_HPP
#define ECS_SYSTEM_HPP

#include <SFML/System/Time.hpp>

namespace ecs
{

    class Engine;

    class System
    {
    public:
        System(Engine& engine) : m_engine(engine) {}
        ~System() {}
        virtual void update(sf::Time dt) = 0;
        virtual void render(sf::Time dt) = 0;

    protected:
        Engine& m_engine;
    };

}

#endif