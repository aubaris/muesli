#ifndef ECS_RENDER_SYSTEM_HPP
#define ECS_RENDER_SYSTEM_HPP

#include "System.hpp"

namespace ecs
{

    class Engine;
    
    class RenderSystem : public System
    {
    public:
        RenderSystem(Engine& engine);
        void update(sf::Time dt) override;
        void render(sf::Time dt) override;

    private:

    };
}

#endif // !ECS_RENDER_SYSTEM_HPP
