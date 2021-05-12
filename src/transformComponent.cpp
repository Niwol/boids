#include "transformComponent.hpp"

TransformComponent::TransformComponent(const std::string &name,
                                       Ra::Engine::Scene::Entity *entity)
    : Component(name, entity), m_position(0.f, 0.5f, 0.f),
      m_direction(0.f, 1.f, 0.f), m_preDirection(0.f, 0.f, 0.f) {}

void TransformComponent::initialize() {}

Ra::Core::Vector3 &TransformComponent::getPosition() { return m_position; }
Ra::Core::Vector3 &TransformComponent::getDirection() { return m_direction; }
Ra::Core::Vector3 &TransformComponent::getPreDirection() {
  return m_preDirection;
}
