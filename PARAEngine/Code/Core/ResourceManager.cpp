#include "ResourceManager.hpp"
#include <assert.h>

using namespace Para;

ResourceManager::ResourceManager()
{
}


ResourceManager::~ResourceManager()
{
}

void ResourceManager::addResource(Resource* resource, ResourceType type)
{
	switch (type)
	{
	case ResourceType::SHADER:
		addShader(resource);
	}
}

void ResourceManager::addShader(Resource* resource)
{
	assert(resource->getType() == ResourceType::SHADER);
	Shader* shaderPointer = dynamic_cast<Shader*>(resource);
	std::shared_ptr<Shader> ptr(shaderPointer);
	m_shaders.put(resource->getGUID(), ptr); //TODO sprawdziæ to w praniu
	m_resources_size += resource->getSize();
}