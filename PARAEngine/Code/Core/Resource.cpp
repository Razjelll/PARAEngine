#include "Resource.hpp"

using namespace Para;

Resource::~Resource()
{
}

void Resource::load(const std::string& filename, bool background)
{
	//TODO narazie bardzo prosta metoda
	if (background)
	{
		//TODO dowiedzieæ siê jak to powinno byæ dobrze zrobione
	}
	else
	{
		loadResource(filename);
		if (m_listener != nullptr)
		{
			m_listener->loadingComplete();
		}
	}
	//TODO dorobiæ tutaj jeszcze pobieranie nazwy origin, oraz pobieranie rozmiaru
}

void Resource::unload(bool background)
{
	if (background)
	{
		//TODO dokoñczyæ to
	} 
	else
	{
		unloadResource();
		if (m_listener != nullptr)
		{
			m_listener->unloadingComplete();
		}
	}
}
