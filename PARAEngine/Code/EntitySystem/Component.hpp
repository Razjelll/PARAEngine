#ifndef __PARA_COMPONENT_HPP__
#define __PARA_COMPONENT_HPP__

#pragma once
#include <string>
#include "Entity.hpp"

typedef unsigned int ComponentID;

namespace Para
{
	enum class ComponentType
	{
		RENDER_COMPONENT,
		BEHAVIOUR_COMPONENT,
		CAMERA_COMPONENT
	};

	//TODO skoñczyæ klasê
	/** Komponenty rozszerzaj¹ w³aœciwoœci obiektów gry. Komponentami moga byæ siatki obiektów, które bêd¹ wyrenderowane,
	œwiat³o, kamera, skrypt itd. Ka¿dy komponent musi mieæ przypisanego w³¹œciciela, poniewa¿ wiêkszoœæ komponentów musi
	znaæ po³o¿enie obiektu. Dodatkowo takie rozwi¹zanie pozwala na wymiane informacji pomiêdzy komponentami danego obiektu*/
	class Component
	{
	public:
		/** Komponent musi posiadaæ w³aœciciela, dlatego przekazywany jest w konstruktorze.
		Komponent nie mo¿e istnieæ d³u¿ej ni¿ jego w³aœciel, dlatego mo¿na przekazaæ referencjê do w³aœciciela*/
		Component(Entity& owner);
		~Component();

		//TODO w³aœciwie klasy init() oraz release s¹ niepotrzebne, mo¿na to wszystko za³atwiæ w kontruktorze
		/** Metoda wywo³ywana w momencie do³¹czenia komponentu do obiektu*/
		virtual void init() = 0;
		/** Metoda zawieraj¹ca dzia³ania charakterystyczne dla konkretnych rodzajów komponentów*/
		virtual void update() = 0;
		/** Metoda wywo³ywana w momencie od³¹czenia komponentu od obiektu.*/
		virtual void release() = 0;

		inline const std::string& getName() const { return m_name; }
		inline void setName(const std::string& name) { m_name = name; }
		inline const std::string& getTag() const { return m_tag; }
		inline void setTag(const std::string& tag) { m_tag = tag; }
		inline ComponentType getType() const { return m_type; }
		
		const Transform& getTransform() { 
			m_owner_entity.getTransform();
		}
	protected:
		ComponentID m_id;
		std::string m_name;
		std::string m_tag;
		ComponentType m_type;

		Entity& m_owner_entity;
	};
}


#endif //__PARA_COMPONENT_HPP__
