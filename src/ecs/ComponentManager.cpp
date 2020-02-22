#include "ecs/ComponentManager.hpp"

namespace ecs
{

using comp::EComponentType;

uint32_t ComponentManager::addComponent(EComponentType type)
{
	switch (type)
	{
	case EComponentType::Transform:
		return m_transforms.add();
	case EComponentType::Movement:
		return m_movements.add();
	case EComponentType::Render:
		return m_renders.add();
	default:
		;
	}
	// add critical log
    return 0;
}

void ComponentManager::freeComponent(uint32_t id, EComponentType type)
{
	switch (type)
	{
	case EComponentType::Transform:
		return m_transforms.free(id);
	case EComponentType::Movement:
		return m_movements.free(id);
	case EComponentType::Render:
		return m_renders.free(id);
	default:
		;
	}  
}

}