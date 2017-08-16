#ifndef __PARA_RENDER_ELEMENT_HPP__
#define __PARA_RENDER_ELEMENT_HPP__

#pragma once

typedef unsigned int ElementID;

namespace Para
{
	
	class Entity;
	//TODO dokoñczyæ to 
	class RenderElement
	{
	public:
		RenderElement(Entity& entity) : m_entity(entity) {} //TODO przetestowaæ obiektem Transform
		virtual ~RenderElement() {};

		virtual void draw() = 0;
		//TODO mo¿e bêdzie potrzeba zrobiæ metodê update, w której bêd¹ aktualizowane animacje czy coœ

		inline const ElementID getID() const { return m_id; }
		inline void setID(ElementID id) { m_id = id; }
	private:
		ElementID m_id;
		Entity& m_entity; //TODO nadaæ temu lepsz¹ nazwê
	};
}
#endif //__PARA_RENDER_ELEMENT_HPP__