#include "Engine.hpp"



Engine::Engine(Window* window) : m_window(window)
{
	
}


Engine::~Engine()
{

}



void Engine::start()
{
	m_window->create();
	m_is_running = true;
}

void Engine::stop()
{
	//TODO zrobi� funkcj� zamykaj�c� okno
	delete m_window; //to raczej nie powinno by� w tym miejscu
	m_is_running = false;
}

