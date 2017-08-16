#include "ResourceManager.hpp"
#include <assert.h>

using namespace Para;

ResourceManager* ResourceManager::m_instance = nullptr;

ResourceManager::ResourceManager()
{
}


ResourceManager::~ResourceManager()
{
	
}

void ResourceManager::loadResource(const std::string&name, ResourceType type, const std::string& filename)
{
	//TODO dokoñczyæ metodê
	std::logic_error("Function not implemented");
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

void ResourceManager::remove(GUID guid, ResourceType type)
{
	//TODO uzupe³niæ o dodatkowe rodzaje zasobów
	switch (type)
	{
	case ResourceType::SHADER:
		m_shaders.remove(guid);
	}
}

void ResourceManager::release()
{
	m_shaders.clear();
}

Shader* ResourceManager::getShader(GUID guid)
{
	return m_shaders.get(guid).get(); //TODO przeanalizowaæ, czy zwracaæ shared_ptr czy normalny wskaŸnik
}

Shader* ResourceManager::getShader(const std::string& name)
{
	std::shared_ptr<Shader> shaderPtr = m_shaders.get(name);
	if (shaderPtr)
	{
		return shaderPtr.get();
	}
	return nullptr;
}
