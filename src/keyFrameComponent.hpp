#pragma once

#include <Core/Animation/KeyFramedValue.hpp>
#include <Core/Geometry/TriangleMesh.hpp>
#include <Engine/Scene/Component.hpp>
#include <Engine/Scene/ComponentMessenger.hpp>
#include <Engine/Scene/Entity.hpp>

class KeyFrameComponent : public Ra::Engine::Scene::Component {
public:
  KeyFrameComponent(const std::string &name, Ra::Engine::Scene::Entity *entity);

  void initialize();

  Ra::Core::Transform getTransform();

private:
  Ra::Core::Transform m_transform;
};