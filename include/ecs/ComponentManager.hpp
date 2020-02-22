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
		std::vector<uint32_t> m_freedComponents;
		uint32_t m_nextNewID;
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
		// Check for freed storage
		if (m_freedComponents.size() > 0)
		{
			// TODO sort the components depending on active state and saved id
			// Reuse existing component
			uint32_t id = m_freedComponents.back();
			m_freedComponents.pop_back();
			m_components[id].reset();
			return id;
		}
		else
		{
			m_components.push_back(T{});
			return m_nextNewID++;
		}
		return 0;
	}

	template<typename T>
	void ComponentMemory<T>::free(uint32_t id)
	{
		if (id >= m_components.size())
		{
			// log error
			return;
		}

		// do not free already freed component
		if (std::find(m_freedComponents.begin(), m_freedComponents.end(), id) == m_freedComponents.end()) {
			m_freedComponents.push_back(id);
			m_components[id].active = false;
		}
	}
}

#endif