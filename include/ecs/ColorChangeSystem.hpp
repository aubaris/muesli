#ifndef ECS_COLOR_CHANGE_SYSTEM_HPP
#define ECS_COLOR_CHANGE_SYSTEM_HPP

#include "System.hpp"
#include <cstdint>

namespace ecs
{

    class Engine;
    
    class ColorChangeSystem : public System
    {
    public:
        ColorChangeSystem(Engine& engine);
        void update(sf::Time dt) override;
        void render(sf::Time dt) override;

    private:
        uint32_t m_mask = 0;
        sf::Time m_cooldown = sf::seconds(1);
    };
}

#endif