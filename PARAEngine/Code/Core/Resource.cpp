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
		//TODO dowiedzie� si� jak to powinno by� dobrze zrobione
	}
	else
	{
		loadResource(filename);
		if (m_listener != nullptr)
		{
			m_listener->loadingComplete();
		}
	}
	//TODO dorobi� tutaj jeszcze pobieranie nazwy origin, oraz pobieranie rozmiaru
}

void Resource::unload(bool background)
{
	if (background)
	{
		//TODO doko�czy� to
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
