#include "ecs/DebuggingSystem.hpp"
#include "ecs/Components.hpp"
#include "ecs/Entity.hpp"
#include "ecs/Engine.hpp"

#include <random>
#include <iostream>
#include <numeric>

namespace ecs
{
    using comp::EComponentType;

    DebuggingSystem::DebuggingSystem(Engine& engine, sf::RenderWindow* window)
        : System(engine), m_window(window)
    {
        m_mask = comp::createMaskForComponents(EComponentType::DebugInfo);

        if (!m_font.loadFromFile("OpenSans-Regular.ttf"))
        {
            std::cerr << "font error";
            return;
        }
        m_fpsText.setFont(m_font);
        m_fpsText.setPosition(30, 30);
        m_fpsText.setFillColor(sf::Color::White);
        m_fpsText.setCharacterSize(16);
        m_fpsText.setString("Test 123");

        m_fpsAverageText.setFont(m_font);
        m_fpsAverageText.setPosition(30, 60);
        m_fpsAverageText.setFillColor(sf::Color::White);
        m_fpsAverageText.setCharacterSize(16);
        m_fpsAverageText.setString("Test 123");

        m_entityID = m_engine.addEntity(m_mask);
    }

    void DebuggingSystem::update(sf::Time dt)
    {
        //return;
        m_refreshCD -= dt;
        if (m_refreshCD <= sf::Time::Zero)
        {
            m_refreshCD = sf::milliseconds(500);
            auto entity = m_engine.getUnsafeEntityPtr(m_entityID);
            if (!entity)
            {
                return;
            }
            comp::DebugInfo* debugInfo = m_engine.getComponent<comp::DebugInfo>(entity->componentIDs[EComponentType::DebugInfo]);
            if (debugInfo)
            {
                debugInfo->fpsQueue.push_back(1.0f / dt.asSeconds());
                while (debugInfo->fpsQueue.size() > 60)
                {
                    debugInfo->fpsQueue.pop_front();
                }
                int sum = std::accumulate(debugInfo->fpsQueue.begin(), debugInfo->fpsQueue.end(), 0);
                m_fpsAverageText.setString("Avg. fps: " + std::to_string(sum / debugInfo->fpsQueue.size()));
                m_fpsText.setString("Fps: " + std::to_string(std::lround(1.0f / dt.asSeconds())));
            }
            else
            {
                std::cout << "No debug info";
            }
        }
    }

    void DebuggingSystem::render(sf::Time dt)
    {
        // TODO: Render fps info
        m_window->draw(m_fpsAverageText);
        m_window->draw(m_fpsText);
    }
}


