#ifndef __PARA_GL_WINDOW_HPP__
#define __PARA_GL_WINDOW_HPP__

#include "../Base/Window.hpp"

class GLWindow : public Window
{
public:
	GLWindow(int width, int height, const std::string& title, bool fullscreen, int argcp, char** argv);
	~GLWindow();
	void init();
	void create();
	void update();
	void swapBuffers();
	void bindAsRenderTarget() const;

	void setWindowSize(int width, int height);
	void setFullscreen(bool fullscreen);
private:
	
};

#endif 