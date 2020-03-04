#ifndef ECS_DEBUGGING_SYSTEM_HPP
#define ECS_DEBUGGING_SYSTEM_HPP

#include "System.hpp"
#include <cstdint>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

namespace ecs
{

    class Engine;
    class Entity;

    class DebuggingSystem : public System
    {
    public:
        DebuggingSystem(Engine& engine, sf::RenderWindow* window);
        void update(sf::Time dt) override;
        void render(sf::Time dt) override;

    private:
        uint32_t m_mask = 0;
        sf::RenderWindow* m_window;
        sf::Font m_font;
        sf::Text m_fpsText;

        Entity* m_entity = 0;

        sf::Time m_refreshCD;
    };
}

#endif