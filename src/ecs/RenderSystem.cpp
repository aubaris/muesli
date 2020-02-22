#include "ecs/RenderSystem.hpp"
#include "ecs/Components.hpp"
#include "ecs/Entity.hpp"
#include "ecs/Engine.hpp"

namespace ecs
{
    using comp::EComponentType;

    RenderSystem::RenderSystem(Engine& engine)
        : System(engine)
    {
        // create some test entities
        uint32_t mask = comp::createMaskForComponents(EComponentType::Transform,
                                                      EComponentType::Movement,
                                                      EComponentType::Render);
        //mask |= EComponentType::Transform;
        for (int i = 0; i < 100; ++i)
        {
            m_engine.addEntity(mask);
        }
    }

    void RenderSystem::update(sf::Time dt)
    {
        //throw std::logic_error("The method or operation is not implemented.");
    }

    void RenderSystem::render(sf::Time dt)
    {

    }
}


