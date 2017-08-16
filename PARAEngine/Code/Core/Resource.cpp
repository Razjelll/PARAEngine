#include "Resource.hpp"
#include "../Utils/HashUtils.hpp"

using namespace Para;

Resource::Resource(const std::string& name, ResourceListener* listener) :m_name(name), m_listener(listener)
{
	m_guid = HashUtils::hash(name);
}

Resource::~Resource()
{
}

bool Resource::load(const std::string& filename, bool background)
{
	//TODO narazie bardzo prosta metoda
	if (background)
	{
		//TODO dowiedzie� si� jak to powinno by� dobrze zrobione
	}
	else
	{
		bool success = loadResource(filename);
		if (success && m_listener != nullptr)
		{
			m_listener->loadingComplete();
		}
		return success;
	}
	//TODO dorobi� tutaj jeszcze pobieranie nazwy origin, oraz pobieranie rozmiaru
}

bool Resource::unload(bool background)
{
	if (background)
	{
		//TODO doko�czy� to
	} 
	else
	{
		bool success = unloadResource();
		if (success && m_listener != nullptr)
		{
			m_listener->unloadingComplete();
		}
		return success;
	}
}
