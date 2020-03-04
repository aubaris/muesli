#include "ecs/ColorChangeSystem.hpp"
#include "ecs/Components.hpp"
#include "ecs/Entity.hpp"
#include "ecs/Engine.hpp"

#include <random>
#include <iostream>

namespace {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, 255);
    std::uniform_int_distribution<int> bool_dist(0, 2);
}

namespace ecs
{
    using comp::EComponentType;

    ColorChangeSystem::ColorChangeSystem(Engine& engine)
        : System(engine)
    {
        m_mask = comp::createMaskForComponents(EComponentType::RectangleShapeRender);        
    }

    void ColorChangeSystem::update(sf::Time dt)
    {
        m_cooldown -= dt;
        if (m_cooldown <= sf::Time::Zero) {
            auto func = [this](Entity& e) {
                auto component = m_engine.getComponent<comp::RectangleShapeRender>(e.id);
                if (bool_dist(mt)) {
                    component->shape.setFillColor(sf::Color(dist(mt), dist(mt), dist(mt)));
                    //component->shape.setOutlineColor(sf::Color(dist(mt), dist(mt), dist(mt)));
                }
            };
            m_engine.forAllEntitiesWithComponents(m_mask, func);
            m_cooldown = sf::seconds(1);
        }
    }

    void ColorChangeSystem::render(sf::Time dt)
    {
    }
}


