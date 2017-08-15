//#if defined(__PARA_SDL_WINDOW_HPP__)
	
	//#pragma comment(lib, "SDL2main.lib");
//#endif

//#include "Core\Engine.hpp"
//#include "Utils\ObjLoader.hpp"

//#include "Rendering\OpenGL\SDLWindow.hpp"

#include "Rendering\OpenGL\GLWindow.hpp"
#include "Core\Engine.hpp"
#include "Utils\ObjLoader.hpp"
#include "Rendering\OpenGL\GLRenderElement.hpp"
#include "Rendering\OpenGL\OpenGL\include\freeglut.h"

#define DEBUG
#define GL_CHECK_ERRORS assert(glGetError()== GL_NO_ERROR);

using namespace Para;

int main(int argcp, char* argv[])
{
	//Window* window = new GLWindow(800, 600, "ParaEngine", false, argcp, argv);
	/*Window* window = new SDLWindow(800, 600, "PARAEngine", false);
	Engine engine(window);
	engine.start();*/

	Para::GLWindow* window = new Para::GLWindow(800, 600, "ParaEngine", false, argcp, argv);
	window->init();
	Para::Engine engine;
	engine.init(window);
	engine.start();
	Para::ObjLoader loader;
	Para::Mesh* mesh = loader.load("D:/kostka.obj");
	
	
	GLGpuProgram* program = new GLGpuProgram();
	GL_CHECK_ERRORS;
	//program->addShader(new GLShader(ShaderType::VERTEX_SHADER, "../PARAEngine/Shaders/shader_vert.glsl"));
	GLShader* shader = new GLShader(ShaderType::VERTEX_SHADER, "shader_vert");
	shader->load("../PARAEngine/Shaders/shader_vert.glsl");
	program->addShader(shader);
	GLShader* shader2 = new GLShader(ShaderType::FRAGMENT_SHADER, "shader_frag");
	shader2->load("../PARAEngine/Shaders/shader_frag.glsl");
	program->addShader(shader2);
	//program->addShader(new GLShader(ShaderType::FRAGMENT_SHADER, "../PARAEngine/Shaders/shader_frag.glsl"));
	program->create();
	GL_CHECK_ERRORS;
	program->bind();
	program->addAttribute("inPosition");
	program->addAttribute("inNormals");
	program->addAttribute("inUV");
	program->addUniform("MVP", UniformType::MAT4);
	program->unbind();
	GL_CHECK_ERRORS;

	Para::GLRenderElement renderElement;
	renderElement.load(mesh, program);

	while (true)
	{
		GL_CHECK_ERRORS;
		window->update();
		renderElement.draw();
		window->swapBuffers();
	}
	
	system("pause");
	delete mesh;
	delete program;

	delete window;

	return 0;
}

