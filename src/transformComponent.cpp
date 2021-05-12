#include "transformComponent.hpp"

TransformComponent::TransformComponent(const std::string &name,
                                       Ra::Engine::Scene::Entity *entity)
    : Component(name, entity) {

  m_physics.position = Ra::Core::Vector3(0.f, 0.5f, 0.f);
  m_physics.rotationAxis = Ra::Core::Vector3(0.f, 1.f, 0.f);
  m_physics.direction = Ra::Core::Vector3(-1.f, 0.f, 0.f);

  m_physics.speed = 0.05f;
  m_physics.rotationSpeed = 0.f;
}

void TransformComponent::initialize() {}

PhysicInfo &TransformComponent::getPhysics() { return m_physics; };