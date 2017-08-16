#ifndef __PARA_ENTITY_HPP__
#define __PARA_ENTITY_HPP__

#pragma once

#include "../Core/Transform.hpp"

#include <vector>
#include <memory>

typedef unsigned int EntityID;

namespace Para
{
	class Component;

	struct Components
	{
		std::vector<Component*> components;
	};
	/** Klasa reprezentuj�ca obiekt gry. Zawiera informacje 
	o transformacjach obiektu, o obiektach przy��czonych do tego obiektu(dzieci),
	oraz o komponentach, kt�re s� przypisane do obiektu
	*/
	class Entity
	{
	public:
		Entity(EntityID id);
		Entity(EntityID id ,const std::string& name) ;
		~Entity();

		void update(); //TODO chyba to powinnno by�
		/** Do��czanie obiektu jako obiekt podrz�dny (dziecko). W�a�ciwo�ci transformacji dziecka s� dziedziczone po rodzicu*/
		void attachChild(Entity* child);
		Entity* getParent() { return m_parent; }
		void setParent(Entity* parent);
		/** Od��czanie dziecka od obiektu. Dziecko nie zostaje usuni�te
		 Po od��czeniu dziecko zmienia swoj� transformacj� na kombinacje transformacji
		 rodzica przemno�onej przez w�asn�, dzi�ki czemu otrzyma transformacje w uk�adzie �wiata*/
		void detachChild(Entity* child);
		void detachChild(EntityID id);
		void detachChild(const std::string& name);
		/** Od��czenie wszystkich dzieci*/
		void detachAllChildren();
		/** Wyszukuje i zwraca dziecko o podanym numerze ID*/
		Entity* getChild(EntityID id);
		/** Od��czanie dziecka od obiektu z jednoczesnym usuni�ciem dziecka*/
		void removeChild(EntityID id);
		std::vector<Entity*>& getChildren() { return m_children; }
		int getChildrenCount() { return m_children.size(); }
		//std::vector<std::unique_ptr<Entity>> getChildren() { return m_children; }

		void addComponent(Component* component);
		void removeComponent(Component* component);
		
		inline const EntityID getID() const { return m_id; }
		inline const Transform& getTransform() { return m_transform; }
		inline const std::string& getName() const { return m_name; }
		inline const std::string& getTag() const { return m_tag; }
		inline bool isEnable() { return m_enable; }
		inline void setName(const std::string& name) { m_name = name; }
		inline void setTag(const std::string& tag) { m_tag = tag; }
		inline void enable(bool enable) { m_enable = enable; }
	private:
		/// numer identyfikacyjny obiektu. 
		EntityID m_id;
		/// nazwa obiektu
		std::string m_name;
		/// warto�� s�u��ca do grupowania obiekt�w
		std::string m_tag;
		/// okre�la, czy obiekt jest aktywny
		bool m_enable;
		/// po�o�enie, rotacja oraz skala obiektu
		Transform m_transform;
		/// rodzic obiektu
		Entity* m_parent;
		//TODO cholera, teraz nei wiem czy obliczanie transformacji b�dzie dobrze zrobione
		/// dzieci obiektu
		std::vector<Entity*> m_children;
		/*std::weak_ptr<Entity> m_parent;
		std::vector<std::unique_ptr<Entity>> m_children;*/
		/// Lista komponent�w przypisanych do obiektu
		Components m_components;
	};
}

#endif //__PARA_ENTITY_HPP__