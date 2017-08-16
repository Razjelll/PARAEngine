#ifndef __PARA_RENDER_ELEMENT_HPP__
#define __PARA_RENDER_ELEMENT_HPP__

#pragma once

typedef unsigned int ElementID;

namespace Para
{
	
	class Entity;
	//TODO doko�czy� to 
	class RenderElement
	{
	public:
		RenderElement(Entity& entity) : m_entity(entity) {} //TODO przetestowa� obiektem Transform
		virtual ~RenderElement() {};

		virtual void draw() = 0;
		//TODO mo�e b�dzie potrzeba zrobi� metod� update, w kt�rej b�d� aktualizowane animacje czy co�

		inline const ElementID getID() const { return m_id; }
		inline void setID(ElementID id) { m_id = id; }
	private:
		ElementID m_id;
		Entity& m_entity; //TODO nada� temu lepsz� nazw�
	};
}
#endif //__PARA_RENDER_ELEMENT_HPP__