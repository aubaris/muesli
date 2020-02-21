#ifndef ECS_COMPONENT_MANAGER_HPP
#define ECS_COMPONENT_MANAGER_HPP

#include "Components.hpp"
#include <vector>
// #include <pair>

namespace ecs
{
 
    template<typename T>
    class ComponentMemory
    {
    public:

    };

    class ComponentManager
    {
    public:
        using ID = uint32_t;

        ComponentManager();
        ID addComponent(comp::EComponentType type);
        void freeComponent(ID id, comp::EComponentType type);

    private:
        std::vector<comp::Transform> m_transforms;
        std::vector<comp::Movement> m_movements;
        std::vector<comp::Render> m_renders;

        ID m_nextFreeTransform = 0;


        // Pooling?
    };
}

#endif