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

//TODO zobaczyæ, czy przekazanie mesha to dobry pomys³
void GLVertexBuffer::load(Mesh* mesh)
{
	//TODO zastanowiæ siê, czy id generowaæ tutaj czy w konstruktorze
	glGenVertexArrays(1, &m_id); // TOD Otutaj powinno byæ wi¹zanie do vao (Vertex array)
	bind();
	glBindBuffer(GL_ARRAY_BUFFER, m_id);
	//³adowanie danych do bufora
	glBufferData(GL_ARRAY_BUFFER, mesh->getVertices().size() * sizeof(Vec3), mesh->getVertices().data(), GL_STATIC_DRAW);
	//TODO zastanowiæ siê, czy glEnableVertexAttrib wstawiæ tutaj, czy przenieœæ do jakiejœ innej klasy
	
	unbind();
}



void GLVertexBuffer::bind()
{
	assert(m_id > 0); //TODO pamiêtaæ, ¿eby zdefiniowaæ NDEBUG in Release mode
	glBindVertexArray(m_id);
}

void GLVertexBuffer::unbind()
{
	assert(m_id > 0);
	glBindVertexArray(NULL);
}