#include "ecs/ComponentManager.hpp"

namespace ecs
{

using comp::EComponentType;

ComponentManager::ID ComponentManager::addComponent(comp::EComponentType component)
{
    if (m_nextFreeTransform >= m_transforms.size())
    {
        m_transforms.push_back({});
    }
    else
    {
        m_transforms[m_nextFreeTransform].reset();
    }
    return m_nextFreeTransform++;
}

void ComponentManager::freeComponent(ComponentManager::ID id, comp::EComponentType type)
{
    switch (type)
    {
        case EComponentType::Transform:

            // Already freed component can be skipped
            if (id < m_nextFreeTransform) {
                
            }
            break;
        case EComponentType::Movement:
            break;
        
        case EComponentType::Render:
            break;
    }    
}

}