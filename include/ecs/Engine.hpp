#ifndef ECS_ENGINE_HPP
#define ECS_ENGINE_HPP

#include "ComponentManager.hpp"
#include "Entity.hpp"
#include "System.hpp"
#include <vector>
#include <SFML/System/Time.hpp>

#include <optional>

namespace ecs
{

    class Engine
    {
    public:
        Engine();

        // create systems and load entities
        void init();

        template<typename F>
        void forAllEntitiesWithComponents(uint32_t mask, F func1);

        void addEntity(uint32_t componentMask);
        void update(sf::Time dt);
        void render(sf::Time dt);

        template<typename T>
        std::optional<T*> getComponentForEntity(uint32_t id);

        void addSystem(std::unique_ptr<System> system);

    private:
        ComponentManager m_componentManager;
        std::vector<std::unique_ptr<System>> m_systems;
        std::vector<Entity> m_entities;

        // TODO cached list of entities with component xyz
    };

    template<typename F>
    void Engine::forAllEntitiesWithComponents(uint32_t mask, F func1)
    {
        for (auto& e : m_entities)
        {
            if (e.m_ComponentMask == mask)
            {
                func1(e);
            }
        }
    }

    template<typename T>
    std::optional<T*> Engine::getComponentForEntity(uint32_t id)
    {
        m_componentManager.
        return nullptr;
    }
}

#endif