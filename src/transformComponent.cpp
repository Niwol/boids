#include "transformComponent.hpp"

TransformComponent::TransformComponent(const std::string &name,
                                       Ra::Engine::Scene::Entity *entity)
    : Component(name, entity) {

  m_physics.position = Ra::Core::Vector3(0.f, 0.5f, 0.f);
  m_physics.rotationAxis = Ra::Core::Vector3(0.f, 1.f, 0.f);
  m_physics.prevRotationAxis = Ra::Core::Vector3(0.f, 1.f, 0.f);

  m_physics.rataionSpeed = 1.f;
  m_physics.prevRotationSpeed = 1.f;
}

void TransformComponent::initialize() {}

PhysicInfo &TransformComponent::getPhysics() { return m_physics; };