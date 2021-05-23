#pragma once

#include <iostream>
#include <vector>

#include "ColisionComponent.hpp"
#include "transformComponent.hpp"
#include <Engine/FrameInfo.hpp>
#include <Engine/RadiumEngine.hpp>
#include <Engine/Scene/Component.hpp>
#include <Engine/Scene/ComponentMessenger.hpp>
#include <Engine/Scene/Entity.hpp>
#include <Engine/Scene/GeometryComponent.hpp>
#include <Engine/Scene/System.hpp>

#define MAP_BORDER 20.f

class BoidSystem : public Ra::Engine::Scene::System {
public:
    BoidSystem() = default;
    ~BoidSystem() = default;

    void generateTasks(Ra::Core::TaskQueue* taskQueue,
                       const Ra::Engine::FrameInfo& frameInfo);

    void addToObstacles(ColisionComponent obstacle);

private:
    std::vector<ColisionComponent> obstacles = std::vector<ColisionComponent>();
    Ra::Core::Vector3f verifyCubeBorders(Ra::Core::Vector3f position, float halfSideLength);
    Ra::Core::Vector3f verifyBorders(Ra::Core::Vector3f position,
        float toRightLength, float toLeftLength,
        float toBackLength, float toForwardLength,
        float toUpLength, float toBottomLength);
};