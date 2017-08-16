#ifndef __PARA_GL_RENDER_ELEMENT_HPP__
#define __PARA_GL_RENDER_ELEMENT_HPP__
#pragma once

#include "../OpenGL/OpenGL/include/glew.h"
#include "../OpenGL/GLGpuProgram.hpp"
#include "../../Core/Mesh.hpp" //TODO mo¿na przedstawiæ za pomoc¹ class
#include "../Base/MeshRenderer.hpp"
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

	class GLMeshRenderer : public MeshRenderer
	{
	public:
		GLMeshRenderer(Entity& entity, GLGpuProgram* program);
		~GLMeshRenderer();
		void draw() override;
		//void load(Mesh* mesh) override;
		void load(Mesh* mesh) override;
		
		void setProgram(GLGpuProgram* program) { m_program = program; }
	private:
		GLuint m_vao_id;
		GLuint m_buffers[BUFFERS_SIZE];
		GLGpuProgram* m_program;

		int m_total_indices;
	};

}


#endif //__PARA_GL_RENDER_ELEMENT_HPP__