#include "ecs/Components.hpp"

namespace ecs
{
    namespace comp
    {
        bool isPartOfMask(uint32_t mask, EComponentType type)
        {
            uint32_t maskForType = createMaskForComponents(type);
            return (mask & maskForType) == maskForType;
        }
    }
}