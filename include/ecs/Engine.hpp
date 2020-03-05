#ifndef ECS_ENGINE_HPP
#define ECS_ENGINE_HPP

#include "ComponentManager.hpp"
#include "Entity.hpp"
#include "System.hpp"
#include <vector>
#include <SFML/System/Time.hpp>

//#include <optional>

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

        uint32_t addEntity(uint32_t componentMask);
        void update(sf::Time dt);
        void render(sf::Time dt = sf::Time::Zero);

        // id needs to be passed by the entity requesting the component, see Entity.componentIDs
        template<typename T>
        T* getComponent(uint32_t id);

        void addSystem(std::unique_ptr<System> system);

        // The returned reference might become invalid due to internal memory reallocation
        Entity* const getUnsafeEntityPtr(uint32_t id);

    private:
        ComponentManager m_componentManager;
        std::vector<std::unique_ptr<System>> m_systems;
        std::vector<Entity> m_entities;

        // TODO entity pooling
        // TODO cached list of entities with component xyz
    };

    template<typename F>
    void Engine::forAllEntitiesWithComponents(uint32_t mask, F func1)
    {
        for (auto& e : m_entities)
        {
            if (e.componentMask == mask)
            {
                func1(e);
            }
        }
    }

    template<typename T>
    T* Engine::getComponent(uint32_t id)
    {
        return m_componentManager.getComponent<T>(id);
    }
}

#endif