#include "RenderScene.hpp"
#include <algorithm>
#include <assert.h>
#include "RenderElement.hpp"
using namespace Para;

RenderScene::RenderScene()
{
}


RenderScene::~RenderScene()
{
	clear();
}

void RenderScene::render()
{
	//TODO wyrenderowaæ wszystkie elementy
	std::for_each(m_elements.begin(), m_elements.end(), [](RenderElement* element)
	{
		element->draw();
	});
}

void RenderScene::addElement(RenderElement* element)
{
	assert(element != nullptr);
	m_elements.push_back(element);
}

void RenderScene::removeElement(ElementID id)
{
	std::vector<RenderElement*>::iterator it = std::find_if(m_elements.begin(), m_elements.end(), [id](RenderElement* element)
	{
		return element->getID() == id;
	});
	if (it != m_elements.end())
	{
		delete (*it);
		m_elements.erase(it);
	}
}

void RenderScene::clear()
{
	std::for_each(m_elements.begin(), m_elements.end(), [](RenderElement* element)
	{
		delete element;
	});
	m_elements.clear();
	//TODO dorobiæ usuwanie pozosta³ych elementów na scenie
}