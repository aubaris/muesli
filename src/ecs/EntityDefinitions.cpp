#include "ecs/EntityDefinitions.hpp"
#include "ecs/Components.hpp"

namespace ecs
{
    namespace entity
    {
        uint32_t PlayerMask = comp::createMaskForComponents(comp::EComponentType::CircleShapeRender);
    }
}