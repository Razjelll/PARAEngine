#ifndef __PARA_WINDOW_HPP__
#define __PARA_WINDOW_HPP__

#include <string>
namespace Para
{
	class Window
	{
	public:
		Window(int width, int height, const std::string& title, bool fullscreen) :
			m_width(width), m_height(height), m_title(title), m_fullscreen(fullscreen) {}
		virtual void init() = 0;
		virtual void create() = 0;
		virtual void update() = 0;
		virtual void swapBuffers() = 0;
		virtual void clear() = 0;
		virtual void bindAsRenderTarget() const = 0;

		inline bool getWidth() const { return m_width; }
		inline bool getHeight() const { return m_height; }
		virtual void setWindowSize(int width, int height) = 0;
		inline std::string getTitle() const { return m_title; }
		inline bool isFullscreen() const { return m_fullscreen; }
		virtual void setFullscreen(bool fullscreen) = 0;

	protected:
		int m_width;
		int m_height;
		std::string m_title;
		bool m_fullscreen;
	};
}



#endif