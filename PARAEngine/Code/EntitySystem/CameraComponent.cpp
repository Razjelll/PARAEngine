#include "CameraComponent.hpp"

using namespace Para;

CameraComponent::CameraComponent(Entity& entity) : Component(entity)
{
	m_name = "Camera";
	m_type = ComponentType::CAMERA_COMPONENT;
}


CameraComponent::~CameraComponent()
{
}

void CameraComponent::init()
{
	//TODO zrobi� dodawanie RenderCamera do systemu renderinu
}

void CameraComponent::update()
{
	//TODO tutaj nie wiem co tak w�a�ciwie zrobi�
}

void CameraComponent::release()
{
	//TODO tutaj usun�� kamer� z systemu renderingu
}
