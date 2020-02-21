#ifndef ECS_SYSTEM_HPP
#define ECS_SYSTEM_HPP

#include <SFML/System/Time.hpp>

namespace ecs
{

class System
{
public:
    virtual void update(sf::Time dt) = 0;
    virtual void render(sf::Time dt) = 0;
};

}

#endif