#include "Mesh.hpp"

using namespace Para;

Mesh::Mesh()
{
}


Mesh::~Mesh()
{
	//TODO zobaczyæ, czy bêdzie trzeba usuwaæ tutaj wierzcho³ki
	m_vertices.clear();
}
