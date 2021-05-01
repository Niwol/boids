#pragma once

#include <iostream>
#include <vector>

#include "keyFrameComponent.hpp"
#include <Engine/RadiumEngine.hpp>
#include <Engine/Scene/ComponentMessenger.hpp>
#include <Engine/Scene/GeometryComponent.hpp>
#include <Engine/Scene/System.hpp>

class BoidSystem : public Ra::Engine::Scene::System {
public:
  BoidSystem() = default;
  ~BoidSystem() = default;

  void generateTasks(Ra::Core::TaskQueue *taskQueue,
                     const Ra::Engine::FrameInfo &frameInfo);

private:
};