#ifndef __PARA_RESOURCE_MAP_HPP__
#define __PARA_RESOURCE_MAP_HPP__
#pragma once

#include <map>
#include "../Core/Resource.hpp"
#include <memory>
#include <algorithm>

namespace Para
{
	template <typename Res>
	class ResourceMap
	{
		typedef std::shared_ptr<Res> ResourcePtr;
	public:
		ResourceMap() {};
		~ResourceMap()
		{
			removeAll();
		};
		
		ResourcePtr get(GUID guid)
		{
			return m_resource_map.find(guid)->second;
		}

		void put(GUID guid, ResourcePtr resource)
		{
			m_resource_map[guid] = resource;
		}

		bool exist(GUID guid)
		{
			return m_resource_map.find(guid) != m_resource_map.end();
		}

		void remove(GUID guid)
		{
			delete m_resource_map.find(guid)->second;
			m_resource_map.erase(guid);
		}

		void removeAll()
		{
			/*auto begin = m_resource_map.begin();
			auto end = m_resource_map.end();

			std::for_each(begin, end, [](ResourcePtr resource)
			{
				delete resource;
			});*/
			m_resource_map.clear(); //TODO to chyba wystarczy
			/*for (std::map<GUID, ResourcePtr>::iterator it = m_resource.begin(); it != m_resource.end(); it++)
			{
				delete it->second;
			}
			m_resource_map.clear();*/
		}

	private:
		std::map<GUID, ResourcePtr> m_resource_map;
	};
}


#endif //__PARA_RESOURCE_MAP_HPP__
