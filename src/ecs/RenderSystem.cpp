#include "ecs/RenderSystem.hpp"
#include "ecs/Components.hpp"
#include "ecs/Entity.hpp"
#include "ecs/Engine.hpp"

#include <random>
#include <iostream>

std::random_device rd;
std::mt19937 mt(rd());
std::uniform_real_distribution<float> dist(0.0f, 400);

namespace ecs
{
    using comp::EComponentType;

    RenderSystem::RenderSystem(Engine& engine, sf::RenderWindow* window)
        : System(engine), m_window(window)
    {
        // create some test entities
        m_mask = comp::createMaskForComponents(EComponentType::RectangleShapeRender);

        std::cout << "ctor RenderSystem: mask = " << m_mask << "\n";

        //mask |= EComponentType::Transform;
        for (int i = 0; i < 30; ++i)
        {
            auto entity = m_engine.addEntity(m_mask);
            const float x = dist(mt);
            const float y = dist(mt);
            auto id = entity->componentIDs[EComponentType::RectangleShapeRender];
            auto component = m_engine.getComponent<comp::RectangleShapeRender>(id);
            component->shape.setSize(sf::Vector2f(40.0f, 40.0f));
            component->shape.setFillColor(sf::Color::Cyan);
            component->shape.setPosition(x, y);
        }
    }

    void RenderSystem::update(sf::Time dt)
    {
        //throw std::logic_error("The method or operation is not implemented.");
    }

    void RenderSystem::render(sf::Time dt)
    {
        auto func = [this](Entity& e) {
            auto component = m_engine.getComponent<comp::RectangleShapeRender>(e.id);
            m_window->draw(component->shape);
        };
        m_engine.forAllEntitiesWithComponents(m_mask, func);
    }
}


