#ifndef __PARA_COMPONENT_HPP__
#define __PARA_COMPONENT_HPP__

#pragma once
#include <string>

namespace Para
{
	enum class ComponentType
	{
		RENDER_COMPONENT,
		BEHAVIOUR_COMPONENT
	};

	//TODO skoñczyæ klasê
	class Component
	{
	public:
		Component();
		~Component();

		virtual void update() = 0;

		inline const std::string& getName() const { return m_name; }
		inline void setName(const std::string& name) { m_name = name; }
		inline const std::string& getTag() const { return m_tag; }
		inline void setTag(const std::string& tag) { m_tag = tag; }
		inline ComponentType getType() const { return m_type; }
		
	private:
		std::string m_name;
		std::string m_tag;
		ComponentType m_type;
		//TODO dorobiæ w³aœciciela komponentu
		
	};
}


#endif //__PARA_COMPONENT_HPP__
