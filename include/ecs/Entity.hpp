#ifndef ECS_ENTITY_HPP
#define ECS_ENTITY_HPP

#include <cstdint>
#include <utility>
#include "Components.hpp"
#include <unordered_map>

namespace ecs
{

class Entity
{
public:
    uint32_t id = 0;

    // Currently only support for 1 component per type
    uint32_t componentMask = 0;

    bool active = true;

    // Using vector for data locality instead?
    std::unordered_map<comp::EComponentType, uint32_t> componentIDs;
    //std::vector<std::pair<comp::EComponentType, uint32_t>> m_components;
};

}

#endif