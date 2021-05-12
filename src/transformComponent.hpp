#pragma once

#include <Core/Animation/KeyFramedValue.hpp>
#include <Core/Geometry/TriangleMesh.hpp>
#include <Eigen/Geometry>
#include <Engine/Scene/Component.hpp>
#include <Engine/Scene/ComponentMessenger.hpp>
#include <Engine/Scene/Entity.hpp>

struct PhysicInfo {
  Ra::Core::Vector3 position;
};

class TransformComponent : public Ra::Engine::Scene::Component {
public:
  TransformComponent(const std::string &name,
                     Ra::Engine::Scene::Entity *entity);

  void initialize();

  Ra::Core::Vector3 &getPosition();
  Ra::Core::Vector3 &getDirection();
  Ra::Core::Vector3 &getPreDirection();

private:
  Ra::Core::Vector3 m_position;
  Ra::Core::Vector3 m_direction;
  Ra::Core::Vector3 m_preDirection;
};