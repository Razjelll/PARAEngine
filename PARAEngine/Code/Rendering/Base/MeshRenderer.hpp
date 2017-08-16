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
		//virtual void load(Mesh* mesh, GpuProgram* program) = 0; //TODO póŸniej bêdzie trzeba zobaczyæ, czy w ka¿dym silniku renderingu bêdzie program
		virtual void load(Mesh* mesh) = 0; 
	};
}


#endif //__PARA_MESH_RENDERER_HPP__
