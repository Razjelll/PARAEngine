//#if defined(__PARA_SDL_WINDOW_HPP__)
	
	//#pragma comment(lib, "SDL2main.lib");
//#endif

//#include "Core\Engine.hpp"
//#include "Utils\ObjLoader.hpp"

//#include "Rendering\OpenGL\SDLWindow.hpp"

#include "Rendering\OpenGL\GLWindow.hpp"
#include "Core\Engine.hpp"
#include "Utils\ObjLoader.hpp"
#include "Rendering\OpenGL\GLMeshRenderer.hpp"
#include "Rendering\OpenGL\OpenGL\include\freeglut.h"
#include "Core\ResourceManager.hpp"
#include "EntitySystem\Entity.hpp"
#include "Rendering\Base\RenderScene.hpp"
#include ""

#define DEBUG
#define GL_CHECK_ERRORS assert(glGetError()== GL_NO_ERROR);

using namespace Para;

void initResourceManager()
{
	GLShader* shader = new GLShader(ShaderType::VERTEX_SHADER, "vertexShader");
	if (shader->load("../PARAEngine/Shaders/shader_vert.glsl"))
	{
		ResourceManager::get()->addResource(shader, ResourceType::SHADER);
	}
	shader = new GLShader(ShaderType::FRAGMENT_SHADER, "fragmentShader");
	if (shader->load("../PARAEngine/Shaders/shader_frag.glsl"))
	{
		ResourceManager::get()->addResource(shader, ResourceType::SHADER);
	}
}

int main(int argcp, char* argv[])
{
	GLWindow* window = new GLWindow(800, 600, "ParaEngine", false, argcp, argv);
	window->init();
	Engine engine;
	engine.init(window);
	engine.start();
	ObjLoader loader;
	Mesh* mesh = loader.load("D:/kostka.obj");
	
	initResourceManager();

	GLGpuProgram* program = new GLGpuProgram();
	program->addShader(ResourceManager::get()->getShader("vertexShader"));
	program->addShader(ResourceManager::get()->getShader("fragmentShader"));
	program->create();
	program->bind();
	program->addAttribute("inPosition");
	program->addAttribute("inNormals");
	program->addAttribute("inUV");
	program->addUniform("MVP", UniformType::MAT4);
	program->unbind();

	Entity entity(1);
	
	GLMeshRenderer* renderElement = new GLMeshRenderer(entity, program);
	renderElement->load(mesh);
	GLMeshRenderer* renderElement2 = new GLMeshRenderer(entity, program);
	renderElement2->load(mesh);
	//renderElement.load(mesh, program);
	RenderScene scene;
	scene.addElement(renderElement);
	scene.addElement(renderElement2);
	


	while (true)
	{
		GL_CHECK_ERRORS;
		window->update();
		//renderElement.draw();
		scene.render();
		window->swapBuffers();
	}
	
	system("pause");
	scene.clear();
	engine.stop();
	ResourceManager::get()->release();
	delete mesh;
	delete program;

	delete window;
	

	return 0;
}

