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
	case EComponentType::RectangleShapeRender:
		return m_rectangleShapeRenders.add();
	default:
		;
	}
	// TODO: Add critical log
    return 0;
}

void ComponentManager::freeComponent(uint32_t id, EComponentType type)
{
	// TODO: Is a non void return type necessary here?
	switch (type)
	{
	case EComponentType::Transform:
		return m_transforms.free(id);
	case EComponentType::Movement:
		return m_movements.free(id);
	case EComponentType::RectangleShapeRender:
		return m_rectangleShapeRenders.free(id);
	default:
		;
	}  
}

template<>
comp::Transform* ComponentManager::getComponent(uint32_t id)
{
    return m_transforms[id];
}

template<>
comp::Movement* ComponentManager::getComponent(uint32_t id)
{
    return m_movements[id];
}

template<>
comp::RectangleShapeRender* ComponentManager::getComponent(uint32_t id)
{
    return m_rectangleShapeRenders[id];
}

}