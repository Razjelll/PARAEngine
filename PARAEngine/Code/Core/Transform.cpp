#include "Transform.hpp"
#include "../../Libraries/glm/gtc/matrix_transform.hpp"
using namespace Para;

Transform::Transform()
{
	m_position = Vec3(0);
	m_rotation = Vec3(0);
	m_scale = Vec3(1);
	m_transform_matrix = Mat4(1);
}


Transform::~Transform()
{
}

void Transform::translate(const Vec3& translation)
{
	m_position += translation;
	m_transform_change = true;
}

void Transform::translate(Axis axis, const float translation)
{
	switch (axis)
	{
	case Axis::X:
		m_position += Vec3(translation, 0, 0); break;
	case Axis::Y:
		m_position += Vec3(0, translation, 0); break;
	case Axis::Z:
		m_position += Vec3(0, 0, translation); break;
	}
	m_transform_change = true;
}

void Transform::rotate(const Vec3& rotation)
{
	//TODO zobaczyæ, czy nie bêdzie trzeba zamieniaæ tego na radiany
	//TODO, zobaczyc jak to jest zrobione w Unity
	m_rotation += rotation;
	m_transform_change = true;
}

void Transform::rotate(Axis axis, const float angle)
{
	switch (axis)
	{
	case Axis::X:
		m_rotation += Vec3(angle, 0, 0); break;
	case Axis::Y:
		m_rotation += Vec3(0, angle, 0); break;
	case Axis::Z:
		m_rotation += Vec3(0, 0, angle); break;
	}
	m_transform_change = true;
}

void Transform::scale(const Vec3& scale)
{
	m_scale += scale;
	m_transform_change = true;
}

void Transform::scale(const float scale)
{
	m_scale += Vec3(scale, scale, scale);
	m_transform_change = true;
}

void Transform::scale(Axis axis, const float scale)
{
	switch (axis)
	{
	case Axis::X:
		m_scale += Vec3(scale, 0, 0); break;
	case Axis::Y:
		m_scale += Vec3(0, scale, 0); break;
	case Axis::Z:
		m_scale += Vec3(0, 0, scale); break;
	}
	m_transform_change = true;
}

Mat4& Transform::getTransformMatrix()
{
	if (m_transform_change)
	{
		updateTransform();
	}
	return m_transform_matrix;
}

void Transform::updateTransform()
{
	//TODO tymczasowo do obliczeñ wykorzystano glm
	//TODO mo¿na pomyœleæ nad tym, aby nie by³o trzeba przeprowadzaæ wszystkich dzia³añ
	m_transform_matrix = Mat4(1); 
	m_transform_matrix = glm::scale(m_transform_matrix, m_scale);
	if (m_rotation.x != 0)
	{
		m_transform_matrix = glm::rotate(m_transform_matrix, m_rotation.x, glm::vec3(1, 0, 0));
	}
	if (m_rotation.y != 0)
	{
		m_transform_matrix = glm::rotate(m_transform_matrix, m_rotation.y, glm::vec3(0, 1, 0));
	}
	if (m_rotation.z != 0)
	{
		m_transform_matrix = glm::rotate(m_transform_matrix, m_rotation.z, glm::vec3(0, 0, 1));
	}
	m_transform_matrix = glm::translate(m_transform_matrix, m_position);
	m_transform_change = false;
}