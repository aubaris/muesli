#include "ecs/RenderSystem.hpp"
#include "ecs/Components.hpp"
#include "ecs/Entity.hpp"
#include "ecs/Engine.hpp"

#include <random>
#include <iostream>

namespace {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<float> dist(0.0f, 400); //1280, 720
    std::uniform_real_distribution<float> dist_x(0.0f, 1280); //1280, 720
    std::uniform_real_distribution<float> dist_y(0.0f, 720); //1280, 720
}

namespace ecs
{
    using comp::EComponentType;

    RenderSystem::RenderSystem(Engine& engine, sf::RenderWindow* window)
        : System(engine), m_window(window)
    {
        // create some test entities
        m_mask = comp::createMaskForComponents(EComponentType::RectangleShapeRender/*, EComponentType::CircleShapeRender*/);

        std::cout << "ctor RenderSystem: mask = " << m_mask << "\n";

        //mask |= EComponentType::Transform;
        for (int i = 0; i < 100; ++i)
        {
            auto entityID = m_engine.addEntity(m_mask);
            const float x = dist_x(mt);
            const float y = dist_y(mt);
            auto entity = m_engine.getUnsafeEntityPtr(entityID);
            if (!entity)
            {
                // Log error
                continue;
            }
            auto id = entity->componentIDs[EComponentType::RectangleShapeRender];
            auto component = m_engine.getComponent<comp::RectangleShapeRender>(id);
            component->shape.setSize(sf::Vector2f(10.0f, 10.0f));
            component->shape.setFillColor(sf::Color::Black);
            component->shape.setPosition(x, y);
            //component->shape.setOutlineThickness(0.5f);
        }
    }

    void RenderSystem::update(sf::Time dt)
    {
        //throw std::logic_error("The method or operation is not implemented.");
    }

    void RenderSystem::render(sf::Time dt)
    {
        auto func = [this](Entity& e) {
            if (comp::isPartOfMask(e.componentMask, comp::EComponentType::RectangleShapeRender))
            {
                auto id = e.componentIDs[EComponentType::RectangleShapeRender];
                auto component = m_engine.getComponent<comp::RectangleShapeRender>(id);
                if (component)
                    m_window->draw(component->shape);
            }
            if (comp::isPartOfMask(e.componentMask, comp::EComponentType::CircleShapeRender))
            {
                auto id = e.componentIDs[EComponentType::CircleShapeRender];
                auto component = m_engine.getComponent<comp::CircleShapeRender>(id);
                if (component)
                    m_window->draw(component->shape);
            }
            /*auto component = m_engine.getComponent<comp::RectangleShapeRender>(e.id);
            m_window->draw(component->shape);*/
        };
        m_engine.forAllEntitiesWithComponents(comp::createMaskForComponents(EComponentType::CircleShapeRender), func);
        m_engine.forAllEntitiesWithComponents(comp::createMaskForComponents(EComponentType::RectangleShapeRender), func);
        //m_engine.forAllEntitiesWithComponents(m_mask, func);
    }
}


