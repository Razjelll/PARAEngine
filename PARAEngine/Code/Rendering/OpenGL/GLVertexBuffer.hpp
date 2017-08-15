#ifndef __PARA_GL_VERTEX_BUFFER_HPP__
#define __PARA_GL_VERTEX_BUFFER_HPP__

#pragma once

#include "glew.h"

namespace Para
{
	class Mesh;

	class GLVertexBuffer
	{
	public:
		GLVertexBuffer();
		~GLVertexBuffer();

		void load(Mesh* mesh);
		void bind();
		void unbind();

	private:
		GLuint m_id;
		//TODO zrobiæ pointer na VertexArray
	};

}
#endif //__PARA_GL_VERTEX_BUFFER_HPP__