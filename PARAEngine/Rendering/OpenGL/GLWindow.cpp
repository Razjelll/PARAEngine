#include "GLWindow.hpp"
#include "glew.h"
#include "freeglut.h"
#include "glew.h"
#include "../../Libraries/glm/glm.hpp"


void render()
{
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
}

void reshape(int width, int height)
{
	glViewport(0, 0, width, height);
	
}

void close()
{

}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	default:
		break;
	}
}

GLWindow::GLWindow(int width, int height, const std::string& title, bool fullscreen, int argcp, char** argv) :
	Window(width, height, title, fullscreen)
{
	glutInit(&argcp, argv); //TODO dowiedzieæ siê czy to bêdzie dobrze dzia³a³o
	if (fullscreen)
		glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA | GLUT_FULL_SCREEN);
	else
		glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitContextVersion(3, 3);
	glutInitContextFlags(GLUT_CORE_PROFILE | GLUT_DEBUG);
	glutInitWindowSize(width, height);
	
}

GLWindow::~GLWindow()
{
	//TODO pousuwaæ wszystko co bêdzie potrzebne
}

void GLWindow::init()
{
	
}

void GLWindow::create()
{
	//TODO odkomentowaæ. 
	glutCreateWindow(m_title.c_str());
	glewExperimental = GL_TRUE;
	GLenum err = glewInit();
	err = glGetError();

	glutDisplayFunc(render); //TODO tê funkcjê dajemy tymczasowo
	glutReshapeFunc(reshape);
	glutCloseFunc(close);
	glutKeyboardFunc(keyboard);
	//glutMainLoop();
}

void GLWindow::update()
{
	glutMainLoopEvent();
}

void GLWindow::swapBuffers()
{
	glutSwapBuffers();
}

void GLWindow::bindAsRenderTarget() const
{
	glBindTexture(GL_TEXTURE_2D, 0);
	glBindFramebuffer(GL_FRAMEBUFFER, 0);

	glViewport(0, 0, m_width, m_height);
}

void GLWindow::setWindowSize(int width, int height)
{
	m_width = width;
	m_height = height;
	//TODO dorobiæ resztê metody
}

void GLWindow::setFullscreen(bool fullscreen)
{
	m_fullscreen = fullscreen;
}

