#include "GLVertexBuffer.hpp"
#include "../../Core/Mesh.hpp"
#include <assert.h>
using namespace Para;


GLVertexBuffer::GLVertexBuffer()
{
	
}


GLVertexBuffer::~GLVertexBuffer()
{
	glDeleteVertexArrays(1, &m_id);
}

//TODO zobaczy�, czy przekazanie mesha to dobry pomys�
void GLVertexBuffer::load(Mesh* mesh)
{
	//TODO zastanowi� si�, czy id generowa� tutaj czy w konstruktorze
	glGenVertexArrays(1, &m_id); // TOD Otutaj powinno by� wi�zanie do vao (Vertex array)
	bind();
	glBindBuffer(GL_ARRAY_BUFFER, m_id);
	//�adowanie danych do bufora
	glBufferData(GL_ARRAY_BUFFER, mesh->getVertices().size() * sizeof(Vec3), mesh->getVertices().data(), GL_STATIC_DRAW);
	//TODO zastanowi� si�, czy glEnableVertexAttrib wstawi� tutaj, czy przenie�� do jakiej� innej klasy
	
	unbind();
}



void GLVertexBuffer::bind()
{
	assert(m_id > 0); //TODO pami�ta�, �eby zdefiniowa� NDEBUG in Release mode
	glBindVertexArray(m_id);
}

void GLVertexBuffer::unbind()
{
	assert(m_id > 0);
	glBindVertexArray(NULL);
}