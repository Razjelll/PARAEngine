#ifndef __PARA_OBJ_LOADER_HPP__
#define __PARA_OBJ_LOADER_HPP__

#pragma once
#include "../Core/Mesh.hpp"
#include <string>

namespace Para
{
	struct Face
	{
		unsigned int a, b, c,
			d, e, f,
			g, h, i;
	};

	class ObjLoader
	{
	public:
		ObjLoader();
		~ObjLoader();
		Mesh* load(const std::string& filename);
	};
}

#endif // !__PARA_OBJ_LOADER_HPP__