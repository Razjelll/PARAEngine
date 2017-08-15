#ifndef  __PARA_SDL_WINDOW_HPP__
#define __PARA_SDL_WINDOW_HPP__

#pragma once

#include "../Base/Window.hpp"
#include "SDL\include\SDL.h"
#undef main

namespace Para
{
	class SDLWindow : public Window
	{
	public:
		SDLWindow(int width, int height, const std::string& title, bool fullscreen);
		~SDLWindow();
		void init() {};
		void create();
		void update();
		void swapBuffers();
		void bindAsRenderTarget() const;
		void setWindowSize(int width, int height);
		void setFullscreen(bool fullscreen);
	private:
		SDL_Window* m_window;
		SDL_GLContext m_gl_context;
	};
}


#endif
