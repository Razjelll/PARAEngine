#ifndef __PARA_CAMERA_COMPONENT_HPP__
#define __PARA_CAMERA_COMPONENT_HPP__

#pragma once

#include "Component.hpp"

namespace Para
{
	enum class Projection
	{
		PERSPECTIVE,
		ORTHOGRAPHIC
	};

	struct Viewport
	{
		float min_x;
		float max_x;
		float min_y;
		float max_y;
	};

	class CameraComponent : public Component
	{
	public:
		CameraComponent(Entity& onwer);
		~CameraComponent();

		void init() override;
		void update() override;
		void release() override;

		inline const float getFov() const { return m_fov; }
		inline const float getNear() const { return m_near; }
		inline const float getFar() const { return m_far; }
		inline const float getAspectRatio() const { return m_aspect_ratio; }
		inline const Projection getProjection() const { return m_projection; }
		inline const Viewport getViewport() const { return m_viewport; }

		inline void setFov(float fov) { m_fov = fov; }
		inline void setNear(float near) { m_near = near; }
		inline void setFar(float far) { m_far = far; }
		inline void setAspectRatio(float aspectRatio) { m_aspect_ratio = aspectRatio; }
		inline void setProjection(Projection projection) { m_projection = projection; }
		inline void setViewport(float minX, float maxX, float minY, float maxY)
		{
			m_viewport.max_x = maxX;
			m_viewport.min_x = minX;
			m_viewport.max_y = maxY;
			m_viewport.min_y = minY;
		}

	private:
		float m_fov;
		float m_near;
		float m_far;
		float m_aspect_ratio;

		Projection m_projection;
		Viewport m_viewport;

		//TODO referencja do RenderCamera
	};
}



#endif //__PARA_CAMERA_COMPONENT_HPP__

