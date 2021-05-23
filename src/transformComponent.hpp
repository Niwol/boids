#pragma once

#include <Core/Animation/KeyFramedValue.hpp>
#include <Core/Geometry/TriangleMesh.hpp>
#include <Eigen/Geometry>
#include <Engine/Scene/Component.hpp>
#include <Engine/Scene/ComponentMessenger.hpp>
#include <Engine/Scene/Entity.hpp>

struct PhysicInfo {
    Ra::Core::Vector3 position;
    Ra::Core::Vector3 rotationAxis;
    Ra::Core::Vector3 direction;

    float speed;
    float rotationSpeed;
};

class TransformComponent : public Ra::Engine::Scene::Component {
public:
    TransformComponent(const std::string &name, Ra::Engine::Scene::Entity *entity);

    void initialize();

    PhysicInfo &getPhysics();

private:
    PhysicInfo m_physics;
};