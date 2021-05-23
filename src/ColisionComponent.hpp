#pragma once

#include <Core/Animation/KeyFramedValue.hpp>
#include <Core/Geometry/TriangleMesh.hpp>
#include <Eigen/Geometry>
#include <Engine/Scene/Component.hpp>
#include <Engine/Scene/ComponentMessenger.hpp>
#include <Engine/Scene/Entity.hpp>

class ColisionComponent : public Ra::Engine::Scene::Component {
public:
    ColisionComponent(const std::string &name, Ra::Engine::Scene::Entity *entity, Ra::Core::Vector3f position,float radius);

    void initialize();

    Ra::Core::Vector3f &getPosition();

    float radius;

private:
    Ra::Core::Vector3f position;
};