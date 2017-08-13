#ifndef __PARA_RENDERING_SYSTEM_HPP__
#define __PARA_RENDERING_SYSTEM_HPP__
#pragma once

#include "Rendering\Base\Window.hpp"

class RenderingSystem
{
public:
	RenderingSystem* get() 
	{
		if (m_instance == nullptr)
		{
			m_instance = new RenderingSystem();
		}
		return m_instance;
	}
private:
	RenderingSystem();
	~RenderingSystem();

	RenderingSystem* m_instance;

private:
	
};

#endif
