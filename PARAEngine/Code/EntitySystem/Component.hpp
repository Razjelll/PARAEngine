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

	//TODO sko�czy� klas�
	/** Komponenty rozszerzaj� w�a�ciwo�ci obiekt�w gry. Komponentami moga by� siatki obiekt�w, kt�re b�d� wyrenderowane,
	�wiat�o, kamera, skrypt itd. Ka�dy komponent musi mie� przypisanego w���ciciela, poniewa� wi�kszo�� komponent�w musi
	zna� po�o�enie obiektu. Dodatkowo takie rozwi�zanie pozwala na wymiane informacji pomi�dzy komponentami danego obiektu*/
	class Component
	{
	public:
		/** Komponent musi posiada� w�a�ciciela, dlatego przekazywany jest w konstruktorze.
		Komponent nie mo�e istnie� d�u�ej ni� jego w�a�ciel, dlatego mo�na przekaza� referencj� do w�a�ciciela*/
		Component(Entity& owner);
		~Component();

		//TODO w�a�ciwie klasy init() oraz release s� niepotrzebne, mo�na to wszystko za�atwi� w kontruktorze
		/** Metoda wywo�ywana w momencie do��czenia komponentu do obiektu*/
		virtual void init() = 0;
		/** Metoda zawieraj�ca dzia�ania charakterystyczne dla konkretnych rodzaj�w komponent�w*/
		virtual void update() = 0;
		/** Metoda wywo�ywana w momencie od��czenia komponentu od obiektu.*/
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
