#ifndef __PARA_RESOURCE_MANAGER_HPP__
#define __PARA_RESOURCE_MANAGER_HPP__

#pragma once

#include "ResourceMap.hpp"
#include "../Rendering/Base/GpuProgram.hpp"
 
namespace Para
{
	class ResourceManager
	{
	public:
		static ResourceManager* get()
		{
			if (m_instance == nullptr)
			{
				m_instance = new ResourceManager();
			}
			return m_instance;
		}
		void loadResource(const std::string& name, ResourceType type, const std::string& filename);
		void addResource(Resource* resource, ResourceType type);
		void clearAll(ResourceType type) {}
		void remove(GUID guid, ResourceType type);
		void release();
		Shader* getShader(GUID guid);
		Shader* getShader(const std::string& name);
	private:
		static ResourceManager* m_instance;
		ResourceManager();
		~ResourceManager();

		ResourceMap<Shader> m_shaders;

		unsigned int m_resources_size;

	private:
		void addShader(Resource* resoruce);
	};
}


#endif //__PARA_RESOURCE_MANAGER_HPP__