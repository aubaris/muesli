#include "ecs/Engine.hpp"
#include "ecs/Components.hpp"
#include <iostream>

namespace ecs
{

using comp::EComponentType;

Entity* ecs::Engine::addEntity(uint32_t componentMask)
{
    Entity entity;
    entity.id = static_cast<uint32_t>(m_entities.size());
    entity.componentMask = componentMask;

    // TODO prevent assigning already existing component
    // due to potential memory leak in component memory

    // Create components
    if (comp::isPartOfMask(componentMask, EComponentType::Transform))
    {
        entity.componentIDs.emplace(EComponentType::Transform,
            m_componentManager.addComponent(EComponentType::Transform));
    }
    if (comp::isPartOfMask(componentMask, EComponentType::Movement))
    {
        entity.componentIDs.emplace(EComponentType::Movement,
            m_componentManager.addComponent(EComponentType::Movement));
    }
    if (comp::isPartOfMask(componentMask, EComponentType::RectangleShapeRender))
    {
        // TODO prevent assigning already existing component
        // due to potential memory leak in component memory

        //std::cout << "create render comp\n";

        entity.componentIDs.emplace(EComponentType::RectangleShapeRender,
            m_componentManager.addComponent(EComponentType::RectangleShapeRender));
    }
    //m_componentManager.
    m_entities.push_back(entity);

    return &m_entities.back();
}

void Engine::update(sf::Time dt)
{
    for (auto& system : m_systems)
    {
        system->update(dt);
    }
}

void Engine::render(sf::Time dt)
{
	for (auto& system : m_systems)
	{
		system->render(dt);
	}
}

void Engine::addSystem(std::unique_ptr<System> system)
{
    m_systems.push_back(std::move(system));
}

}
