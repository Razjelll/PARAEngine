#ifndef __PARA_MESH_HPP__
#define __PARA_MESH_HPP__
#pragma once

#include "../Libraries/glm/glm.hpp"
#include <vector>

typedef glm::vec3 Vec3;
typedef glm::vec2 Vec2;

namespace Para
{

	struct Vertex
	{
		Vec3 position;
		Vec3 normal;
		Vec2 uv;
	};

	class Mesh
	{
	public:
		Mesh();
		~Mesh();

		void setVertices(const std::vector<Vertex>& vertices) { m_vertices = vertices; }
		void setName(const std::string& name) { m_name = name; }

		std::vector<Vertex>& getVertices() { return m_vertices; }
		void setTotalTriangles(int totalTriangles) { m_total_triangles = totalTriangles; }
		
		bool hasNormals() { return m_has_normals; }
		bool hasUV() { return m_has_uv; }
		void setHasNormals(bool hasNormals) { m_has_normals = hasNormals; }
		void setHasUV(bool hasUV) { m_has_uv = hasUV; }
	private:
		std::vector<Vertex> m_vertices;
		std::string m_name;

		bool m_has_normals;
		bool m_has_uv;

		int m_total_vertices;
		int m_total_triangles;
	};
}


#endif //__PARA_MESH_HPP__