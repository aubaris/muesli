#ifndef ECS_ENTITY_HPP
#define ECS_ENTITY_HPP

#include <cstdint>

namespace ecs
{

class Entity
{
public:
    uint32_t m_id = 0;
    uint32_t m_ComponentMask = 0;
    bool active = false;
};

}

#endif