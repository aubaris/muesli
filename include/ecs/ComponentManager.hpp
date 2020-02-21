#ifndef ECS_COMPONENT_MANAGER_HPP
#define ECS_COMPONENT_MANAGER_HPP

#include "Components.hpp"
#include <vector>
// #include <pair>

namespace ecs
{
    using CmpID = uint32_t;

    class ComponentManager
    {
    public:
        ComponentManager();
        CmpID addComponent(comp::EComponent component);
        void freeComponent(CmpID id);

    private:
        // pair.key indicates if the component is in use
        std::vector<std::pair<bool, comp::Transform>> m_transforms;
        std::vector<comp::Movement> m_movements;
        std::vector<comp::Render> m_renders;

        // Pooling?
    };
}

#endif