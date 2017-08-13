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
	//TODO zrobiæ funkcjê zamykaj¹c¹ okno
	delete m_window; //to raczej nie powinno byæ w tym miejscu
	m_is_running = false;
}

