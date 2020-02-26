#ifndef ECS_RENDER_SYSTEM_HPP
#define ECS_RENDER_SYSTEM_HPP

#include "System.hpp"
#include <SFML/Graphics/RenderWindow.hpp>

namespace ecs
{

    class Engine;
    
    class RenderSystem : public System
    {
    public:
        RenderSystem(Engine& engine, sf::RenderWindow* window);
        void update(sf::Time dt) override;
        void render(sf::Time dt) override;

    private:
        uint32_t m_mask = 0;
        sf::RenderWindow *m_window; // TODO: Generalize this with RenderTarget if needed
    };
}

#endif // !ECS_RENDER_SYSTEM_HPP
