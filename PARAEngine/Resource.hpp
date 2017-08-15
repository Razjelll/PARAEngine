#ifndef __PARA_RESOURCE_HPP__
#define __PARA_RESOURCE_HPP__

#pragma once
#include <string>

namespace Para
{
	typedef long GUID;

	enum class ResourceType
	{
		TEXTURE,
		SHADER,
		MESH,
		//TODO dopisa� pozosta�e typy
	};

	enum class ResourceState
	{
		UNLOADED,
		PREPARING,
		PREPARED,
		LOADING,
		LOADED,
		UNLOADING
	};

	class ResourceListener
	{
	public:
		virtual void prepareComplete() = 0;
		virtual void loadingComplete() = 0;
		virtual void unloadingComplete() = 0;
	};

	class Resource
	{
	public:
		Resource();
		~Resource();
		
	private:
		/// Unikalny liczbowy indetyfikator zasobu. Identyfiaktor powstaje w wyniku hashowania po�o�enia pliku z zasobem.  
		GUID m_guid;
		/// Unikalna nazwa zasobu
		std::string m_name;
		/// Typ zasobu.
		ResourceType m_type;
		/// Rozmiar zasobu w bajtach
		size_t m_size;
		/// Orginalna nazwa pliku. Warto�� jest opcjonalna
		std::string m_origin_name;
		/// Stan za�adowania zasobu
		ResourceState m_state;
		/// Obiekt metod zwrotnych, kt�re maj� by� wykonana poza�adowaniu, przygotowaniu lub usuni�ciu zasobu
	};
}


#endif //__PARA_RESOURCE_HPP__