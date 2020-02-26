#ifndef ECS_COMPONENT_MANAGER_HPP
#define ECS_COMPONENT_MANAGER_HPP

#include "Components.hpp"
#include <vector>
#include <SFML/Graphics/RectangleShape.hpp>

namespace ecs
{
	// Template arguments are expected to be subclass of IComponent
	// TODO: assert this by code
    template<typename T>
    class ComponentMemory
    {
    public:
		uint32_t add();
		void free(uint32_t id);
		T* operator[](size_t index)
		{
			if (index < m_components.size())
			{
				if (m_components[index].active)
				{
					return &m_components[index];
				}
			}
			return nullptr;
		}

	private:
		std::vector<T> m_components;
		std::vector<uint32_t> m_freedComponents;
		uint32_t m_nextNewID = 0;
    };

    class ComponentManager
    {
    public:
        //ComponentManager();
		uint32_t addComponent(comp::EComponentType type);
        void freeComponent(uint32_t id, comp::EComponentType type);

		template<typename T>
		T* getComponent(uint32_t id); // return nullptr if no component was found
		// intentionally left undefined, see https://stackoverflow.com/questions/8220045/switch-template-type

    private:
		ComponentMemory<comp::Transform> m_transforms;
		ComponentMemory<comp::Movement> m_movements;
		ComponentMemory<comp::RectangleShapeRender> m_rectangleShapeRenders;
    };
	
	//template<>
	//comp::Transform* ComponentManager::getComponent(uint32_t id)
	//{
	//	return m_transforms[id];
	//}

 //   template<>
 //   comp::Movement* ComponentManager::getComponent(uint32_t id)
 //   {
 //       return m_movements[id];
 //   }

 //   template<>
 //   comp::RectangleShapeRender* ComponentManager::getComponent(uint32_t id)
 //   {
 //       return m_rectangleShapeRenders[id];
 //   }

    template<typename T>
	uint32_t ComponentMemory<T>::add()
	{
		// Check for freed storage
		if (m_freedComponents.size() > 0)
		{
			// TODO: How can we guarantee that the previous "owner" of the component does
			// not use the id of the freed component to access the reused component?
			// maybe using hash values

			// TODO: Sort the components depending on active state and saved id

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