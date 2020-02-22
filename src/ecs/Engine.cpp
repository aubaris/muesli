#include "ecs/Engine.hpp"

namespace ecs
{

void ecs::Engine::addEntity(uint32_t componentMask)
{

}

void Engine::update(sf::Time dt)
{

}

void Engine::render(sf::Time dt)
{

}

void Engine::addSystem(std::unique_ptr<System> system)
{
    m_systems.push_back(std::move(system));
}

}
