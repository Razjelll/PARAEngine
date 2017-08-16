#ifndef __PARA_RESOURCE_HPP__
#define __PARA_RESOURCE_HPP__

#pragma once
#include <string>

namespace Para
{
	typedef unsigned int GUID;

	enum class ResourceType
	{
		TEXTURE,
		SHADER,
		MESH,
		//TODO dopisaæ pozosta³e typy
	};

	enum class ResourceState
	{
		UNLOADED,
		LOADING,
		LOADED,
		UNLOADING
	};

	/** Metoda zwrotna*/
	class ResourceListener
	{
	public:
		virtual void loadingComplete() = 0;
		virtual void unloadingComplete() = 0;
	};

	class Resource
	{
	public:
		Resource(const std::string& name = NULL, ResourceListener* listener = nullptr);
		virtual ~Resource();

		bool load(const std::string& filename, bool background = false);
		bool unload(bool background = false);
		//TODO mo¿e bêdzie trzeba wstawiæ jeszcze metodê 

		GUID getGUID() { return m_guid; }
		std::string getName() { return m_name; }
		ResourceType getType() { return m_type; }
		size_t getSize() { return m_size; }
		std::string getOriginName() { return m_origin_name; }

		void setListener(ResourceListener* listener) { m_listener = listener; }
	protected:
		/// Unikalny liczbowy indetyfikator zasobu. Identyfiaktor powstaje w wyniku hashowania nazwy zasobu. Dziêki temu w szybszy sposób
		/// Dziêki temu w szybszy sposób bêdzie mo¿na wyszukiwaæ po nazwie.
		GUID m_guid;
		/// Unikalna nazwa zasobu
		std::string m_name;
		/// Typ zasobu.
		ResourceType m_type;
		/// Rozmiar zasobu w bajtach
		size_t m_size;
		/// Orginalna nazwa pliku. Wartoœæ jest opcjonalna
		std::string m_origin_name;
		/// Obiekt metod zwrotnych, wywo³ywanych podczas ³adowania i usuwania zasobu
		ResourceListener* m_listener;

	protected:

		virtual bool loadResource(const std::string& filename) = 0;
		virtual bool unloadResource() = 0;
	};
}


#endif //__PARA_RESOURCE_HPP__