#ifndef __PARA_ENGINE_HPP__
#define __PARA_ENGINE_HPP__
#pragma once

#include "../Rendering/Base/Window.hpp"

#define PString std::string;
#define Puint unsigned int;
#define Pint int;

typedef PString std::string;


class Engine
{
public:
	//TODO mo�na zrobi� uruchomienie silnika z odpowiednich ustawie�
	Engine(Window* window);
	~Engine();
	//TODO dorobi� funkcj� inicjalizuj�c�
	void start();
	void stop();
private:
	Window* m_window;
	bool m_is_running;
	double m_frame_time; //okresla jak d�ugo�� trwa klatka 
};

#endif //__PARA_ENGINE_HPP__
