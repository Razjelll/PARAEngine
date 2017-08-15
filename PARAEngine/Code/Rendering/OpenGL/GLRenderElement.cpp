#include "GLRenderElement.hpp"
#include "../../Libraries/glm/gtc/matrix_transform.hpp"
#include "../../Libraries/glm/gtc/type_ptr.hpp"
using namespace Para;

const std::string POSITION_ATTRIBUTE = "inPosition";
const std::string NORMALS_ATTRIBUTE = "inNormal";
const std::string UVS_ATTTRIBUTE = "inUV";

#define GL_CHECK_ERRORS assert(glGetError()== GL_NO_ERROR);

GLRenderElement::GLRenderElement()
{
}


GLRenderElement::~GLRenderElement()
{
	glDeleteBuffers(BUFFERS_SIZE, m_buffers);
	glDeleteVertexArrays(1, &m_vao_id);
}

void GLRenderElement::draw()
{
	glBindVertexArray(m_vao_id);
	m_program->bind();
	//TODO usun¹æ to póŸniej
	glm::mat4 P = glm::perspective(45.f, 800.f / 600.f, 0.1f, 1000.f);
	glm::mat4 T = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -5.f));
	glm::mat4 Rx = glm::rotate(T, 5.f, glm::vec3(1.0f, 0.0f, 0.0f));
	glm::mat4 MV = glm::rotate(Rx, 0.f, glm::vec3(0.0f, 1.0f, 0.0f));
	glm::mat4 MVP = P*MV;

	glPolygonMode( GL_FRONT_AND_BACK, GL_LINE);
	glUniformMatrix4fv(m_program->getUniform("MVP"), 1, GL_FALSE, glm::value_ptr(MVP));
	GL_CHECK_ERRORS;
	glDrawArrays(GL_TRIANGLES, 0, m_total_indices);

	m_program->unbind();
	glBindVertexArray(0);
	
}

void GLRenderElement::load(Mesh* mesh, GLGpuProgram* program)
{
	m_program = program;
	glGenVertexArrays(1, &m_vao_id);
	glBindVertexArray(m_vao_id);
	GL_CHECK_ERRORS;
	//³adowanie bufora wierzcho³ków
	glGenBuffers(1, &m_buffers[VERTEX_BUFFER]);
	glBindBuffer(GL_ARRAY_BUFFER, m_buffers[VERTEX_BUFFER]);
	glBufferData(GL_ARRAY_BUFFER, mesh->getVertices().size() * sizeof(Vertex), mesh->getVertices().data(), GL_STATIC_DRAW);
	GL_CHECK_ERRORS;
	//TODO zrobiæ atrybuty
	int vertexSize = sizeof(Vertex);
	glVertexAttribPointer(m_program->getAttribute(POSITION_ATTRIBUTE), 3, GL_FLOAT, GL_FALSE, vertexSize, 0);
	glEnableVertexAttribArray(m_program->getAttribute(POSITION_ATTRIBUTE));
	GL_CHECK_ERRORS;
	if (mesh->hasNormals())
	{
		glVertexAttribPointer(m_program->getAttribute(NORMALS_ATTRIBUTE), 3, GL_FLOAT, GL_FALSE, vertexSize, (const GLvoid*)(offsetof(Vertex, normal)));
		glEnableVertexAttribArray(m_program->getAttribute(NORMALS_ATTRIBUTE));
		GL_CHECK_ERRORS;
	}
	if (mesh->hasUV())
	{
		glVertexAttribPointer(m_program->getAttribute(UVS_ATTTRIBUTE), 2, GL_FLOAT, GL_FALSE, vertexSize, (const GLvoid*)(offsetof(Vertex, uv)));
		glEnableVertexAttribArray(m_program->getAttribute(UVS_ATTTRIBUTE));
		GL_CHECK_ERRORS;
	}
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	GL_CHECK_ERRORS;
	m_total_indices = mesh->getVertices().size();//TDOO tymczasowo pobieramy liczbê wierzcho³ków, poniewa¿ nie korzystamy z indeksów
}