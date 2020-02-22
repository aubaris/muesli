#ifndef ECS_COMPONENT_MANAGER_HPP
#define ECS_COMPONENT_MANAGER_HPP

#include "Components.hpp"
#include <vector>

namespace ecs
{
 
    template<typename T>
    class ComponentMemory
    {
    public:
		uint32_t add();
		void free(uint32_t id);

	private:
		std::vector<T> m_components;
		uint32_t m_nextFreeID = 0;
    };

    class ComponentManager
    {
    public:
        ComponentManager();
		uint32_t addComponent(comp::EComponentType type);
        void freeComponent(uint32_t id, comp::EComponentType type);

    private:
		ComponentMemory<comp::Transform> m_transforms;
		ComponentMemory<comp::Movement> m_movements;
		ComponentMemory<comp::Render> m_renders;

        // Pooling?
    };

	template<typename T>
	uint32_t ComponentMemory<T>::add()
	{
		return 0;
	}

	template<typename T>
	void ComponentMemory<T>::free(uint32_t id)
	{

	}
}

#endif