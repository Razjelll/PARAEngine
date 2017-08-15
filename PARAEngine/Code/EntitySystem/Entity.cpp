#include "Entity.hpp"
#include "../Utils/HashUtils.hpp"
#include <algorithm>

using namespace Para;

Entity::Entity(EntityID id) : m_id(id)
{
}

Entity::Entity(EntityID id ,const std::string& name):m_id(id), m_name(name)
{
}


Entity::~Entity()
{
	//podczas usuwania obiektu usuwane sa wszystkie komponenty oraz dzieci
	size_t componentSize = m_components.components.size();
	for (size_t i = 0; i < componentSize; i++)
	{
		delete m_components.components[i];
	}
	m_components.components.clear();

	size_t childrenSize = m_children.size();
	for (size_t i = 0; i < childrenSize; i++)
	{
		m_children[i]->setParent(nullptr); //TODO to chyba bêdzie niepotrzebne, poniewa¿ dzieci w kontruktorze bed¹ od³¹cz³y rodzica
		delete m_children[i];
	}
	m_children.clear();

	//od³¹czenie rodzica
	m_parent = nullptr;
}

void Entity::attachChild(Entity* child)
{
	m_children.push_back(child);
	child->setParent(this);

}

void Entity::setParent(Entity* parent)
{
	m_parent = parent;

}

void Entity::detachChild(Entity* child)
{
	std::vector<Entity*>::iterator it = std::find_if(m_children.begin(), m_children.end(), [child](Entity* entity)
	{
		return child == entity;
	});
	if (it != m_children.end())
	{
		(*it)->setParent(nullptr);
		m_children.erase(it);
	}
}

void Entity::detachChild(EntityID entityID)
{
	std::vector<Entity*>::iterator it = std::find_if(m_children.begin(), m_children.end(), [entityID](Entity* entity)
	{
		return entity->getID() == entityID;
	});
	if (it != m_children.end())
	{
		(*it)->setParent(nullptr);
		m_children.erase(it);
	}
}

void Entity::detachChild(const std::string& name)
{
	std::vector<Entity*>::iterator it = std::find_if(m_children.begin(), m_children.end(), [name](Entity* entity)
	{
		return entity->getName() == name;
	});
	if (it != m_children.end())
	{
		(*it)->setParent(nullptr);
		m_children.erase(it);
	}
}

void Entity::detachAllChildren()
{
	std::for_each(m_children.begin(), m_children.end(),[](Entity* entity){
		entity->setParent(nullptr);
	});
	m_children.clear();
}

Entity* Entity::getChild(EntityID id)
{
	std::vector<Entity*>::iterator iterator = std::find_if(m_children.begin(), m_children.end(), [id](Entity* entity) {return entity->getID() == id; });
	if (iterator != m_children.end())
	{
		return *iterator;
	}
	return nullptr;
}

void Entity::removeChild(EntityID id)
{
	std::vector<Entity*>::iterator it = std::find_if(m_children.begin(), m_children.end(), [id](Entity* entity)
	{
		return entity->getID() == id;
	});
	if (it != m_children.end())
	{
		(*it)->setParent(nullptr);
		delete (*it);
		m_children.erase(it);
	}
}

void Entity::addComponent(Component* component)
{
	//TODO ustawiæ w³aœciciela komponentu
	m_components.components.push_back(component);
}

void Entity::removeComponent(Component* component)
{
	
	auto begin = m_components.components.begin();
	auto end = m_components.components.end();
	std::vector<Component*>::iterator it = std::find_if(begin, end, [component](Component* comp)
	{
		return component == comp;
	});
	if (it != end)
	{
		//TODO usun¹æ w³aœciciela komponentu
		delete (*it);
		m_components.components.erase(it);
	}
}
