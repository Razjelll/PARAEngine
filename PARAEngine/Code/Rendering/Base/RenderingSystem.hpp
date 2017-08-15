#ifndef __PARA_RENDERING_SYSTEM_HPP__
#define __PARA_RENDERING_SYSTEM_HPP__
#pragma once

#include "Window.hpp"

namespace Para
{
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

		void init(Window* window);
	private:
		RenderingSystem();
		~RenderingSystem();

		RenderingSystem* m_instance;
		Window* m_window;

	};
}

#endif //__PARA_RENDERING_SYSTEM_HPP__
