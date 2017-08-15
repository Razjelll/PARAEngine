#include <iostream>
#include "glew.h"
#include "SDLWindow.hpp"

using namespace Para;

SDLWindow::SDLWindow(int width, int height, const std::string& title, bool fullscreen) :Window(width, height, title, fullscreen)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	


}


SDLWindow::~SDLWindow()
{
	SDL_GL_DeleteContext(m_gl_context);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

void SDLWindow::create()
{
	m_window = SDL_CreateWindow(m_title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_width, m_height, SDL_WINDOW_OPENGL);
	m_gl_context = SDL_GL_CreateContext(m_window);

	SDL_GL_SetSwapInterval(1);

	GLenum res = glewInit();
	if (res != GLEW_OK)
	{
		std::cout << "nie uda³o siê zainicjowaæ GLEW" << std::endl;
	}
}

void SDLWindow::update()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		//TODO tutaj zrobiæ obs³ugê
	}
}

void SDLWindow::swapBuffers()
{
	SDL_GL_SwapWindow(m_window);
}

void SDLWindow::bindAsRenderTarget() const
{
	//ustawiamy teksturê oraz obiekty ramki na domyœlne. Dziêki temu celem renderingu bêdzie okno
	glBindTexture(GL_TEXTURE_2D, 0);
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	
	glViewport(0, 0, m_width, m_height); 
}

void SDLWindow::setWindowSize(int width, int height)
{
	m_width = width;
	m_height = height;
	SDL_SetWindowSize(m_window, width, height);
	glViewport(0, 0, width, height);
}

void SDLWindow::setFullscreen(bool fullscreen)
{
	int mode = 0;
	if (fullscreen)
	{
		mode = SDL_WINDOW_FULLSCREEN;
	}
	SDL_SetWindowFullscreen(m_window, mode);
}