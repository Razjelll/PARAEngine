#ifndef __PARA_MESH_RENDERER_HPP__
#define __PARA_MESH_RENDERER_HPP__

#pragma once

#include "RenderElement.hpp"
#include <string>

namespace Para
{
	class Mesh;

	class MeshRenderer : public RenderElement
	{
	public:
		MeshRenderer(Entity& entity) : RenderElement(entity){}
		~MeshRenderer() {}

		virtual void draw() = 0;
		//virtual void load(Mesh* mesh, GpuProgram* program) = 0; //TODO p�niej b�dzie trzeba zobaczy�, czy w ka�dym silniku renderingu b�dzie program
		virtual void load(Mesh* mesh) = 0; 
	};
}


#endif //__PARA_MESH_RENDERER_HPP__
