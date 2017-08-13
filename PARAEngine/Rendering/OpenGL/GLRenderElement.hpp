#ifndef __PARA_GL_RENDER_ELEMENT_HPP__
#define __PARA_GL_RENDER_ELEMENT_HPP__
#pragma once

#include "../OpenGL/OpenGL/include/glew.h"
#include "../OpenGL/GLGpuProgram.hpp"
#include "../../Core/Mesh.hpp"

namespace Para
{
	enum Buffers
	{
		VERTEX_BUFFER,
		INDEX_BUFFER,
		BUFFERS_SIZE
	};

	enum Attributes
	{
		POSITION,
		NORMALS,
		UVS
	};

	class GLRenderElement
	{
	public:
		GLRenderElement();
		~GLRenderElement();
		void draw();
		void load(Mesh* mesh, GLGpuProgram* program);
	private:
		GLuint m_vao_id;
		GLuint m_buffers[BUFFERS_SIZE];
		GLGpuProgram* m_program;

		int m_total_indices;
	};

}


#endif //__PARA_GL_RENDER_ELEMENT_HPP__